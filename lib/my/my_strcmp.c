/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** task06
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int c = 0;

    while (s1[i] != '\0') {
        if (s1[i] == s2[c]) {
            i++;
            c++;
        }
        if (s1[i] != s2[c]) {
            return (s1[i] - s2[c]);
        }
    }
    return (0);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int c = 0;

    while (s1[i] != '\0' && s2[c] != '\0') {
        if (s1[i] == s2[c]) {
            i++;
            c++;
        }
        if (c == n)
            break;
        if (s1[i] != s2[c]) {
            return (s1[i] - s2[c]);
        }
    }
    return (0);
}