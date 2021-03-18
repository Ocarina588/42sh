/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** convert.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

int lenght(long int nb)
{
    int size = 0;

    while (1) {
        nb = nb / 2;
        size++;
        if (nb < 1)
            return (size);
    }
}

void convert_to_hexa(unsigned int result)
{
    char tab[] = "0123456789abcdef";
    unsigned int *stack = (unsigned int *)(sizeof(unsigned int)
    * (lenght(result) + 2));
    int i = 0;

    while (1) {
        stack[i] = result % 16;
        result = result / 16;
        if (result == 0)
            break;
        i++;
    }
    for (i = i; i >= 0; i--)
        my_putchar(tab[stack[i]]);
    free(stack);
}

void convert_to_hexa_up(unsigned int result)
{
    char tab[] = "0123456789ABCDEF";
    unsigned int *stack = (unsigned int *)(sizeof(unsigned int)
    * (lenght(result) + 2));
    int i = 0;

    while (1) {
        stack[i] = result % 16;
        result = result / 16;
        if (result == 0)
            break;
        i++;
    }
    for (i = i; i >= 0; i--)
        my_putchar(tab[stack[i]]);
    free(stack);
}

void convert_to_binary(unsigned int result)
{
    int i;
    unsigned int *stack = (unsigned int *)(sizeof(unsigned int)
    * (lenght(result) + 2));

    while (1) {
        stack[i] = result % 2;
        result = result / 2;
        if (result == 0)
            break;
        i++;
    }
    for (i = i-1; i >= 0; i--)
        my_put_unsignednbr(stack[i]);
    free(stack);
}

void convert_to_octal(unsigned int result)
{
    int i = 0;
    unsigned int *stack = (unsigned int *)(sizeof(unsigned int)
    * (lenght(result) + 2));

    while (1) {
        stack[i] = result % 8;
        result = result / 8;
        if (result == 0)
            break;
        i++;
    }
    for (i = i; i >= 0; i--)
        my_put_unsignednbr(stack[i]);
    free(stack);
}