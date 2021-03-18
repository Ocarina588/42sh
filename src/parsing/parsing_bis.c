/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** parsing bis
*/

#include "my.h"
#include "minishell.h"
#include <stdlib.h>

void func_pars(int *i, char **input, char **av)
{
    char c;
    int j = 0;

    while (find_new_word(input)) {
        *i = find_end(*input, 0);
        c = (*input)[*i];
        (*input)[*i] = 0;
        av[j++] = my_strdup(*input);
        *input = *input + *i +  (c ? 1 : 0);
    }
}

int func_pars_two(int *len, int *i, char **str, char *tmp)
{
    while (find_new_word(str)) {
        (*len)++;
        if ((*i = find_end(*str, 0)) == -1) {
            free(tmp);
            return (1);
        }
        *str = *str + *i + (*(*str + *i) ? 1 : 0);
    }
    return (0);
}