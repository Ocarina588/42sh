/*
** EPITECH PROJECT, 2020
** function bis
** File description:
** sdf
*/

#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"
#include "my.h"

void clean_loop_next(char **functions, int i, int j, int rep_quotes)
{
    if (!rep_quotes && functions[i][j] == '\\')
        removeb(functions[i] + j);
    if (rep_quotes && functions[i][j] == '\\'
    && functions[i][j + 1] == '\n') {
        removeb(functions[i] + j);
    }
}

void clean_function_loop(char **functions, int i)
{
    char c = 0;
    int rep_quotes = 0;

    for (int j = 0; functions[i][j] ; j++) {
        if (!rep_quotes && (functions[i][j] == '\''
        || functions[i][j] == '"')) {
            rep_quotes ^= 1;
            c = functions[i][j];
            removeb(functions[i] + j--);
            continue;
        } else if (rep_quotes && functions[i][j] == c) {
            rep_quotes ^= 1;
            removeb(functions[i] + j--);
            continue;
        }
        clean_loop_next(functions, i, j, rep_quotes);
    }
}

int check_error_functions(int *rep, int *len, char ***functions)
{
    for (int i = 0; functions[i] && *functions[i]; i++, (*len)++) {
        if (check_error_function(functions[i])) {
            *rep = 1;
            free(functions);
            return (1);
        }
    }
    return (0);
}

int find_pipe(char **tab, int way, int i)
{
    for (; way && tab[i] ; i++)
        if (!my_strcmp(tab[i], "|"))
            return (1);
    for (; !way && i >= 0 ; i--)
        if (!my_strcmp(tab[i], "|"))
            return (1);
    return (0);
}