/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** set_bis.c
*/

#include "my.h"
#include "minishell.h"

int check_var(options_t *opt, char *s2, int j)
{
    int i = 0;

    for (int i = 0; s2[i] != '=' && 
    opt->history.set[j][i] != '\t' && opt->history.set[j][i] != '\0'; i++)
        if (opt->history.set[j][i] != s2[i])
            return (0);
    opt->history.set[j] = malloc(sizeof(char) * my_strlen(s2) + 1);
    for (i = 0; s2[i] != '\0'; i++) {
        if (s2[i] == '=')
            opt->history.set[j][i] = '\t';
        else
            opt->history.set[j][i] = s2[i];
    }
    opt->history.set[j][i] = '\0';
    return (1);
}

char *special_var(options_t *opt, char *var, char *cmd, int z)
{
    char *new = NULL;
    if (!my_strcmp(var, "?")) {
        new = malloc(sizeof(char) * my_strlen(cmd)
            + my_strlen(nbstr(opt->alias.echo_value) + 1));
        if (new == NULL)
            exit(84);
        new = my_strncpy(new, cmd, z);
        new = my_strcat(new, nbstr(opt->alias.echo_value));
        return (new);
    }
    if (!my_strcmp(var, "$")) {
        new = malloc(sizeof(char) * my_strlen(cmd)
            + my_strlen(opt->alias.pid) + 1);
        if (new == NULL)
            exit(84);
        new = my_strncpy(new, cmd, z);
        new = my_strcat(new, opt->alias.pid);
        return (new);
    }
    return (NULL);
}

char *find_set_var(char *tab, char *s)
{
    int i = 0;
    int j = 0;
    char *new = malloc(sizeof(char) * my_strlen(tab) + 1);
    for (i = 0; tab[i] != '\t'; i++) {
        if (tab[i] != '\0' && tab[i] != s[i])
            return (NULL);
    }
    for (i = i + 1; tab[i] != '\0'; i++)
        new[j++] = tab[i];
    new[j] = '\0';
    return (new);
}

int loop_sep(options_t *opt)
{
    int exit = 0;

    for (int i = 0; opt->parsing.cmd[i]; i++) {
        exit = var_interpreter(opt->parsing.cmd[i], opt);
        if (exit == 1) {
            opt->exit_v = 1;
            return (1);
        }
        if (!(opt->parsing.cmd[i][0]))
            continue;
        if (i > 0 && opt->parsing.sep_val[i - 1] == 2 && opt->exit_v == 0)
            continue;
        if (i > 0 && opt->parsing.sep_val[i - 1] == 3 && opt->exit_v != 0)
            continue;
        exit = built_in(opt->parsing.cmd[i], opt);
        free_intermediate(opt);
    }
    return (exit);
}

char *get_var(char **tab, char *s)
{
    char *str = NULL;
    if (!tab)
        return (NULL);
    for (int i = 0; tab[i]; i++) {
        str = find_set_var(tab[i], s);
        if (str)
            return (str);
    }
    return (NULL);
}