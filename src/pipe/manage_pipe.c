/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** manage_pipe
*/

#include "my.h"
#include "minishell.h"

static char *func[] =
    {"env", "setenv", "unsetenv", "cd", "alias", "unalias", "where",
    "which", "repeat", NULL};

static int (*function[10])(env_t **, char **, options_t *) =
    {print_env, add_setenvi, remove_envi, cd, alias, unalias,
    where, which, repeat};

int manage_pipe_next(options_t *opt)
{
    int i = 0;

    for (i = 0; opt->pcoma.command[i]; i++) {
        int index = find_index(func, opt->pcoma.command[i][0]);
        if (index != -1)
            opt->pcoma.exe[i] = my_strdup("built_in");
        else if (!my_strcmp(opt->pcoma.command[i][0], "exit"))
            opt->pcoma.exe[i] = my_strdup("exit");
        else {
            clean_function(opt->pcoma.command[i]);
            fill_exe(opt, i);
        }
    }
    return (i);
}

int manage_pipe(char **s, options_t *opt)
{
    int i = 0;

    opt->pcoma.exit_pipe = malloc(sizeof(int *) * (len_2d(s) + 1));
    if (!opt->pcoma.exit_pipe)
        exit(84);
    opt->com.my_env = stock_env(&opt->envi);
    fill_command(opt, s);
    i = manage_pipe_next(opt);
    opt->pcoma.exe[i] = NULL;
    what_function_pipe(opt);
    return (0);
}
