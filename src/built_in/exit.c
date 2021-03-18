/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** exit.c
*/

#include "my.h"
#include "minishell.h"

int checkexit(char **tab)
{
    int z = 0;
    int w = 0;

    for (int j = 0; tab[1][j]; j++)
        if (tab[1][j] < '0' || tab[1][j] > '9')
            z = 1;
        else
            w = 1;
    if ((z && !w) || ((tab[1][0] < '0' || tab[1][0] > '9')
    && tab[1][0] != '-'))
        dprint(2, "exit: Expression Syntax.\n");
    else if ((z && w) && tab[1][0] != '-')
        dprint(2, "exit: Badly formed number.\n");
    else
        return (0);
    return (1);
}

int new_exit(char **tab)
{
    int i = 0;

    for (i = 0; tab[i]; i++);
    if (i == 2) {
        if (checkexit(tab))
            return (1);
        if (isatty(0))
            print("exit\n");
        return (atoi(tab[1]));
    } else if (i > 2) {
        dprint(2, "exit: Expression Syntax.\n");
        return (1);
    } else {
        if (isatty(0))
            print("exit\n");
        return (0);
    }
    return (0);
}

int my_exit(options_t *opt, char **tab)
{
    char **cmd = copy_tab(tab);

    clean_function(cmd);
    opt->getlines.my_exit = new_exit(cmd);
    if (opt->getlines.my_exit < 0)
        opt->getlines.my_exit = 256 + (opt->getlines.my_exit);
    free_intermediate(opt);
    free_2darray(cmd);
    return (-2);
}

char *my_new_str(char **tab, char *str, char *newstr, int i)
{
    str = my_strdup(tab[1]);
    newstr = malloc(sizeof(char) * my_strlen(tab[1]) + 2);
    if (!str || !newstr)
        return (NULL);
    newstr = my_strcpy(newstr, str);
    newstr = my_strcat(newstr, "=");
    if (i != 2) {
        free(str);
        str = malloc(sizeof(char) * my_strlen(tab[2]) + my_strlen(tab[1]) + 2);
        if (!str)
            return (NULL);
        str = my_strcpy(str, newstr);
        str = my_strcat(str, tab[2]);
        free(newstr);
        return (str);
    }
    free(str);
    return (newstr);
}

int my_child_red(options_t *opt, char *exe)
{
    int pid = 0;
    int fd = 0;
    int (*red[4])(red_t, int) =
    {double_right, simple_right, double_left, simple_left};

    pid = fork();
    if (pid  == 0) {
        for (int i = 0; opt->redirect.nb[i] != -1; i++)
            if ((fd = red[opt->redirect.nb[i] - 1](opt->redirect, i)) == -1)
                exit(1);
        execve(exe, opt->com.tab, opt->com.my_env);
        dprint(2, "%s: %s.%s\n", opt->com.tab[0], strerror(errno),
        !my_strcmp(strerror(errno),
        "Exec format error") ? " Wrong Architecture." : "");
        exit(1);
    }
    return (pid);
}