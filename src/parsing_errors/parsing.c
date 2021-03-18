/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** parsing.c
*/

#include "my.h"
#include "minishell.h"

int verify1(int *i, char *s)
{
    for ((*i) = (*i) + 1; s[*i]; (*i)++)
        if (s[*i] == '\'' && s[(*i) - 1] != '\\' && (*i) != 0)
            return (1);
    return (0);
}

int verify2(int *i, char *s)
{
    for ((*i) = (*i) + 1; s[*i]; (*i)++)
        if (s[*i] == '"' && s[(*i) - 1] != '\\' && (*i) != 0)
            return (1);
    return (0);
}

int search_coat(int *i, char *s)
{
    if (s[*i] == '"') {
        if (verify2(i, s))
            return (1);
    } else if (s[*i] == '\'') {
        if (verify1(i, s))
            return (1);
    }
    return (0);
}

int skip_back(char *s, int *i)
{
    int z = 0;

    for (*i = *i; s[*i] == '\\'; (*i)++, z++);
    return (z);
}

char **parsing(char *s)
{
    int rep = 0;
    char **tab = first_parsing(s, &rep);

    if (!tab)
        return (NULL);
    tab = parsing_2(tab);
    return (tab);
}