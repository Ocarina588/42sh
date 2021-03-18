/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** path_red.c
*/

#include "my.h"
#include "minishell.h"

int set_red_built_in(options_t *opt)
{
    int fd = 0;
    int (*red[4])(red_t, int) =
    {double_right, simple_right, double_left, simple_left};

    for (int i = 0; opt->redirect.nb[i] != -1; i++)
        if (red[opt->redirect.nb[i] - 1](opt->redirect, i) == -1)
            return (-1);
    return (0);
}

int simple_right(red_t red, int i)
{
    int fd = open(red.files[i], O_WRONLY | O_TRUNC | O_CREAT,
    S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);

    if (fd == -1) {
        print("%s: %s.\n", red.files[i], strerror(errno));
        return (-1);
    }
    if (dup2(fd, 1) == -1)
        exit(84);
    return (fd);
}

int simple_left(red_t red, int i)
{
    int fd = open(red.files[i], O_RDONLY);

    if (fd == -1) {
        print("%s: %s.\n", red.files[i], strerror(errno));
        return (-1);
    }
    if (dup2(fd, 0) == -1)
        exit(84);
    return (fd);
}

int double_right(red_t red, int i)
{
    int fd = open(red.files[i], O_WRONLY | O_CREAT | O_APPEND,
    S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);

    if (fd == -1) {
        print("%s: %s.\n", red.files[i], strerror(errno));
        return (-1);
    }
    if (dup2(fd, 1) == -1)
        exit(84);
    return (fd);
}