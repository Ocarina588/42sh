/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** change_cmd_alias
*/

#include "my.h"
#include "minishell.h"

char *get_new_next(int check, char *str, int i, int j)
{
    char *new_cmd;

    if (check == 0) {
        new_cmd = malloc(sizeof(char) * (j - i + 1));
        if (!new_cmd)
            exit(84);
        for (int x = 0; str[x + i]; x++)
            new_cmd[x] = str[x + i];
        new_cmd[j - i] = '\0';
    } else {
        new_cmd = malloc(sizeof(char) * (j - i - 1));
        if (!new_cmd)
            exit(84);
        for (int x = 0; str[x + i + 1] != ')'; x++)
            new_cmd[x] = str[x + i + 1];
        new_cmd[j - i - 2] = '\0';
    }
    return (new_cmd);
}

char *get_new_cmd(char *str, int i)
{
    char *new_cmd;
    int j = i;
    int check = 0;

    if (str[i] == '(' && str[my_strlen(str) - 1] == ')')
        check = 1;
    for (; str[j]; j++);
    new_cmd = get_new_next(check, str, i, j);
    return (new_cmd);
}

char **change_cmd_tab(char **tab)
{
    char *long_cmd = "\0";

    for (int i = 0; tab[i]; i++) {
        i != 0 ? long_cmd = my_strcatrealloc(long_cmd, " ") : 0;
        long_cmd = my_strcatrealloc(long_cmd, tab[i]);
    }
    free_2darray(tab);
    tab = my_str_to_word_array(long_cmd, ' ');
    free(long_cmd);
    return (tab);
}

char **change_cmd_alias(char **tab, options_t *opt)
{
    char *tmp;
    char **new_tab = copy_tab(tab);

    clean_function(new_tab);
    tmp = my_strcatrealloc(new_tab[0], "\t");
    for (int i = 0; opt->alias.alias != NULL && opt->alias.alias[i]; i++)
        if (my_strncmp(opt->alias.alias[i], tmp, my_strlen(tmp)) == 0) {
            free(tab[0]);
            tab[0] = get_new_cmd(opt->alias.alias[i], my_strlen(tmp));
            free(tmp);
            tmp = my_strdup(tab[0]);
            tab = change_cmd_tab(tab);
            i = 0;
        }
    free(tmp);
    free_2darray(new_tab);
    return (tab);
}