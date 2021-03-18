/*
** EPITECH PROJECT, 2020
** line
** File description:
** sdf
*/

#include <stdlib.h>
#include "my.h"
#include "minishell.h"

line_t init_line(void)
{
    line_t line;

    line.pos = 0;
    line.str = my_strdup("");
    line.pos_history = len_2d(get_opt(0, NULL)->history.history);
    if (!line.str)
        exit(84);
    return (line);
}

void insert(line_t *line, char c)
{
    char *s = malloc(sizeof(char) * (my_strlen(line->str) + 2));

    if (!s)
        exit(84);
    my_strcpy(s, line->str);
    s[my_strlen(s)] = 0;
    s[my_strlen(s) + 1] = 0;
    for (int i = my_strlen(line->str); i > line->pos ; i--)
        s[i] = s[i - 1];
    s[line->pos] = c;
    line->pos++;
    line->pos_history = len_2d(get_opt(0, NULL)->history.history);
    line->str = s;
}

void last_n(line_t *line)
{
    if (line->pos == my_strlen(line->str))
        insert(line, '\n');
}

void choose_key(char c, line_t *line)
{
    static char tab[5] = {97, 97, 97, 97, 0};
    shift(tab);
    tab[3] = c;
    manage_special_key(line, tab, c);
    if (c == '\t' || c == 27 || c == 127 || tab[2] == 27 ||
        (tab[1] == 27 && tab[2] == 91)
        || (tab[0] == 27 && tab[1] == 91 && tab[2] == 51))
        return;
    insert(line, c);
}

int my_getline(char **s)
{
    line_t line = init_line();
    int last_len = 0;
    char c = 0;
    get_line_p(1, &line);
    while (c != 4 && c != '\n') {
        c = my_getch();
        if (c == '\n') {
            last_n(&line);
            print("\n");
            break;
        }
        last_len = my_strlen(line.str);
        choose_key(c, &line);
        print_line(line, last_len);
    }
    if (c == 4)
        return (-1);
    *s = line.str;
    return (my_strlen(*s));
}