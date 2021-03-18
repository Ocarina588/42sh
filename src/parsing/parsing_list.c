/*
** EPITECH PROJECT, 2020
** parsing redi
** File description:
** sdf
*/

#include <stdlib.h>
#include "my.h"
#include "minishell.h"

char const *com[] = {"<<", ">>", "<", ">", ";", "||", "&&", "|", NULL};

parsing_t *new_node(char const *s)
{
    parsing_t *var = malloc(sizeof(parsing_t));

    if (!var)
        exit(84);
    var->val = s;
    var->next = NULL;
    return (var);
}

void push_node(parsing_t *node, parsing_t **head)
{
    parsing_t *tmp = *head;

    if (!*head) {
        *head = node;
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = node;
}

int is_over(char *str, char const **r)
{
    for (int i = 0; r[i] ; i++)
        if (!my_strncmp(str, r[i], my_strlen(r[i])))
            return (i);
    return (-1);
}

int loop_find(char *str, int *i, parsing_t **head, int *rep)
{
    char c;
    int res;

    if (str[(*i)] == '\\' && ++(*i))
        return (0);
    res = is_over(str + (*i), com);
    if (res != -1) {
        for (int j = 0; j < my_strlen(com[res]) ; j++)
            str[(*i) + j] = 0;
        if (*i > 1 && str[*rep])
            push_node(new_node(str + (*rep)), head);
        push_node(new_node(com[res]), head);
        (*i) += my_strlen(com[res]) - 1;
        (*rep) = (*i) + 1;
        return (!str[(*rep)] ? 1 : 0);
    }
    if (str[(*i)] != '\'' && str[*i] != '\"')
        return (0);
    c = str[(*i)++];
    while (str[(*i)] && str[(*i)++] != c);
    return (0);
}

void find(parsing_t **head, char *str)
{
    int rep = 0;
    int len = my_strlen(str);

    for (int i = 0; i < len ; i++)
        if (loop_find(str, &i, head, &rep))
            return;
    if (str[rep])
        push_node(new_node(str + rep), head);
}