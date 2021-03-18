/*
** EPITECH PROJECT, 2019
** my_printf.c
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdio.h>
#include "my.h"
#include <stdlib.h>

int compare_tab(char letter, char *tab)
{
    for (int index = 0; tab[index] != 0; index++) {
        if (tab[index] == letter)
            return (index);
    }
    return (-1);
}

int function_pointers(char c, va_list ap)
{
    char tab[] = "csdixoXbupS%";
    int index;
    void (*func[13])(va_list) = {print_char, print_str,
    print_nb, print_nb, print_hexa,
    print_octal, print_hexa_up,
    print_binary, print_unsignednbr, print_adress_p,
    print_big_s, print_pourcent};

    index = compare_tab(c, tab);
    if (compare_tab(c, tab) == -1)
        return (0);
    func[index](ap);
    return (1);
}

int check_space(char *str, int i)
{
    char tab[] = "csdixoXbupS%";
    for (i = i; str[i+1] == ' '; i++);

    if (compare_tab(str[i+1], tab) == -1)
        return (-1);
    else
        return (1);
}

int if_fonction(char *str, int i)
{
    if (str[i+1] == ' ') {
        for (i = i; str[i+1] == ' '; i++);
        my_putchar(str[i]);
        return (i);
    }
    return (i);
}

int print(char *str, ...)
{
    va_list ap;
    va_start(ap, str);
    for (int i = 0;str[i] != '\0'; i += 0) {
        if ((str[i] == '%') && (check_space(str, i) == 1)) {
            check_if_space_or_not(str, i);
            for (i = i; str[i+1] == ' '; i++);
            function_pointers(str[i+1], ap);
            i = i + 2;
        } else if ((str[i] == '%') && (check_space(str, i)) == -1) {
            my_putchar(str[i]);
            i = if_fonction(str, i);
            i++;
        } else {
            my_putchar(str[i]);
            i++;
        }
    } va_end(ap);
    return (1);
}