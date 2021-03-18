/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** utils
*/

#include "my.h"
#include "minishell.h"

int count_char(char *str, char cut)
{
    int x = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == cut)
            x++;
    return (x);
}

void signal_handler(int num)
{
    get_line_p(0, NULL)->str = my_strdup("");
    get_line_p(0, NULL)->pos = 0;
    get_line_p(0, NULL)->pos_history =
        len_2d(get_opt(0, NULL)->history.history);
    print("\n$> ");
}

char **reorder_tab_next(char **tab, int i, int j)
{
    char *tmp;

    if (i != j && my_strcmp(tab[i], tab[j]) < 0) {
        tmp = tab[i];
        tab[i] = tab[j];
        tab[j] = tmp;
    }
    return (tab);
}

char **reorder_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        for (int j = 0; tab[j]; j++)
            tab = reorder_tab_next(tab, i, j);
    return (tab);
}

int len_tab(char **tab)
{
    int i = 0;

    if (tab == NULL)
        return (0);
    for (; tab[i]; i++);
    return (i);
}