/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** history
*/

#include "my.h"
#include "minishell.h"

char *malloc_history(char **tab, char *str, int len)
{
    str = malloc(sizeof(char) * len);
    if (!str)
        exit(84);
    str[0] = '\0';
    return (str);
}

int get_size_history(char **tab)
{
    int i = 0;

    for (int j = 0; tab[j]; j++)
        for (int x = 0; tab[j][x]; x++)
            i++;
    i += len_tab(tab);
    return (i);
}

void add_history(options_t *opt)
{
    int size = len_tab(opt->history.history);
    char **tmp = malloc(sizeof(char *) * (size + 2));
    int len = 0;
    char *str = "\0";
    int i = 0;

    if (!tmp)
        exit(84);
    len = get_size_history(opt->parsing.sep);
    for (; opt->history.history != NULL && opt->history.history[i]; i++)
        tmp[i] = my_strdup(opt->history.history[i]);
    tmp[i] = malloc_history(tmp, tmp[i], len);
    for (int x = 0; opt->parsing.sep[x]; x++) {
        x != 0 ? str = my_strcatrealloc(str, " ") : 0;
        str = my_strcatrealloc(str, opt->parsing.sep[x]);
    }
    tmp[i] = my_strcpy(tmp[i], str);
    tmp[i + 1] = NULL;
    if (opt->history.history != NULL)
        free_2darray(opt->history.history);
    opt->history.history = tmp;
}