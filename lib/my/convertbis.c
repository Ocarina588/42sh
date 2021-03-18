/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** convertbis.c
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

void convert_to_hexa_p(long int result)
{
    char tab[] = "0123456789abcdef";
    long int *stack = malloc(sizeof(long int) * (lenght(result) + 2));
    int i = 0;

    if (!stack)
        exit(84);
    my_put_nbr(0);
    my_putchar('x');
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

void print_octalbis(int i, int *stack)
{
    int *tab = malloc(sizeof(unsigned int) * 4);

    if (!tab)
        exit(84);
    tab[0] = 0;
    tab[1] = 0;
    for (int j = 0; j <= 2; i--) {
        if (i == 1)
            tab[j+1] = stack[i];
        else if (i == 0 && j == 1)
            tab[j+1] = stack[i];
        else
            tab[j+2] = stack[i];
        my_put_unsignednbr(tab[j]);
        j++;
    }
}

void convert_to_octal_bis(unsigned int result)
{
    int i = 0;
    int *stack = malloc(sizeof(unsigned int) * (lenght(result) + 2));
    int *tab = malloc(sizeof(unsigned int) * 4);

    if (!stack || !tab)
        exit(84);
    tab[0] = 0;
    tab[1] = 0;
    while (1) {
        stack[i] = result % 8;
        result = result / 8;
        if (result == 0)
            break;
        i++;
    }
    print_octalbis(i, stack);
    free(stack);
}

void print_char_non_printable(char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 0 && str[i] <= 31) {
            my_putchar(92);
            convert_to_octal_bis(str[i]);
            count = 1;
        }
        if (count == 1)
            my_putchar(str[i + 1]);
        else
            my_putchar(str[i]);
    }
}

void print_big_s(va_list ap)
{
    print_char_non_printable(va_arg(ap, char *));
}