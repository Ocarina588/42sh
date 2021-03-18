/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** where2
*/

#include "my.h"
#include "minishell.h"

int search_binary(char *to_find, char *path, struct dirent *de, DIR *dir)
{
    int res = 0;

    while ((de = readdir(dir)) != NULL) {
        if (access(de->d_name, X_OK) && !my_strcmp(de->d_name, to_find)) {
            print("%s", path);
            print("/%s\n", de->d_name);
            res++;
        }
    }
    return (res);
}