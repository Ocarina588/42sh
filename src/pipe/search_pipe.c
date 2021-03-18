/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** search_pipe.c
*/

#include "my.h"
#include "minishell.h"

char *read_to_find_pipe(options_t *opt, int i, int j)
{
    DIR *fd = opendir(opt->com.tpath[i]);
    struct dirent *lu = NULL;
    char *exe = NULL;

    if (fd == NULL)
        return (NULL);
    while ((lu = readdir(fd)) != NULL)
        if (!my_strcmp(opt->pcoma.command[j][0], lu->d_name)) {
            exe = newstr_of_exeve(opt->com.tpath, lu, i);
            closedir(fd);
            return (exe);
        }
    if (closedir(fd) == -1)
        exit(84);
    return (NULL);
}