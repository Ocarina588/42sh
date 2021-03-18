/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** free.c
*/

#include <stdlib.h>

void free_2darray(char **tab)
{
    int i = 0;
    for (i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab[i]);
    free(tab);
}