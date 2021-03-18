/*
** EPITECH PROJECT, 2019
** my_char_isalphanum.c
** File description:
** lib
*/

int my_char_isalphanum(char str)
{
    if ((str >= 'a' && str <= 'z') || (str >= 'A' && str <= 'Z')
        || (str >= '0' && str <= '9') || str == '_' || str == '.'
        || str == ')' || str == '(' || str == '-' || str == '/')
        return (1);
    return (0);
}