/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** close_and_dup
*/

#include "my.h"
#include "minishell.h"

static char *func[] =
    {"env", "setenv", "unsetenv", "cd", "alias", "unalias", "echo",
    "where", "repeat", NULL};

static int (*function[9])(env_t **, char **, options_t *) =
    {print_env, add_setenvi, remove_envi,
    cd, alias, unalias, echo_var, where, repeat};

void dup_close(int i, options_t *opt)
{
    if (i != 0) {
        if (dup2(opt->pcoma.old_fd[0], 0) == -1)
            exit(84);
        if (close(opt->pcoma.old_fd[0]) == -1)
            exit(84);
        if (close(opt->pcoma.old_fd[1]) == -1)
            exit(84);
    }
    if (opt->pcoma.exe[i + 1]) {
        if (close(opt->pcoma.new_fd[0]) == -1)
            exit(84);
        if (dup2(opt->pcoma.new_fd[1], 1) == -1)
            exit(84);
        if (close(opt->pcoma.new_fd[1]) == -1)
            exit(84);
    }
}

int pipe_path(int i, options_t *opt, char *exe1)
{
    dup_close(i, opt);
    execve(exe1, opt->pcoma.command[i], opt->com.my_env);
    dprint(2, "%s: %s.%s\n", opt->pcoma.command[i][0], strerror(errno),
    !my_strcmp(strerror(errno),
    "Exec format error") ? " Wrong Architecture." : "");
    exit(1);
}

int pipe_builtin(int i, options_t *opt, char *exe1)
{
    int index = 0;

    dup_close(i, opt);
    if (!my_strcmp(exe1, "exit")) {
        my_exit(opt, opt->pcoma.command[i]);
        exit(opt->getlines.my_exit);
    } else {
        index = find_index(func, opt->pcoma.command[i][0]);
        exit(function[index](&opt->envi, opt->pcoma.command[i], opt));
    }
}

int set_return_pipe(options_t *opt, int check, int status)
{
    for (int i = 0; opt->pcoma.exit_pipe[i] != -1; i++) {
        if (check == opt->pcoma.exit_pipe[i])
            opt->pcoma.exit_pipe[i] = func_return(status);
    }
}