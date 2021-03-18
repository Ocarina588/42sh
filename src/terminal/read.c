/*
** EPITECH PROJECT, 2020
** read
** File description:
** sdf
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include "minishell.h"
#include "my.h"

char *get_history_line(line_t *line, int mode)
{
    char **history = get_opt(0, NULL)->history.history;

    if (history && mode && line->pos_history &&
        history[line->pos_history - 1]) {
        line->str = my_strdup(history[--line->pos_history]);
        line->pos = my_strlen(line->str);
    }
    if (history && !mode &&
        line->pos_history < len_2d(get_opt(0, NULL)->history.history)
        && history[line->pos_history + 1]) {
        line->str = my_strdup(history[++line->pos_history]);
        line->pos = my_strlen(line->str);
    }
}

line_t *get_line_p(int mode, line_t *p)
{
    static line_t *line = NULL;

    if (mode)
        line = p;
    return (line);
}

void manage_special_key(line_t *line, char tab[5], char c)
{
    if (tab[1] == 27 && tab[2] == 91 && tab[3] == 65)
        get_history_line(line, 1);
    if (tab[1] == 27 && tab[2] == 91 && tab[3] == 66)
        get_history_line(line, 0);
    if (tab[1] == 27 && tab[2] == 91 && tab[3] == 68 && line->pos)
        line->pos--;
    if (tab[1] == 27 && tab[2] == 91 && tab[3] == 67 &&
        line->pos < my_strlen(line->str))
        line->pos++;
    if (c == 127) {
        shift(line->str + line->pos - 1);
        line->pos ? line->pos-- : 0;
    }
    if ((tab[0] == 27 && tab[1] == 91 && tab[2] == 51 && tab[3] == 126)
        && line->pos < my_strlen(line->str))
        shift(line->str + line->pos);
}

char my_getch(void)
{
    char ch;
    struct termios old;
    struct termios new;

    ioctl(0, TCGETS, &old);
    new = old;
    new.c_lflag &= ~ICANON;
    new.c_lflag &= ~ECHO;
    ioctl(0, TCSETS, &new);
    read(0, &ch, 1);
    ioctl(0, TCSETS, &old);
    return (ch);
}