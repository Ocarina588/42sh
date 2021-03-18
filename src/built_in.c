/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** built_in.c
*/

#include "my.h"
#include "minishell.h"

static char *func[] =
    {"env", "setenv", "unsetenv", "cd", "alias", "unalias", "where",
    "which", "repeat", "set", NULL};

static int (*function[10])(env_t **, char **, options_t *) =
    {print_env, add_setenvi, remove_envi, cd, alias, unalias,
    where, which, repeat, set};

void what_function_next(int index, int tmp, int tmp2, options_t *opt)
{
    if (index != -1) {
        opt->exit_v = function[index](&opt->envi, opt->com.tab, opt);
    } else {
        clean_function(opt->com.tab);
        func_with_path(opt);
    }
    dup2(tmp2, 0);
    close(tmp2);
    dup2(tmp, 1);
    close(tmp);
}

void what_function(char **cmd, options_t *opt)
{
    int index = find_index(func, cmd[0]);
    int i = 0;
    int tmp;
    int tmp2;

    opt->com.tab = malloc(sizeof(char *) * (len_2d(cmd) + 1));
    if (!opt->com.tab)
        exit(84);
    for (i = 0; cmd[i]; i++)
        opt->com.tab[i] = my_strdup(cmd[i]);
    tmp = dup(1);
    tmp2 = dup(0);
    opt->com.tab[i] = NULL;
    if (opt->redirect.files)
        if (set_red_built_in(opt) == -1) {
            opt->exit_v = 1;
            dup2(tmp, 1);
            close(tmp);
            return;
        }
    what_function_next(index, tmp, tmp2, opt);
}

int built_in(char **cmd, options_t *opt)
{
    cmd = change_cmd_alias(cmd, opt);
    if (nb_red(cmd) && !search_pipe(cmd, opt)) {
        opt->redirect = set_redirect(opt->redirect, cmd);
        cmd = modifcmd(cmd);
    }
    if (search_pipe(cmd, opt))
        return (manage_pipe(cmd, opt));
    if (!my_strcmp(cmd[0], "exit"))
        return (my_exit(opt, cmd));
    what_function(cmd, opt);
    return (0);
}