/*
** EPITECH PROJECT, 2024
** PSU_42sh_2019
** File description:
** Created by Dorian Berten
*/

#include "minishell.h"
#include "my.h"

char **get_cmd_repeat(char **cmd, int i)
{
    int j = 0;
    int tmp = 0;
    int size = 0;
    char **cmd_repeat = NULL;

    i += 2;
    tmp = i;
    for (; cmd[i]; i++, size++);
    cmd_repeat = malloc(sizeof(char *) * (size + 1));
    for (; cmd[tmp]; tmp++, j++)
        cmd_repeat[j] = my_strdup(cmd[tmp]);
    cmd_repeat[j] = NULL;
    return (cmd_repeat);
}

int check_error_repeat(char *str)
{
    int i = 0;

    for (; str[i]; i++) {
        if ((str[i] < '0' || str[i] > '9')
            && (str[i] != '-' ))
        return (1);
    }
    return (0);
}

int find_repeat(char **cmd)
{
    int i = 0;

    for (; cmd[i]; i++) {
        if (!my_strcmp(cmd[i], "repeat"))
            return (i);
    }
    return (-1);
}

int loop_repeat(options_t *opt, char **cmd, int i)
{
    int nb = my_getnbr(cmd[i + 1]);
    char **cmd_repeat = get_cmd_repeat(cmd, i);

    if (check_error_repeat(cmd[i + 1]) == 1) {
        dprint(2, "repeat: Badly formed number.\n");
        return (1);
    }
    if (nb <= 0)
        return (0);
    for (int j = 0; j < nb; j++)
        built_in(cmd_repeat, opt);
}

int repeat(env_t **env, char **cmd, options_t *opt)
{
    int i = find_repeat(cmd);

    if (i == -1)
        return (-1);
    if (!cmd[i + 1] || !cmd[i + 2]) {
        dprintf(2, "repeat: Too few arguments.\n");
        return (1);
    } else {
        if (loop_repeat(opt, cmd, i) == 1)
            return (1);
        return (opt->exit_v);
    }
}

