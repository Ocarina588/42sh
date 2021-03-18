/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** task01
*/

#include <string.h>
#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *arr = malloc((my_strlen(src) + 1)  * sizeof(char));

    if (!arr)
        exit(84);
    arr = my_strcpy(arr, src);
    return (arr);
}
