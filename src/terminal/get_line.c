/*
** EPITECH PROJECT, 2020
** get line
** File description:
** sdf
*/

#include <stdlib.h>
#include "my.h"
#include "minishell.h"

char *fuse(char *a, char *b)
{
    int len = my_strlen(a) + my_strlen(b);
    char *s = malloc(sizeof(char) * (len + 1));

    if (!s)
        exit(84);
    my_strcpy(s, a);
    my_strcat(s, b);
    return (s);
}

void shift(char *s)
{
    for (int i = 0; s[i] ; i++)
        s[i] = s[i + 1];
}

void enter_manage(char *s)
{
    char c = 0;
    int rep = 0;

    for (int i = 0; s[i] ; i++) {
        if (!rep && (s[i] == '"' || s[i] == '\'')) {
            c = s[i];
            rep ^= 1;
        }
        else if (rep && s[i] == c)
            rep ^= 1;
        if (!rep && s[i] == '\\' && s[i + 1] == '\n') {
            shift(s + i);
            shift(s + i);
        }
    }
}

int stop_loop(int rep, char **final, char *s)
{
    if (rep == -1) {
        isatty(0) ? print("exit\n") : 0;
        return (1);
    }
    *final = fuse(*final, s);
    if (!(my_strlen(s) >= 2 && s[my_strlen(s) - 2] == '\\'
    && s[my_strlen(s) - 1] == '\n'))
        return (2);
    return (0);
}

int get_line(options_t *opt)
{
    char *s = NULL;
    char *final = my_strdup("");
    char *tab[] = {"$> ", "? "};
    int i = 0;
    int rep = 0;

    while (1) {
        isatty(0) ? print("%s", tab[i]) : 0;
        i = 1;
        rep = isatty(0) ? my_getline(&s) :
            getline(&s, &opt->getlines.size, stdin);
        rep = stop_loop(rep, &final, s);
        if (rep == 1)
            return (1);
        if (rep == 2)
            break;
    }
    enter_manage(final);
    opt->getlines.s = final;
    return (0);
}