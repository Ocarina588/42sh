/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** echo_var_bis.c
*/

#include "my.h"
#include "minishell.h"

int print_error_next(char *var, char *cmd, options_t *opt, int *i)
{
    if (var[0] != '?' && var[0] != '#' &&
        !get_variable(&opt->envi, var) && !get_var(opt->history.set, var)) {
        dprint(2, "%s: Undefined variable.\n", var);
        return (1);
    }
    if (cmd[*i] == '\0' || cmd[*i] == '$')
        (*i)--;
    return (0);
}

int print_error(options_t *opt, int *i, char *cmd)
{
    char *var = malloc(sizeof(char) * my_strlen(cmd) + 1);
    int j = 0;

    if (!var)
        exit(84);
    for (*i = (*i) + 1; cmd[*i] != ' ' && cmd[*i] != '\t' && cmd[*i] != '\n'
        && cmd[*i] != '\0' && cmd[*i] != '$' && cmd[*i] != '\"'; (*i)++)
        var[j++] = cmd[*i];
    var[j] = '\0';
    if ((var[0] < 'A' || var[0] > 'Z')
        && (var[0] < 'a' || var[0] > 'z') && var[0] != '_'
            && var[0] != '#' &&  var[0] != '?') {
        dprint(2, "Illegal variable name.\n", var);
        return (1);
    }
    return (print_error_next(var, cmd, opt, i));
}

int check_echo_var(char **cmd, int *i, int j, options_t *opt)
{
    if (cmd[j][*i] == '$' && cmd[j][(*i) + 1] != ' ' &&
        cmd[j][(*i) + 1] != '\t' && cmd[j][(*i) + 1] != '\n' &&
        cmd[j][(*i) + 1] != '\0') {
        if (*i != 0 && cmd[j][(*i) - 1] == '\\');
        else if (print_error(opt, i, cmd[j]))
            return (1);
    }
    return (0);
}