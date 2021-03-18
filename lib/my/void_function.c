/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** void_function.c
*/

#include <stdarg.h>
#include "my.h"

void print_char(va_list ap)
{
    my_putchar((char)va_arg(ap, int));
}

void print_str(va_list ap)
{
    char *str = va_arg(ap, char *);
    if (!str)
        my_putstr("(null)");
    else
        my_putstr(str);
}

void print_nb(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
}

void print_hexa(va_list ap)
{
    convert_to_hexa(va_arg(ap, long int));
}

void print_octal(va_list ap)
{
    convert_to_octal(va_arg(ap, unsigned int));
}