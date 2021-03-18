/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** init.c
*/

#include "my.h"
#include "minishell.h"

int search_path(options_t *opt)
{
    opt->com.path = get_variable(&opt->envi, "PATH");
    opt->com.tpath = parse_path(opt->com.path);
    for (int i = 0; opt->com.tpath[i]; i++) {
        if (access(opt->com.tpath[i], F_OK) == -1)
            continue;
        if (!read_to_find(opt, i)) {
            free_path(opt);
            return (0);
        }
    }
    return (1);
}

red_t set_redirect(red_t red, char **s)
{
    red.files = malloc(sizeof(char *) * (nb_red(s) + 1));
    if (!red.files)
        return ((red_t){0});
    red.nb = find_nb_redirections(red, s);
    red.files = fill_files(s, red);
    return (red);
}

r_t set_read(void)
{
    r_t r;

    r.s = NULL;
    r.size = 1;
    return (r);
}

alias_t init_alias(void)
{
    alias_t alias;

    alias.pid = nbstr(getpid());
    alias.alias = NULL;
    return (alias);
}

history_t init_history(void)
{
    history_t history;

    history.set = NULL;
    history.history = NULL;
    return (history);
}