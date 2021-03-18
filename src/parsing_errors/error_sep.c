/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** error_sep.c
*/

#include <stdlib.h>
#include "minishell.h"
#include "my.h"

int check_error_sep(char **cmd)
{
    for (int i = 0; cmd[i]; i++) {
        if ((!my_strcmp(cmd[i], "||") || !my_strcmp(cmd[i], "&&"))
            && (!i || !cmd[i + 1])) {
            dprint(2, "Invalid null command.\n");
            return (1);
        }
        if ((!my_strcmp(cmd[i], "||") || !my_strcmp(cmd[i], "&&"))
        && (is_co(cmd[i + 1]) || !my_strcmp("|", cmd[i + 1])
        || !my_strcmp("||", cmd[i + 1]) || !my_strcmp("&&", cmd[i + 1])
        || !my_strcmp(";", cmd[i + 1]))) {
            dprint(2, "Invalid null command.\n");
            return (1);
        }
    }
}