/*
** EPITECH PROJECT, 2019
** my_putchar.c
** File description:
** my_putchar
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char c)
{
    write(change_status(0, 0), &c , 1);
}
