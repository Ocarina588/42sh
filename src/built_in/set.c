/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** set.c
*/

#include "my.h"
#include "minishell.h"

void print_set(char **tab)
{
    if (!tab)
        return;
    for (int i = 0; tab[i]; i++)
        print("%s\n", tab[i]);
}

int replace_var(options_t *opt, char *s)
{
    if (!opt->history.set)
        return (0);
    for (int i = 0; opt->history.set[i]; i++)
        if (check_var(opt, s, i))
            return (1);
    return (0);
}

void add_line(options_t *opt, char *s)
{
    if (replace_var(opt, s))
        return;
    char **tab = copy_tab(opt->history.set);
    int i = 0;
    int j = 0;
    opt->history.set = malloc(sizeof(char *) * (len_tab(opt->history.set) + 2));
    for (i = 0; tab[i]; i++)
        opt->history.set[i] = my_strdup(tab[i]);
    opt->history.set[i] = malloc(sizeof(char) * my_strlen(s) + 2);
    for (j = 0; s[j] != '\0'; j++) {
        if (s[j] == '=')
            opt->history.set[i][j] = '\t';
        else
            opt->history.set[i][j] = s[j];
    }
    opt->history.set[i][j] = '\0';
    opt->history.set[++i] = NULL;
}

int add_set_var(options_t *opt, char **tab)
{
    for (int i = 1; tab[i]; i++) {
        add_line(opt, tab[i]);
    }
}

int set(env_t **env, char **cmd, options_t *opt)
{
    char **tab = copy_tab(cmd);
    clean_function(tab);
    int i = 0;

    for (i = 0; tab[i]; i++);
    if (i == 1)
        print_set(opt->history.set);
    else
        add_set_var(opt, cmd);
}