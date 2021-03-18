/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** get_variable.c
*/

#include "my.h"
#include "minishell.h"

char *fill_var(char *tab)
{
    char *newstr = malloc(sizeof(char) * my_strlen(tab) + 2);
    int i = 0;
    int j = 0;

    if (!newstr)
        return (NULL);
    for (i = 0; tab[i] != '='; i++);
    for (j = 0, i = i + 1; tab[i]; i++)
        newstr[j++] = tab[i];
    newstr[j] = '\0';
    return (newstr);
}

char *get_variable(env_t **envi, char *str)
{
    env_t *tmp = (*envi);
    char *newstr = NULL;

    while (tmp != NULL) {
        if (!cmp(tmp->data, str)) {
            newstr = fill_var(tmp->data);
            return (newstr);
        }
        tmp = tmp->next;
    }
    return (NULL);
}

char *remove_slesh_next(char *s, int i)
{
    if (s[i] == '\\')
        for (int j = i; s[j] != '\n'; j++)
            s[j] = s[j+1];
    return (s);
}

char *remove_slash(char *s)
{
    int i = 0;

    for (i = 0; s[i]; i++) {
        if (s[i] == '"')
            for (i = i + 1; s[i] != '"'; i++);
        else if (s[i] == '\'')
            for (i = i; s[i] != '\''; i++);
        else
            s = remove_slesh_next(s, i);
    }
    return (s);
}

int find_var(char **my_env)
{
    for (int i = 0; my_env[i]; i++)
        if (!cmp(my_env[i], "PATH"))
            return (0);
    return (1);
}