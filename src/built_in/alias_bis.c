/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** alias_bis
*/

#include "my.h"
#include "minishell.h"

int is_quote(char **tab)
{
    int i = len_tab(tab) - 1;
    int len = my_strlen(tab[i]) - 1;

    if ((tab[i][len] == '\'' || tab[i][len] == '\"') &&
    (tab[2][0] == '\'' || tab[2][0] == '\"'))
        return (1);
    return (0);
}

void print_alias(char **alias)
{
    if (alias == NULL)
        return;
    for (int i = 0; alias[i]; i++)
        print("%s\n", alias[i]);
}

int get_total_size(char **tab)
{
    int i = 0;

    for (int j = 0; tab[j]; j++)
        for (int x = 0; tab[j][x]; x++)
            i++;
    i += len_tab(tab) - 7;
    return (i);
}

char **copy_alias_parent(char *str, int i, char **alias)
{
    int k = 0;

    for (; alias[i][k]; k++);
    alias[i][k] = '\t';
    k++;
    alias[i][k] = '(';
    k++;
    for (; str[k - 1]; k++)
        alias[i][k] = str[k - 1];
    alias[i][k] = ')';
    k++;
    alias[i][k] = '\0';
    alias[i + 1] = NULL;
    return (alias);
}

char **copy_alias(char *str, int i, char **alias)
{
    int k = 0;

    for (; alias[i][k]; k++);
    alias[i][k] = '\t';
    k++;
    for (; str[k]; k++)
        alias[i][k] = str[k];
    alias[i][k] = '\0';
    alias[i + 1] = NULL;
    return (alias);
}