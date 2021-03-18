/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** which
*/

#include "my.h"
#include "minishell.h"

char **fill_builtin(char **tab)
{
    tab[0] = "cd";
    tab[1] = "setenv";
    tab[2] = "env";
    tab[3] = "unsetenv";
    tab[4] = "where";
    tab[5] = "which";
    tab[6] = "alias";
    tab[7] = "echo";
    tab[8] = "unalias";
    tab[9] = NULL;
    return (tab);
}

char *get_cmd(char *str)
{
    int slash = count_char(str, '/');
    char *clean_str = cut_str(str, slash, '/');

    return (clean_str);
}

int cmd_search(char *str, options_t *opt, char *all_path)
{
    if (check_alias(str, opt->alias.alias, 0) == 0)
        return (0);
    else if (check_builtin(str, 0) == 0)
        return (0);
    if (where_finds(str, all_path, 0) == 0)
        return (0);
    else {
        print("%s: Command not found.\n", str);
        return (1);
    }
}

int which_loop(int res, char **tab, options_t *opt, char **env)
{
    char *all_path = cut_str(env[res], 1, '=');
    char *path = NULL;
    int ret = 0;

    for (int i = 1; tab[i]; i++) {
        tab[i] = get_cmd(tab[i]);
        if (cmd_search(tab[i], opt, all_path) == 1)
            ret = 1;
    }
    return (ret);
}

int which(env_t **envi, char **tab, options_t *opt)
{
    char **env = stock_env(envi);
    int res = 0;

    if (!tab[1]) {
        dprint(2, "which: Too few arguments.\n");
        return (1);
    }
    res = get_path(env);
    if (res == -1)
        return (1);
    return (which_loop(res, tab, opt, env));
}