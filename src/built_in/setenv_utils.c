/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** setenv_utils
*/

#include "my.h"
#include "minishell.h"

void addnode_end(env_t **start_queue, env_t *node)
{
    env_t *tmp = (*start_queue);

    if ((*start_queue) == NULL) {
        *start_queue = node;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = node;
}

env_t *crnode(char *data)
{
    env_t *node = malloc(sizeof(env_t));

    if (!node)
        return (NULL);
    node->data = my_strdup(data);
    node->next = NULL;
    return (node);
}

int setenvi(char **env, options_t *opt)
{
    env_t **envi = &opt->envi;
    env_t *tmp;

    (*envi) = NULL;
    for (int i = 0; env[i]; i++) {
        tmp = crnode(env[i]);
        if (!tmp)
            return (84);
        addnode_end(envi, tmp);
    }
    return (0);
}

char *change_str(char **tab, env_t **envi, options_t *opt)
{
    char *str = NULL;
    char *newstr = NULL;
    char *env_ret = "env";
    int i = 0;

    for (i = 0; tab[i]; i++);
    if (i > 3 && dprint(2, "setenv: Too many arguments.\n"))
        return (NULL);
    if (i == 1 && !print_env(envi, tab, opt))
        return (env_ret);
    return (my_new_str(tab, str, newstr, i));
}