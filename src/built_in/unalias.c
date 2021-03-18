/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** unalias
*/

#include "my.h"
#include "minishell.h"

int supp_alias_next(char *str, char **tmp, options_t *opt, char *var)
{
    int j = 0;

    for (int i = 0; tmp[i]; i++)
        if (my_strncmp(tmp[i], var, my_strlen(str) + 1) != 0) {
            free(opt->alias.alias[j]);
            opt->alias.alias[j] = my_strdup(tmp[i]);
            j++;
        }
    return (j);
}

void supp_alias(options_t *opt, char *str)
{
    int line = len_tab(opt->alias.alias);
    char **tmp = malloc(sizeof(char *) * (line + 1));
    int j = 0;
    char *var = my_strcatrealloc(str, "\t");

    if (!tmp)
        exit(84);
    for (int i = 0; opt->alias.alias[i]; i++)
        tmp[i] = my_strdup(opt->alias.alias[i]);
    tmp[line] = NULL;
    j = supp_alias_next(str, tmp, opt, var);
    if (j != line) {
        free(opt->alias.alias[line - 1]);
        opt->alias.alias[line - 1] = NULL;
    }
    free_2darray(tmp);
    free(var);
}

int unalias(env_t **envi, char **tab, options_t *opt)
{
    char **new_tab = copy_tab(tab);

    clean_function(new_tab);
    if (len_tab(new_tab) == 1) {
        dprint(2, "unalias: Too few arguments.\n");
        return (1);
    }
    if (opt->alias.alias == NULL) {
        free_2darray(new_tab);
        return (0);
    }
    for (int i = 1; new_tab[i]; i++)
        supp_alias(opt, new_tab[i]);
    free_2darray(new_tab);
    return (0);
}