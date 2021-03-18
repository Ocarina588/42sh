/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** where
*/

#include "my.h"
#include "minishell.h"

int check_alias(char *str, char **alias, int opt)
{
    char *value = NULL;

    for (int i = 0; alias != NULL && alias[i]; i++) {
        if (!my_strncmp(alias[i], str, my_strlen(str)) &&
        alias[i][my_strlen(str)] == '\t') {
            value = get_alias(alias[i]);
            if (value && opt == 1)
                print("%s is aliased to %s\n", str, value);
            else if (value && opt != 1)
                print("%s: \t aliased to %s\n", str, value);
            free(value);
            return (0);
        }
    }
    return (1);
}

int where_finds(char *to_find, char *all_path, int opt)
{
    char *path = NULL;
    struct dirent *de = NULL;
    DIR *dir = NULL;
    int ret = 1;
    int res = 0;

    for (int j = 0; j < count_char(all_path, ':'); j++) {
        path = cut_str(all_path, j, ':');
        dir = opendir(path);
        if (dir != NULL)
            res = search_binary(to_find, path, de, dir);
            if (res == 1 && opt == 1)
                ret = 0;
            else if (res == 1 && opt != 1)
                return (0);
    }
    return (ret);
}

int where_loop(int res, char **tab, options_t *opt, char **env)
{
    char *all_path = cut_str(env[res], 1, '=');
    char *path = NULL;
    int ret = -1;

    if (!all_path)
        return (84);
    for (int i = 1; tab[i]; i++) {
        if (check_slash(tab[i]) > 0) {
            print("where: / in command makes no sense\n");
            ret = 1;
        } else {
            check_alias(tab[i], opt->alias.alias, 1);
            check_builtin(tab[i], 1);
            if (where_finds(tab[i], all_path, 1) == 1)
                ret = 1;
        }
    }
    free(all_path);
    free_2darray(env);
    return (ret);
}

int get_path(char **env)
{
    int res = 0;

    if (!env)
        return (-1);
    for (res; env[res] != NULL && my_strncmp(env[res], "PATH:", 4); res++);
    if (res == len_tab(env)) {
        dprint(2, "PATH: variable missing.\n");
        return (-1);
    }
    return (res);
}

int where(env_t **envi, char **tab, options_t *opt)
{
    char **env = stock_env(envi);
    int res = 0;

    if (!tab[1]) {
        dprint(2, "where: Too few arguments.\n");
        return (1);
    }
    res = get_path(env);
    if (res == -1)
        return (1);
    return (where_loop(res, tab, opt, env));
}