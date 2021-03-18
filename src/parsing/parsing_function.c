/*
** EPITECH PROJECT, 2020
** parsing function
** File description:
** sdf
*/

#include <stdlib.h>
#include "minishell.h"
#include "my.h"

int len_2d(char **tab)
{
    int len = -1;
    if (!tab)
        return (0);
    while (tab[++len]);
    return (len);
}

void free_2d_len(char **tab, int len)
{
    if (!tab)
        return;
    for (int i = 0; i < len ; i++) {
        print("free %s\n", tab[i]);
        free(tab[i]);
    }
    free(tab);
}

void free_list(parsing_t *head)
{
    if (head->next)
        free_list(head->next);
    free(head);
}

char **list_to_array(parsing_t *head)
{
    char **tab = NULL;
    int len = 0;
    parsing_t *tmp = head;

    while (tmp && ++len)
        tmp = tmp->next;
    tab = malloc(sizeof(char *) * (len + 1));
    if (!tab)
        exit(84);
    tab[len] = NULL;
    tmp = head;
    for (int i = 0; i < len ; i++) {
        tab[i] = my_strdup(tmp->val);
        tmp = tmp->next;
    }
    free_list(head);
    return (tab);
}

char **parsing_2(char **tab)
{
    parsing_t *head = NULL;

    for (int i = 0; tab[i] ; i++)
        find(&head, tab[i]);
    return (list_to_array(head));
}