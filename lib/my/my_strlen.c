/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** lenstr
*/

int my_strlen(char *str)
{
    int size = 0;

    while (str[size] != '\0')
        size++;
    return (size);
}
