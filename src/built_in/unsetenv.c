/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** unsetenv.c
*/

#include "my.h"
#include "minishell.h"

int free_tmp(env_t **envi, char **tab)
{
    for (int i = 1; tab[i]; i++) {
        env_t *tmp = (*envi);
        env_t *tmprev = (*envi);
        find_tmp(tmp, tmprev, tab[i]);
    }
    return (0);
}

int remove_envi(env_t **envi, char **cmd, options_t *opt)
{
    char **tab = copy_tab(cmd);
    clean_function(tab);
    int i = 0;
    env_t *tmp = (*envi);

    if (tmp == NULL)
        return (0);
    for (i = 0; tab[i]; i++);
    if (i == 1) {
        dprint(2, "unsetenv: Too few arguments.\n");
        return (1);
    }
    if (!cmpunsetenv(tmp->data, tab[1])) {
        (*envi) = tmp->next;
        free(tmp->data);
        free(tmp);
        return (0);
    }
    free_tmp(envi, tab);
    return (0);
}

int print_env(env_t **envi, char **tab, options_t *opt)
{
    (void)(tab);
    env_t *tmp = (*envi);

    while (tmp != NULL) {
        print("%s\n", tmp->data);
        tmp = tmp->next;
    }
    return (0);
}

int cmpunsetenv(char *str, char *tab)
{
    int i = 0;
    for (i = 0; str[i] != '='; i++) {
        if (str[i] != tab[i] || tab[i] == '\0')
            return (1);
    }
    if (tab[i] != '\0')
        return (1);
    return (0);
}

int cmp(char *str, char *tab)
{
    for (int i = 0; tab[i] != '\0' && tab[i] != '='; i++) {
        if (str[i] != tab[i])
            return (1);
    }
    return (0);
}