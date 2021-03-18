/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** cd_err
*/

#include "minishell.h"
#include "my.h"

int handling_errors(char **tab)
{
    int i = 0;

    for (i = 0; tab[i]; i++);
    if (i > 2) {
        dprint(2, "cd: Too many arguments.\n");
        return (0);
    }
    if (i == 1)
        return (2);
    return (1);
}