/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** setenv_bis.c
*/

#include "my.h"
#include "minishell.h"

int handling_errors_of_setenv(char **tab)
{
    if ((tab[1][0] < 'A' || tab[1][0] > 'Z')
    && (tab[1][0] < 'a' || tab[1][0] > 'z') && tab[1][0] != '_') {
        dprint(2, "setenv: Variable name must begin with a letter.\n");
        return (1);
    }
    if (check_tab(tab[1])) {
        dprint(2,
        "setenv: Variable name must contain alphanumeric characters.\n");
        return (1);
    }
    return (0);
}

char *newstr_of_exeve(char **path, struct dirent *lu, int i)
{
    char *newstr = malloc(sizeof(char) *
    my_strlen(path[i]) + my_strlen(lu->d_name) + 2);

    if (!newstr)
        return (NULL);
    newstr = my_strcpy(newstr, path[i]);
    newstr = my_strcat(newstr, lu->d_name);
    return (newstr);
}

int red_fork(options_t *opt, char *exe)
{
    pid_t pid;
    int status = 0;
    int tmp = dup(1);

    pid = my_child_red(opt, exe);
    gestion_err_fork(pid, status);
    if (dup2(tmp, 1) == -1)
        exit(84);
    close(tmp);
    opt->exit_v = func_return(status);
    return (0);
}

int my_fork(options_t *opt, char *exe)
{
    pid_t pid;
    int status = 0;

    if ((pid = fork()) == 0) {
        execve(exe, opt->com.tab, opt->com.my_env);
        dprint(2, "%s: %s.%s\n", opt->com.tab[0], strerror(errno),
        !my_strcmp(strerror(errno),
        "Exec format error") ? " Wrong Architecture." : "");
        exit(1);
    }
    status = gestion_err_fork(pid, status);
    opt->exit_v = func_return(status);
    return (0);
}

int find_tmp(env_t *tmp, env_t *tmprev, char *tab)
{
    while (tmp != NULL) {
        if (!cmpunsetenv(tmp->data, tab)) {
            tmprev->next = tmp->next;
            free(tmp->data);
            free(tmp);
            return (0);
        }
        tmprev = tmp;
        tmp = tmp->next;
    }
    return (0);
}