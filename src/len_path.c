/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** len_path.c
*/

#include "my.h"
#include "minishell.h"

int nb_path(char *s)
{
    int count = 1;

    for (int i = 0; s[i]; i++)
        if (s[i] == ':')
            count++;
    return (count);
}

int path_len(char *s, int a)
{
    int i = a;
    int z = 0;

    for (i = i; s[i]; i++, z++)
        if (s[i] == ':')
            return (z);
    return (z);
}

char *fill_path(char *s, char *path, int *a)
{
    int i = 0;

    for (*a = *a; s[*a]; (*a)++) {
        if (s[*a] == ':')
            break;
        path[i++] = s[*a];
    }
    path[i++] = '/';
    path[i] = '\0';
    return (path);
}

char **parse_path(char *s)
{
    char **path = malloc(sizeof(char *) * (nb_path(s) + 1));
    int a = 0;
    int i = 0;

    if (!path)
        return (NULL);
    for (i = 0; i < nb_path(s); i++) {
        path[i] = malloc(sizeof(char) * path_len(s, a) + 2);
        if (!path[i])
            return (NULL);
        path[i] = fill_path(s, path[i], &a);
        a++;
    }
    path[i] = NULL;
    return (path);
}

int len_env(env_t **envi)
{
    env_t *tmp = (*envi);
    int count = 0;

    while (tmp != NULL) {
        tmp = tmp->next;
        count++;
    }
    return (count);
}