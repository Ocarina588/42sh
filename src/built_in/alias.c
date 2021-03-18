/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** alias
*/

#include "my.h"
#include "minishell.h"

char *malloc_alias(int check, char **tab, char *str, int len)
{
    if (check == 0 && tab[3] != NULL)
        str = malloc(sizeof(char) * (len + 3));
    else
        str = malloc(sizeof(char) * (len + 1));
    if (!str)
        exit(84);
    return (str);
}

char **add_alias(char **tmp, char **tab, int check)
{
    int size = len_tab(tmp);
    char **alias = malloc(sizeof(char *) * (size + 2));
    int len = 0;
    char *str = "\0";
    int i = 0;

    len = get_total_size(tab);
    for (; tmp != NULL && tmp[i]; i++)
        alias[i] = my_strdup(tmp[i]);
    alias[i] = malloc_alias(check, tab, alias[i], len);
    for (int x = 1; tab[x]; x++) {
        x != 1 ? str = my_strcatrealloc(str, " ") : 0;
        str = my_strcatrealloc(str, tab[x]);
    }
    alias[i] = my_strcpy(alias[i], tab[1]);
    if (check == 0 && tab[3] != NULL)
        alias = copy_alias_parent(str, i, alias);
    else
        alias = copy_alias(str, i, alias);
    return (alias);
}

int alias_next(options_t *opt, char *tmp, char **tab, int check)
{
    for (int i = 0; opt->alias.alias != NULL && opt->alias.alias[i]; i++)
        if (my_strncmp(tmp, opt->alias.alias[i], my_strlen(tmp)) == 0) {
            change_alias(tab, opt, i, my_strlen(tmp));
            return (0);
        }
    opt->alias.alias = add_alias(opt->alias.alias, tab, check);
    opt->alias.alias = reorder_tab(opt->alias.alias);
    return (0);
}

int check_err_alias(char **new_tab, options_t *opt)
{
    if (len_tab(new_tab) == 1) {
        print_alias(opt->alias.alias);
        free_2darray(new_tab);
        return (0);
    } else if (len_tab(new_tab) == 2) {
        free_2darray(new_tab);
        return (0);
    }
    if (my_strcmp(new_tab[1], "alias") == 0) {
        dprint(2, "alias: Too dangerous to alias that.\n");
        free_2darray(new_tab);
        return (1);
    }
    return (3);
}

int alias(env_t **envi, char **tab, options_t *opt)
{
    char *tmp;
    int check = is_quote(tab);
    char **new_tab = copy_tab(tab);
    int error = 0;

    clean_function(new_tab);
    error = check_err_alias(new_tab, opt);
    if (error != 3)
        return (error);
    tmp = my_strcatrealloc(new_tab[1], "\t");
    alias_next(opt, tmp, new_tab, check);
    free(tmp);
    free_2darray(new_tab);
    return (0);
}