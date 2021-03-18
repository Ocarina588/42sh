/*
** EPITECH PROJECT, 2019
** my_strncat.c
** File description:
** task03
*/

#include "my.h"

char *my_istrncat(char *dest, const char *src, int j, int n)
{
    int i = 0;
    int bite = 0;
    for (j = bite; j < n + bite && src[j] != '\0' ; j++) {
        dest[i] = src[j];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

void check_if_space_or_not(char *str, int i)
{
    int y;
    for (y = i; str[y+1] == ' '; y++);
    if (i != y )
        my_putchar(' ');
}
