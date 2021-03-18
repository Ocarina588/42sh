/*
** EPITECH PROJECT, 2020
** parsign function bis
** File description:
** sdf
*/

#include <stdlib.h>
#include "my.h"
#include "minishell.h"

char ***set_functions(char **tab, const char **r)
{
    char ***functions = NULL;
    int start = 0;
    int len = 1;
    int j = 0;

    for (int i = 0; tab[i] ; i++)
        len += is_over(tab[i], r) != -1;
    if (!(functions = malloc(sizeof(char **) * (len + 1))))
        exit(84);
    for (int i = 0; i <= len ; i++)
        functions[i] = NULL;
    for (int i = 0; tab[i] ; i++) {
        if (is_over(tab[i], r) != -1) {
            tab[i] = NULL;
            tab[start] ? functions[j++] = tab + start : 0;
            start = i + 1;
        }
        functions[j] = tab + start;
    }
    return (functions);
}

options_t *get_opt(int mode, options_t *p)
{
    static options_t *opt = NULL;

    if (mode)
        opt = p;
    return (opt);
}