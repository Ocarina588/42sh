/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** fprintf.c
*/

#include "my.h"

int change_status(int a, int fd)
{
    static int file = 1;
    if (a == 1)
        file = fd;
    if (a == 0)
        return (file);
}

int dprint(int fd, char *str, ...)
{
    change_status(1, fd);
    va_list ap;
    va_start(ap, str);

    for (int i = 0;str[i] != '\0'; i += 0) {
        if ((str[i] == '%') && (check_space(str, i) == 1)) {
            check_if_space_or_not(str, i);
            for (i = i; str[i+1] == ' '; i++);
            function_pointers(str[i+1], ap);
            i = i + 2;
        } else if ((str[i] == '%') && (check_space(str, i)) == -1) {
            my_putchar(str[i]);
            i = if_fonction(str, i);
            i++;
        } else {
            my_putchar(str[i]);
            i++;
        }
    } va_end(ap);
    change_status(1, 1);
    return (1);
}