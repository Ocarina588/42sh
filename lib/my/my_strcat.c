/*
** EPITECH PROJECT, 2019
** my_strcat.c
** File description:
** task02
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

char *my_strcatrealloc(char *src, char *dest)
{
    int j = 0;
    int i = 0;
    char *res;

    for (i; dest[i]; i++);
    for (j; src[j]; j++);
    res = malloc(sizeof(char) * (i + j + 1));
    if (res == NULL)
        exit(84);
    res[0] = '\0';
    for (int x = 0; src[x]; x++)
        res[x] = src[x];
    for (int x = 0; dest[x]; x++)
        res[x + j] = dest[x];
    res[i + j] = '\0';
    return (res);
}

char *my_strcat(char *dest, char const *src)
{
    int len = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[len+i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
    return (dest);
}