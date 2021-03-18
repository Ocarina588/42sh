/*
** EPITECH PROJECT, 2019
** my_compute_power_rec.c*
** File description:
** compute power rec
*/

#include "my.h"

int lenghtbis(unsigned int nb)
{
    int size = 0;

    while (1) {
        nb = nb / 2;
        size++;
        if (nb < 1)
            return (size);
    }
}

void print_pourcent_char(char sign)
{
    if (sign == '%')
        my_putchar(sign);
}

void print_withoutpourcent_char(char sign)
{
    if (sign != '%')
        my_putchar(sign);
}