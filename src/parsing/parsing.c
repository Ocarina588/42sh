/*
** EPITECH PROJECT, 2020
** parsing
** File description:
** sdf
*/

#include "my.h"
#include "minishell.h"
#include <stdlib.h>

void delete(char *str)
{
    for (int i = 0; str[i] ; i++)
        str[i] = str[i + 1];
}

int find_new_word(char **str)
{
    for (int i = 0; (*str)[i] ; i++) {
        if ((*str)[i] != ' ' && (*str)[i] != '\t' && (*str)[i] != '\n') {
            *str = *str + i;
            return (1);
        }
    }
    return (0);
}

int delete_anti(char *str, int *i)
{
    if (str[*i] == '\\') {
        *i += str[*i + 1] ? 2 : 1;
        return (1);
    }
    return (0);
}

int find_end(char *str, int rep)
{
    char c = 0;
    int i = 0;

    for (; str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n'; i++) {
        rep = delete_anti(str, &i);
        if (!str[i])
            break;
        if (str[i] != '\'' && str[i] != '\"') {
            rep ? i-- : 0;
            continue;
        }
        c = str[i++];
        for (; str[i] != c && str[i]; i++);
        if (!str[i++] && dprint(2, "Unmatched '%c'.\n", c))
            return (-(get_opt(0, NULL)->exit_v = 1));
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == 0)
            return (i);
        i--;
    }
    return (i);
}

char **first_parsing(char *input, int *ret)
{
    char *str = my_strdup(input);
    char *tmp = str;
    char **av = NULL;
    int len = 0;
    int i = 0;

    if (!str || (*ret = func_pars_two(&len, &i, &str, tmp))) {
        free(input);
        return (NULL);
    }
    if (!(av = malloc(sizeof(char *) * (len + 1))))
        exit (84);
    func_pars(&i, &input, av);
    av[len] = NULL;
    free(tmp);
    if (!av || !*av) {
        return (NULL);
    }
    return (av);
}