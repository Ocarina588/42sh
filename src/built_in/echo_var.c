/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** echo_var.c
*/

#include "my.h"
#include "minishell.h"

int check_error(char **cmd, options_t *opt)
{
    for (int j = 0; cmd[j]; j++)
        for (int i = 0; cmd[j][i]; i++)
            if (check_echo_var(cmd, &i, j, opt))
                return (1);
    return (0);
}

int echo_var(env_t **env, char **cmd, options_t *opt)
{
    for (int j = 1; cmd[j]; j++) {
        if (!my_strcmp(cmd[j], "$?")) {
            print("%d", opt->alias.echo_value);
        } else
            print("%s", cmd[j]);
        cmd[j + 1] ? print(" ") : print("\n");
    }
    return (0);
}