/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** interpreter_var.c
*/

#include "my.h"
#include "minishell.h"

char *nbstr(int nb)
{
    char one[32];
    static char two[10];
    int tmp = nb;

    for (int i = 0; i < nb_len(nb) ; i++) {
        one[i] = tmp % 10;
        tmp /= 10;
    }
    for (int i = 0, j = nb_len(nb) - 1; i < nb_len(nb) ; i++, j--)
        two[i] = one[j] + '0';
    two[nb_len(nb)] = 0;
    return (two);
}

char *change_var_next(int z, char *var, char *cmd, options_t *opt)
{
    char *new = NULL;
    new = special_var(opt, var, cmd, z);
    if (new)
        return (new);
    if (get_variable(&opt->envi, var)) {
        new = malloc(sizeof(char) * my_strlen(cmd)
            + my_strlen(get_variable(&opt->envi, var)) + 1);
        if (new == NULL)
            exit(84);
        new = my_strncpy(new, cmd, z);
        new = my_strcat(new, get_variable(&opt->envi, var));
    } else if (get_var(opt->history.set, var)) {
        new = malloc(sizeof(char) * my_strlen(cmd)
            + my_strlen(get_var(opt->history.set, var) + 1));
        if (new == NULL)
            exit(84);
        new = my_strncpy(new, cmd, z);
        new = my_strcat(new, get_var(opt->history.set, var));
    }
    return (new);
}

char *change_var(options_t *opt, int *i, char *cmd)
{
    char *var = malloc(sizeof(char) * my_strlen(cmd) + 1);
    int j = 0;
    int z = *i;
    char *new = NULL;

    if (!var)
        exit(84);
    for (*i = (*i) + 1; cmd[*i] != ' ' && cmd[*i] != '\t' && cmd[*i] != '\n'
        && cmd[*i] != '\0' && cmd[*i] != '\"'; (*i)++) {
        if (*i != z + 1 && cmd[*i] == '$')
            break;
        var[j++] = cmd[*i];
    }
    var[j] = '\0';
    new = change_var_next(z, var, cmd, opt);
    return (new);
}

int check_what_var(char **cmd, int j, int *i, options_t *opt)
{
    char *check = NULL;

    if (cmd[j][*i] == '$' && cmd[j][(*i) + 1] != ' ' &&
        cmd[j][(*i) + 1] != '\t' && cmd[j][(*i) + 1] != '\n'
            && cmd[j][(*i) + 1] != '\0') {
        if (*i != 0 && cmd[j][(*i) - 1] == '\\')
            return (0);
        else {
            check = change_var(opt, i, cmd[j]);
            check = my_strcat(check, cmd[j] + (*i));
            if (my_strcmp(check, cmd[j]))
                *i = 0;
            cmd[j] = my_strdup(check);
        }
    }
}

int var_interpreter(char **cmd, options_t *opt)
{
    if (check_error(cmd, opt))
        return (1);
    for (int j = 0; cmd[j]; j++) {
        for (int i = 0; cmd[j][i]; i++) {
            if (cmd[j][i] == '\'') {
                for (i = i + 1; cmd[j][i] != '\0' && cmd[j][i] != '\''; i++);
                if (cmd[j][i] == '\0')
                    i--;
                continue;
            }
            check_what_var(cmd, j, &i, opt);
        }
    }
    return (0);
}