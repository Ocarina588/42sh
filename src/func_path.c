/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** func_path.c
*/

#include "my.h"
#include "minishell.h"

char **stock_env(env_t **envi)
{
    char **my_env = malloc(sizeof(char *) * (len_env(envi) + 2));
    env_t *tmp = (*envi);
    int i = 0;

    if (!my_env)
        return (NULL);
    while (tmp != NULL) {
        my_env[i] = my_strdup(tmp->data);
        i++;
        tmp = tmp->next;
    }
    my_env[i] = NULL;
    return (my_env);
}

int read_to_find(options_t *opt, int i)
{
    DIR *fd = opendir(opt->com.tpath[i]);
    struct dirent *lu = NULL;
    char *exe = NULL;

    if (fd == NULL)
        return (1);
    while ((lu = readdir(fd)) != NULL)
        if (!my_strcmp(opt->com.tab[0], lu->d_name)
            && opt->com.tab[0][0] != '\0') {
            exe = newstr_of_exeve(opt->com.tpath, lu, i);
            my_fork(opt, exe);
            free(exe);
            closedir(fd);
            return (0);
        }
    closedir(fd);
    return (1);
}

int func_return(int status)
{
    if (WIFEXITED(status))
        return (WEXITSTATUS(status));
    if (WIFSIGNALED(status) && WCOREDUMP(status)) {
        if (WTERMSIG(status) == 13);
        else if (WTERMSIG(status) == 8)
            dprint(2, "Floating exception (core dumped)\n" );
        else
            dprint(2, "%s (core dumped)\n", strsignal(WTERMSIG(status)));
        return (WTERMSIG(status) + 128);
    } else if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == 13);
        else if (WTERMSIG(status) == 8)
            dprint(2, "Floating exception\n" );
        else
            dprint(2, "%s\n", strsignal(WTERMSIG(status)));
        return (WTERMSIG(status) + 128);
    }
    return (-1);
}

int exe_path(options_t *opt)
{
    int j = 0;

    for (int i = 0; opt->com.tab[0][i]; i++)
        if (opt->com.tab[0][i] == '/')
            j = 1;
    if (!j)
        return (1);
    if (access(opt->com.tab[0], F_OK) == -1) {
        dprint(2, "%s: Command not found.\n", opt->com.tab[0]);
        opt->exit_v = 1;
        return (0);
    }
    my_fork(opt, opt->com.tab[0]);
    return (0);
}

int func_with_path(options_t *opt)
{
    if (my_strlen(opt->com.tab[0]) >= 256) {
        opt->exit_v = 1;
        dprint(2, "/usr/bin/%s: File name too long.\n", opt->com.tab[0]);
        return (0);
    }
    opt->com.my_env = stock_env(&opt->envi);
    if (!exe_path(opt))
        return (0);
    if (find_var(opt->com.my_env)) {
        dprint(2, "%s: Command not found.\n", opt->com.tab[0]);
        opt->exit_v = 1;
        return (0);
    }
    if (!search_path(opt))
        return (0);
    dprint(2, "%s: Command not found.\n", opt->com.tab[0]);
    opt->exit_v = 1;
    free_path(opt);
    return (0);
}