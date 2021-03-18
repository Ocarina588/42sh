/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** parse_pipe.c
*/

#include "my.h"
#include "minishell.h"

void fill_command(options_t *opt, char **s)
{
    int a = 0;
    int i = 0;
    const char *r[] = {"|", NULL};

    opt->pcoma.command = set_functions(s, r);
    opt->pcoma.exe = malloc(sizeof(char *) * (opt->pcoma.nb_pipe + 2));
    opt->pcoma.red_pipe = malloc(sizeof(red_t) * (opt->pcoma.nb_pipe + 1));
    if (!opt->pcoma.exe || !opt->pcoma.red_pipe)
        exit(84);
    for (i = 0; opt->pcoma.command[i] ; i++, a++) {
        if (nb_red(opt->pcoma.command[i])) {
            opt->pcoma.red_pipe[a]
            = set_redirect(opt->pcoma.red_pipe[a], opt->pcoma.command[i]);
            opt->pcoma.command[i] = modifcmd(opt->pcoma.command[i]);
        } else {
            opt->pcoma.red_pipe[a].files = NULL;
            opt->pcoma.red_pipe[a].nb = NULL;
        }
    }
}