/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** stock_red.c
*/

#include "minishell.h"
#include "my.h"

int fill_right(red_t red, char *s, char *y, int *a)
{
    int j = 0;
    int z = 0;

    if (!my_strcmp(s, ">") || !my_strcmp(s, "<")
            || !my_strcmp(s, ">>") || !my_strcmp(s, "<<")) {
        red.files[*a] = malloc(sizeof(char) * my_strlen(y) + 2);
        if (!red.files[*a])
            return (84);
        red.files[*a] = my_strcpy(red.files[*a], y);
        (*a)++;
        return (1);
    }
    return (0);
}

char **fill_files(char **s, red_t red)
{
    int exit = 0;
    int a = 0;

    for (int i = 0; s[i + 1]; i++) {
        exit = fill_right(red, s[i], s[i + 1], &a);
        if (exit == 84)
            return (NULL);
    }
    red.files[a] = NULL;
    return (red.files);
}

char **modifcmd(char **s)
{
    int j = 0;
    char **newcmd = malloc(sizeof(char *) * (len_2d(s) + 1));

    if (!newcmd)
        return (NULL);
    for (int i = 0; s[i]; i++) {
        if (is_co(s[i])) {
            i++;
            continue;
        }
        newcmd[j++] = my_strdup(s[i]);
    }
    newcmd[j] = NULL;
    return (newcmd);
}