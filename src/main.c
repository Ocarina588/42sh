/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** main.c
*/

#include "my.h"
#include "minishell.h"

int exe_command(options_t *opt)
{
    int exit = 0;
    opt->redirect.nb = NULL;

    exit = loop_sep(opt);
    if (exit == -2)
        return (exit);
    return (1);
}

int in_loop(options_t *opt, int exit)
{
    if (get_line(opt))
        return (0);
    opt->alias.echo_value = opt->exit_v;
    opt->exit_v = 0;
    if (set_command(opt))
        return (1);
    exit = exe_command(opt);
    if (exit == -2)
        return (-2);
    if (opt->exit_v == 84)
        return (0);
    return (1);
}

int loop(options_t *opt)
{
    int exit = 0;

    while (1) {
        exit = in_loop(opt, exit);
        if (!exit)
            return (0);
        else if (exit == -2)
            return (-2);
    }
    return (0);
}

int minishell(int ac, char **av __attribute__((unused)), char **env)
{
    options_t *opt = malloc(sizeof(options_t));
    int a = 0;

    get_opt(1, opt);
    if (!opt)
        return (84);
    opt->getlines = set_read();
    opt->alias = init_alias();
    opt->history = init_history();
    opt->redirect.files = NULL;
    opt->com.tab = NULL;
    opt->exit_v = 0;
    signal(2, signal_handler);
    if (ac != 1 || setenvi(env, opt) == 84)
        return (84);
    a = loop(opt);
    if (a == -2)
        return (opt->getlines.my_exit);
    a = opt->exit_v;
    free_opt(opt);
    return (a);
}

int main(int ac, char **av, char **env)
{
    int z = minishell(ac, av, env);

    if (z == 84)
        print("Erreur lors de malloc dynamique\n");
    return (z);
}