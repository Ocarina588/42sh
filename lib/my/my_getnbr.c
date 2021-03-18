/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** count number of char in a string
*/

#include "my.h"

int my_getnbr(char *str)
{
    int isneg = 1;
    int nb = 0;
    int i = 0;
    int past_number = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            isneg = isneg * -1;
        i = i + 1;
    }
    while (str[i] != '\0' && str[i] != '\n') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
            past_number = 1;
        } else if (past_number) {
            return (nb * isneg);
        }
        i++;
    }
    return (nb * isneg);
}
