/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** set_sep.c
*/

#include "my.h"
#include "minishell.h"

int set_command(options_t *opt)
{
    const char *r[] = {";", "&&", "||", NULL};

    opt->parsing.sep = parsing(opt->getlines.s);
    if (!opt->parsing.sep)
        return (1);
    opt->exit_v = check_error_sep(opt->parsing.sep);
    add_history(opt);
    if (opt->exit_v == 1)
        return (1);
    opt->parsing.sep_val = set_sep_value(opt);
    opt->parsing.cmd = set_functions(opt->parsing.sep, r);
    for (int i = 0; opt->parsing.cmd[i]; i++) {
        opt->exit_v = check_error_function(opt->parsing.cmd[i]);
        if (opt->exit_v == 1)
            return (1);
    }
    return (0);
}

int *set_sep_value(options_t *opt)
{
    int a = 0;
    int *tab = malloc(sizeof(int) * (len_2d(opt->parsing.sep) + 2));

    if (!tab) {
        opt->exit_v = 84;
        return (NULL);
    }
    for (int i = 0; opt->parsing.sep[i]; i++) {
        if (!my_strcmp(";", opt->parsing.sep[i]))
            tab[a++] = 1;
        if (!my_strcmp("||", opt->parsing.sep[i]))
            tab[a++] = 2;
        if (!my_strcmp("&&", opt->parsing.sep[i]))
            tab[a++] = 3;
    }
    tab[a] = -1;
    return (tab);
}