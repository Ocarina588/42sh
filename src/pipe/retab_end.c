/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** retab_end
*/

#include "my.h"
#include "minishell.h"

void retab_ends(options_t *opt, int tmp, int tmp2)
{
    if (dup2(tmp, 1) == -1)
        exit(84);
    if (dup2(tmp2, 0) == -1)
        exit(84);
    if (close(tmp) == -1)
        exit(84);
    if (close(tmp2) == -1)
        exit(84);
}