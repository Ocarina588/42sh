/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** double_red.c
*/

#include "my.h"
#include "minishell.h"

char *my_read(void)
{
    char *tmp = NULL;
    size_t size;
    int i = 0;

    if (getline(&tmp, &size, stdin) == -1)
        return (NULL);
    return (tmp);
}

char *add_read(char *tmp, char *buffer)
{
    char *new = malloc((tmp ? my_strlen(tmp) : 0)
    + (buffer ? my_strlen(buffer) : 0) + 1);
    int i = 0;

    if (!new)
        exit(84);
    for (i = 0; buffer && buffer[i]; i++)
        new[i] = buffer[i];
    for (int j = 0; tmp && tmp[j]; j++)
        new[i++] = tmp[j];
    new[i] = '\0';
    return (new);
}

int two_redi(char *buffer)
{
    int fd[2];

    if (pipe(fd) == -1)
        exit(84);
    write(fd[1], buffer, my_strlen(buffer));
    if (close(fd[1]) == -1)
        exit(84);
    if (dup2(fd[0], 0) == - 1)
        exit(84);
    return (fd[0]);
}

char *loop_for_read(int i,red_t red, char *buffer, char *str)
{
    char *tmp = NULL;

    while (1) {
        if (isatty(0))
            print("? ");
        tmp = my_read();
        if (!tmp || !my_strcmp(tmp, red.files[i]) || !my_strcmp(tmp, str))
            return (buffer);
        buffer = add_read(tmp, buffer);
    }
    return (NULL);
}

int double_left(red_t red, int i)
{
    char *buffer = malloc(1);
    int z = 0;

    if (!buffer)
        exit(84);
    buffer[0] = '\0';
    for (; red.files[i][z]; z++);
    red.files[i][z++] = '\n';
    red.files[i][z] = '\0';
    char *str = malloc(sizeof(char)* my_strlen(red.files[i]));
    str = my_strncpy(str, red.files[i], my_strlen(red.files[i]) - 1);
    loop_for_read(i, red, buffer, str);
    if (buffer == NULL)
        buffer[0] = '\0';
    return (two_redi(buffer));
}