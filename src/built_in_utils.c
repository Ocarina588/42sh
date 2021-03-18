/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** built_in_bis
*/

#include "my.h"
#include "minishell.h"

int check_tab(char *str)
{
    for (int i = 1; str[i]; i++)
        if (!my_char_isalphanum(str[i]))
            return (1);
    return (0);
}

int find_index(char **func, char *tab)
{
    for (int i = 0; func[i]; i++)
        if (!my_strcmp(func[i], tab))
            return (i);
    return (-1);
}