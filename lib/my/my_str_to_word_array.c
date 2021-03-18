/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** alizee.soussan@epitech.eu
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int alphanum_char(char c, char x)
{
    if (c != x && c != '\0' && c != '\n' && c != '\t')
        return (1);
    else
        return (0);
}

int nb_words(char const *str, char x)
{
    int nb = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (alphanum_char(str[i], x) == 1 &&
        alphanum_char(str[i + 1], x) == 0)
            nb++;
        i++;
    }
    return (nb);
}

int nbr_letter(char const *str, int i, char x)
{
    int k;

    for (k = 0; str[k] != '\0'; k++)
        if (alphanum_char(str[k + i], x) == 0)
            return (k);
    return (k);
}

char *malloc_tab(char *str, int nb_letter)
{
    str = malloc(sizeof(char) * (nb_letter + 1));
    if (str == NULL)
        exit(84);
    return (str);
}

char **my_str_to_word_array(char const *str, char charact)
{
    int nbr_word = nb_words(str, charact);
    int nb_letter = 0;
    char **tab = malloc(sizeof(char *) * (nbr_word + 1));
    int i = 0;
    int j = 0;

    if (tab == NULL)
        exit(84);
    for (i = 0; i < nbr_word; i++) {
        while (alphanum_char(str[j], charact) == 0)
            j++;
        nb_letter = nbr_letter(str, j, charact);
        tab[i] = malloc_tab(tab[i], nb_letter);
        for (int k = 0; k < nb_letter; k++)
            tab[i][k] = str[j + k];
        tab[i][nb_letter] = '\0';
        j += nb_letter;
    }
    tab[nbr_word] = NULL;
    return (tab);
}
