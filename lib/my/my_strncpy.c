/*
** EPITECH PROJECT, 2019
** my_strncpy.c
** File description:
** task02
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i = 0; i != n; i++) {
        dest[i] = src[i];
        if (src[i] == '\0')
            break;
    }
    dest[i] = '\0';
    return (dest);
}
