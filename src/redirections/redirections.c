/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** redirections.c
*/

#include "minishell.h"
#include "my.h"

int gestion_err_fork(int pid, int status)
{
    if (pid > 0)
        if (waitpid(pid, &status, 0) < 0) {
            perror("wait");
            exit(1);
        }
    if (pid == -1) {
        perror("fork");
        exit(1);
    }
    return (status);
}

int nb_red(char **s)
{
    int count = 0;

    for (int i = 0; s[i]; i++) {
        if (!my_strcmp(s[i], ">") || !my_strcmp(s[i], "<")
            || !my_strcmp(s[i], ">>") || !my_strcmp(s[i], "<<")) {
            count++;
        }
    }
    return (count);
}

int check_right(char *s, int *a, red_t red)
{
    if (!my_strcmp(s, ">>")) {
        red.nb[(*a)++] = 1;
        return (1);
    } else if (!my_strcmp(s, ">")) {
        red.nb[(*a)++] = 2;
        return (1);
    }
    return (0);
}

int check_left(char *s, int *a, red_t red)
{
    if (!my_strcmp(s, "<")) {
        red.nb[(*a)++] = 4;
        return (1);
    } else if (!my_strcmp(s, "<<")) {
        red.nb[(*a)++] = 3;
        return (1);
    }
    return (0);
}

int *find_nb_redirections(red_t red, char **s)
{
    int a = 0;

    red.nb = malloc(sizeof(int) * (nb_red(s) + 1));
    if (!red.nb)
        return (NULL);
    for (int i = 0; s[i]; i++) {
        if (check_right(s[i], &a, red));
        else if (check_left(s[i], &a, red));
    }
    red.nb[a] = -1;
    return (red.nb);
}