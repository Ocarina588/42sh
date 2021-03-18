/*
** EPITECH PROJECT, 2019
** my_strcpy.c
** File description:
** task 01
*/

char *my_strcpy(char *dest, char const *src)
{
    int r = 0;

    while (src[r] != '\0') {
        dest[r] = src[r];
        r++;
    }
    dest[r] = '\0';
    return (dest);
}
