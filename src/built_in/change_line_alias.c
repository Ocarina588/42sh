/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** change_line_alias
*/

#include "my.h"
#include "minishell.h"

char *change_value_w(char *all, char *new, int skip, char **tab)
{
    new = malloc(sizeof(char) * (my_strlen(all) + skip + 1));
    if (!new)
        exit(84);
    new = my_strcpy(new, tab[1]);
    new[skip - 1] = '\t';
    for (int i = 0; all[i]; i++)
        new[i + skip] = all[i];
    new[my_strlen(all) + skip] = '\0';
    return (new);
}

char *change_value_parent(char *all, char *new, int skip, char **tab)
{
    new = malloc(sizeof(char) * (my_strlen(all) + skip + 3));
    if (!new)
        exit(84);
    new = my_strcpy(new, tab[1]);
    new[skip - 1] = '\t';
    new[skip] = '(';
    for (int i = 0; all[i]; i++)
        new[i + skip + 1] = all[i];
    new[my_strlen(all) + skip + 1] = ')';
    new[my_strlen(all) + skip + 2] = '\0';
    return (new);
}

void change_alias(char **tab, options_t *opt, int line, int skip)
{
    char *all = "\0";
    char *new;
    int check = is_quote(tab);

    for (int i = 2; tab[i]; i++) {
        i != 2 ? all = my_strcatrealloc(all, " ") : 0;
        all = my_strcatrealloc(all, tab[i]);
    }
    if (check == 0 && tab[3] != NULL)
        new = change_value_parent(all, new, skip, tab);
    else
        new = change_value_w(all, new, skip, tab);
    free(opt->alias.alias[line]);
    opt->alias.alias[line] = my_strdup(new);
    free(new);
}