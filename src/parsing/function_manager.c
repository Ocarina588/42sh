/*
** EPITECH PROJECT, 2020
** function manager
** File description:
** sdf
*/

#include <stdlib.h>
#include "minishell.h"
#include "my.h"

const char *co[] = {";", "&&", "||", NULL};

const char *co_bis[] = {">", ">>", "<", "<<", NULL};

int is_co(char *s)
{
    char *r[] = {">", ">>", "<", "<<", NULL};
    if (!s)
        return (1);
    for (int i = 0; r[i] ; i++)
        if (!my_strcmp(s, r[i]))
            return (1);
    return (0);
}

int check_error_function_bis(char **tab, int i, int *a, int *b)
{
    if (is_co(tab[i]) && is_co(tab[i + 1])) {
        dprint(2, "Missing name for redirect.\n");
        return (1);
    }
    if ((!my_strcmp(tab[i], "|") && (!i || !tab[i + 1]))) {
        dprint(2, "Invalid null command.\n");
        return (1);
    }
    if (!my_strcmp(tab[i], "<") || !my_strcmp(tab[i], "<<"))
        if ((*a)++ > 0) {
            dprint(2, "Ambiguous input redirect.\n");
            return (1);
        }
    if (!my_strcmp(tab[i], ">") || !my_strcmp(tab[i], ">>"))
        if ((*b)++ > 0) {
            dprint(2, "Ambiguous output redirect.\n");
            return (1);
        }
    return (0);
}

int find_command(char **tab, int i, int *rep, int *co)
{
    if (*co)
        return (1);
    if (is_co(tab[i])) {
        (*rep) = 1;
        return (1);
    }
    if (!is_co(tab[i]) && my_strcmp(tab[i], "|") && !*rep)
        (*co) = 1;
    if ((!my_strcmp(tab[i], "|") && !(*rep)) || (!tab[i + 1] && (*rep)))
        return (0);
    if (!my_strcmp(tab[i], "|")) {
        (*rep) = 0;
        (*co) = 1;
        return (1);
    }
    (*rep) = 0;
    return (1);
}

void reset_tmp(char *s, int *a, int *b)
{
    if (!my_strcmp(s, "|")) {
        *a = 0;
        *b = 0;
    }
}

int check_error_function(char **tab)
{
    int tmp[4] = {0, 0, 0, 0};
    for (int i = 0; tab[i] ; i++) {
        if (!find_command(tab, i, tmp, tmp + 1)) {
            dprint(2, "Invalid null command.\n");
            return (1);
        }
        reset_tmp(tab[i], tmp, tmp + 1);
        if ((!my_strcmp(tab[i], ">") ||
            !my_strcmp(tab[i], ">>")) && find_pipe(tab, 1, i)) {
            dprint(2, "Ambiguous output redirect.\n");
            return (1);
        }
        if ((!my_strcmp(tab[i], "<")
            || !my_strcmp(tab[i], "<<")) && find_pipe(tab, 0, i)) {
            dprint(2, "Ambiguous input redirect.\n");
            return (1);
        }
        if (check_error_function_bis(tab, i, tmp + 2, tmp + 3))
            return (1);
    }
    return (0);
}