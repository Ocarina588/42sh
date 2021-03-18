/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** setenv.c
*/

#include "my.h"
#include "minishell.h"

void add_setenvi_next(env_t *tmp, env_t **envi, char *str)
{
    while (tmp != NULL) {
        if (!cmp(tmp->data, str)) {
            free(tmp->data);
            tmp->data = my_strdup(str);
            free(str);
            return;
        }
        tmp = tmp->next;
    }
    addnode_end(envi, crnode(str));
    free(str);
}

int add_setenvi(env_t **envi, char **cmd, options_t *opt)
{
    char **tab = copy_tab(cmd);
    env_t *tmp = (*envi);
    char *str;

    clean_function(tab);
    str = change_str(tab, envi, opt);
    if (str == NULL)
        return (1);
    if (!my_strcmp(str, "env"))
        return (0);
    if (handling_errors_of_setenv(tab)) {
        free(str);
        return (1);
    }
    add_setenvi_next(tmp, envi, str);
    return (0);
}