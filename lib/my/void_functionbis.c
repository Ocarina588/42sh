/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** void_functionbis.c
*/

#include <stdarg.h>
#include "my.h"

void print_hexa_up(va_list ap)
{
    convert_to_hexa_up(va_arg(ap, int));
}

void print_binary(va_list ap)
{
    convert_to_binary(va_arg(ap, int));
}

void print_pourcent(va_list ap)
{
    print_pourcent_char('%');
}

void print_unsignednbr(va_list ap)
{
    my_put_unsignednbr(va_arg(ap, unsigned int));
}

void print_adress_p(va_list ap)
{
    convert_to_hexa_p(va_arg(ap, long int));
}