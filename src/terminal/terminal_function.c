/*
** EPITECH PROJECT, 2020
** terminal function
** File description:
** sdf
*/

#include "my.h"
#include "minishell.h"

void print_line(line_t line, int last_len)
{
    // print("\r\033[1C\033[1C\033[1C");
    print("\33[2K\r$> ");
    print("%s", line.str);
    // for (int i = 0; i < last_len; i++)
    //     print(" ");
    print("\r\033[1C\033[1C\033[1C");
    for (int i = 0; i < line.pos; i++)
        print("\033[1C");
}