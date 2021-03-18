/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** pipe.c
*/

#include "my.h"
#include "minishell.h"

int my_fork_pipe_left(options_t *opt, char *exe1, int i)
{
    int pid = 0;
    int status = 0;

    if (opt->pcoma.exe[i + 1])
        if (pipe(opt->pcoma.new_fd) == -1)
            exit(84);
    pid = my_child_left(i, opt->pcoma.new_fd, opt, exe1);
    opt->pcoma.exit_pipe[i] = (int)pid;
    if (pid > 0) {
        if (i != 0) {
            close(opt->pcoma.old_fd[0]);
            close(opt->pcoma.old_fd[1]);
        }
        if (opt->pcoma.exe[i + 1]) {
            opt->pcoma.old_fd[0] = opt->pcoma.new_fd[0];
            opt->pcoma.old_fd[1] = opt->pcoma.new_fd[1];
        }
    }
    return (pid);
}

int search_path_pipe(options_t *opt, int j)
{
    opt->com.path = get_variable(&opt->envi, "PATH");
    opt->com.tpath = parse_path(opt->com.path);
    for (int i = 0; opt->com.tpath[i + 1]; i++) {
        if (access(opt->com.tpath[i], F_OK) == -1)
            continue;
        opt->pcoma.exe[j] = read_to_find_pipe(opt, i, j);
        if (opt->pcoma.exe[j]) {
            free_path(opt);
            return (0);
        }
    }
    free_path(opt);
    return (1);
}

int exe_path_pipe(options_t *opt, int i)
{
    int j = 0;

    for (int z = 0; opt->pcoma.command[i][0][z]; z++)
        if (opt->pcoma.command[i][0][z] == '/')
            j = 1;
    if (!j)
        return (1);
    if (access(opt->pcoma.command[i][0], F_OK) == -1) {
        opt->exit_v = 1;
        opt->pcoma.exe[i] = my_strdup("error");
        dprint(2, "%s: Command not found.\n", opt->pcoma.command[i][0]);
        return (0);
    }
    opt->pcoma.exe[i] = my_strdup(opt->pcoma.command[i][0]);
    return (0);
}

int fill_exe(options_t *opt, int i)
{
    if (my_strlen(opt->pcoma.command[i][0]) >= 256) {
        opt->exit_v = 1;
        opt->pcoma.exe[i] = my_strdup("error");
        dprint(2, "/usr/bin/%s: File name too long.\n",
            opt->pcoma.command[i][0]);
        return (0);
    }
    if (!exe_path_pipe(opt, i))
        return (0);
    if (find_var(opt->com.my_env)) {
        opt->exit_v = 1;
        opt->pcoma.exe[i] = my_strdup("error");
        dprint(2, "%s: Command not found.\n", opt->pcoma.command[i][0]);
        return (0);
    }
    if (!search_path_pipe(opt, i))
        return (0);
    opt->exit_v = 1;
    dprint(2, "%s: Command not found.\n", opt->pcoma.command[i][0]);
    opt->pcoma.exe[i] = my_strdup("error");
    return (0);
}

void what_function_pipe(options_t *opt)
{
    int i = 0;
    int tmp = dup(1);
    int tmp2 = dup(0);
    int pid = 0;
    int check = 0;
    int status = 0;

    pid = make_pipe(pid, &i, opt);
    opt->pcoma.exit_pipe[i] = -1;
    check = waitpid(-1, &status, 0);
    set_return_pipe(opt, check, status);
    while (1) {
        check = waitpid(-1, &status, 0);
        if (check <= 0)
            break;
        set_return_pipe(opt, check, status);
    }
    for (int i = 0; opt->pcoma.exit_pipe[i] != -1; i++)
        if (opt->pcoma.exit_pipe[i] > 0)
            opt->exit_v = opt->pcoma.exit_pipe[i];
    retab_ends(opt, tmp, tmp2);
}