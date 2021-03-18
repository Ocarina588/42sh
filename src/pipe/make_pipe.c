/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** make_pipe.c
*/

#include "my.h"
#include "minishell.h"

static char *func[] =
    {"env", "setenv", "unsetenv", "cd", "alias", "unalias", "where",
    "repeat", NULL};

static int (*function[8])(env_t **, char **, options_t *) =
    {print_env, add_setenvi, remove_envi, cd, alias, unalias,
    where, repeat};

int search_pipe(char **s, options_t *opt)
{
    opt->pcoma.nb_pipe = 0;

    for (int i = 0; s[i]; i++)
        if (!my_strcmp("|", s[i]))
            opt->pcoma.nb_pipe++;
    if (opt->pcoma.nb_pipe)
        return (1);
    return (0);
}

int check_built_in(options_t *opt, int i, char *exe1, int index)
{
    if (!opt->pcoma.exe[i + 1] && !my_strcmp(exe1, "built_in")) {
        if (dup2(opt->pcoma.old_fd[0], 0) == -1)
            exit(84);
        if (close(opt->pcoma.old_fd[0]) == -1)
            exit(84);
        if (close(opt->pcoma.old_fd[1]) == -1)
            exit(84);
        index = find_index(func, opt->pcoma.command[i][0]);
        opt->exit_v = function[index](&opt->envi, opt->pcoma.command[i], opt);
        return (1);
    }
    return (0);
}

int my_child_left(int i, int fd[2], options_t *opt, char *exe1)
{
    int pid = 0;
    int index = 0;
    int status = 0;

    if (check_built_in(opt, i, exe1, index) == 1)
        return (0);
    pid = fork();
    if (pid == -1)
        exit(84);
    if (pid == 0 && exe1 && !my_strcmp(exe1, "error"))
        exit(1);
    if (pid == 0 && (!my_strcmp(exe1, "built_in") || !my_strcmp(exe1, "exit")))
        pipe_builtin(i, opt, exe1);
    else if (pid == 0 && exe1)
        pipe_path(i, opt, exe1);
    return (pid);
}

int make_pipe(int pid, int *i, options_t *opt)
{
    int fd = 0;
    int (*red[4])(red_t, int) =
    {double_right, simple_right, double_left, simple_left};

    for (*i = 0; opt->pcoma.command[*i]; (*i)++) {
        for (int j = 0; opt->pcoma.red_pipe[*i].nb &&
        opt->pcoma.red_pipe[*i].nb[j] != -1; j++)
            fd = red[opt->pcoma.red_pipe[*i].nb[j] - 1]
            (opt->pcoma.red_pipe[*i], j);
        pid = my_fork_pipe_left(opt, opt->pcoma.exe[*i], *i);
    }
    return (pid);
}