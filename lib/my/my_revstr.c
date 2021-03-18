/*
** EPITECH PROJECT, 2019
** my_revstr.c
** File description:
** task03
*/

#include <stdarg.h>
#include "my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int k = 0;

    while (str[k] != '\0')
        k++;
    k--;

    while ( i < k) {
        char temp = str[i];

        str[i] = str[k];
        str[k] = temp;

        i++;
        k--;
    }
    return (str);
}

int sum_stdarg(int i, int nb, ...)
{
    va_list ap;
    va_start(ap, nb);
    int res = 0;

    if (i == 0) {
        for (int b = 0; b < nb; b++)
            res = va_arg(ap, int) + res;
    }
    if (i == 1) {
        for (int b = 0; b < nb; b++)
            res = my_strlen(va_arg(ap, char *)) + res;
    }
    va_end(ap);
    return (res);
}
