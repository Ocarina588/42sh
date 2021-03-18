/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** free_all.c
*/

#include "my.h"
#include "minishell.h"

void free_intermediate(options_t *opt)
{
    if (opt->com.tab)
        free_2darray(opt->com.tab);
    if (opt->redirect.files)
        free_2darray(opt->redirect.files);
    if (opt->redirect.nb)
        free(opt->redirect.nb);
    opt->redirect.files = NULL;
    opt->redirect.nb = NULL;
    opt->com.tab = NULL;
}

void free_path(options_t *opt)
{
    free(opt->com.path);
    free_2darray(opt->com.tpath);
}

void free_opt(options_t *opt)
{
    env_t *tmp = opt->envi;
    env_t *temp = NULL;

    while (tmp != NULL) {
        temp = tmp;
        tmp = tmp->next;
        free(temp->data);
        free(temp);
    }
    opt->envi = NULL;
    free(tmp);
    free(opt->envi);
    free(opt->getlines.s);
    free(opt);
}