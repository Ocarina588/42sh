/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** clean_utils
*/

#include "my.h"
#include "minishell.h"

void removeb(char *s)
{
    for (int i = 0; s[i] ; i++)
        s[i] = s[i + 1];
}

void clean_function(char **functions)
{
    for (int i = 0 ; functions && functions[i]; i++)
        clean_function_loop(functions, i);
}