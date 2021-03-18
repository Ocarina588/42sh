/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** utils_bis
*/

#include "my.h"
#include "minishell.h"

int check_builtin(char *str, int opt)
{
    char **tab = malloc(sizeof(char *) * 10);

    if (!tab)
        exit(84);
    tab = fill_builtin(tab);
    for (int i = 0; tab[i] != NULL; i++) {
        if (!my_strcmp(str, tab[i]) && opt == 0) {
            print("%s: shell built-in command.\n");
            free(tab);
            return (0);
        }
        else if (!my_strcmp(str, tab[i]) && opt == 1) {
            print("%s is a shell built-in\n");
            free(tab);
            return (0);
        }
    }
    free(tab);
    return (1);
}

char **copy_tab(char **tab)
{
    int lenght = len_tab(tab);
    char **new_tab = malloc(sizeof(char *) * (lenght + 1));

    if (!new_tab)
        exit(84);
    for (int i = 0; tab && tab[i]; i++)
        new_tab[i] = my_strdup(tab[i]);
    new_tab[lenght] = NULL;
    return (new_tab);
}

int check_slash(char *str)
{
    int res = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == '/')
            res++;
    return (res);
}

char *cut_str(char *str, int nb, char cut)
{
    char *res = NULL;
    int x = 0;
    int i = 0;
    int j = 0;
    int y = 0;

    for (i; x < nb; i++) {
        if (str[i] == cut)
            x++;
    }
    for (; str[i] != cut && str[i] != '\0'; i++, j++);
    res = malloc(sizeof(char) * (j + 1));
    if (!res)
        exit(84);
    for (i = i - j; str[i] != cut && str[i] != '\0'; y++, i++)
        res[y] = str[i];
    res[y] = '\0';
    return (res);
}

char *get_alias(char *alias)
{
    char *res = NULL;
    int j = 0;
    int x = 0;

    for (j; alias[j - 1] != '\t'; j++);
    for (x = j; alias[x] != '\0'; x++)
    res = malloc(sizeof(char) * (x + 1));
    if (!res)
        exit(84);
    for (x = 0; alias[j] != '\0'; j++, x++) {
        if (alias[j] == '(' || alias[j] == ')')
            x--;
        else
            res[x] = alias[j];
    }
    res[x] = '\0';
    return (res);
}