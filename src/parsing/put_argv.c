/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** put_argv.c
*/

#include "./my.h"
#include "./minishell.h"

int nb_argv(char *s, char c)
{
    int count = 1;

    for (int i = 0; s[i]; i++) {
        if (s[i] == '"')
            for (i = i + 1; s[i] != '"'; i++);
        if (s[i] == '\'')
            for (i = i + 1; s[i] != '\''; i++);
        if (s[i] == c) {
            for (i = i + 1; s[i] == c; i++);
            if (s[i] != '\n')
                count++;
        }
    }
    return (count);
}

int size_string(char *s, int a, char c)
{
    int len = 0;
    for (a = a; s[a] != c && s[a] != '\0'; a++)
        len++;
    return (len);
}

char *fill_argv(char *s, char *tab, int *a, char c)
{
    int i = 0;

    for (; s[*a] != c && s[*a] != '\0'; (*a)++) {
        if (s[*a] == '"')
            for (; s[*a] != '"'; (*a)++)
                tab[i++] = s[*a];
        else if (s[*a] == '\'')
            for (; s[*a] != '\''; (*a)++)
                tab[i++] = s[*a];
        tab[i++] = s[*a];
    }
    tab[i] = '\0';
    return (tab);
}

char **put_argv(char *s, char c)
{
    int i = 0;
    int a = 0;
    char **tab = malloc(sizeof(char *) * (nb_argv(s, c) + 2));

    if (!tab)
        return (NULL);
    for (i = 0; i < nb_argv(s, c); i++) {
        tab[i] = malloc(sizeof(char) * (size_string(s, a, c) + 1));
        if (!tab[i])
            return (NULL);
        tab[i] = fill_argv(s, tab[i] , &a, c);
        for (a = a; s[a] == c; a++);
    }
    tab[i] = NULL;
    return (tab);
}