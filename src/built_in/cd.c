/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** cd.c
*/

#include "my.h"
#include "minishell.h"

int alonecd(options_t *opt)
{
    char *stre;
    char *tabi[] = {"setenv", "OLDPWD", stre = getcwd(NULL, 0), 0};
    char *str = get_variable(&opt->envi, "HOME");

    add_setenvi(&opt->envi, tabi, opt);
    free(stre);
    if (chdir(str) == -1)
        exit(84);
    char *tab[] = {"setenv", "PWD", stre = getcwd(NULL, 0), NULL};
    add_setenvi(&opt->envi, tab, opt);
    free(str);
    free(stre);
    return (0);
}

int cd_arg(char **tab, options_t *opt, char *str, char *pwd)
{
    char *old_pwd[] = {"setenv", "OLDPWD", str = getcwd(NULL, 0), 0};

    if (chdir(tab[1]) == -1) {
        free(str);
        print("%s: %s.\n", tab[1], strerror(errno));
        return (1);
    }
    add_setenvi(&opt->envi, old_pwd, opt);
    free(str);
    char *new_pwd[] = {"setenv", "PWD", str = my_strdup(getcwd(pwd, 512)), 0};
    add_setenvi(&opt->envi, new_pwd, opt);
    free(str);
    return (0);
}

void cd_tiret_next(options_t *opt, char *pwd, char *stri, char *strre)
{
    char *str = my_strdup(getcwd(pwd, 512));
    char *new_pwd[] = {"setenv", "PWD", str, 0};

    add_setenvi(&opt->envi, new_pwd, opt);
    free(str);
    char *tabi[] = {"setenv", "OLDPWD", stri, NULL};
    add_setenvi(&opt->envi, tabi, opt);
    free(strre);
    free(stri);
}

int cd_tiret(options_t *opt, char *str, char *pwd, int z)
{
    char *stri;
    char *strre;

    if (!z) {
        dprint(2, ": No such file or directory.\n");
        return (1);
    }
    stri = my_strdup(getcwd(pwd, 512));
    strre = get_variable(&opt->envi, "OLDPWD");
    if (!strre) {
        free(stri);
        return (0);
    }
    if (chdir(strre) == -1)
        exit(84);
    cd_tiret_next(opt, pwd, stri, strre);
    return (0);
}

int cd(env_t **envi, char **cmd, options_t *opt)
{
    char pwd[512] = {0};
    char *str = NULL;
    static int z = 0;
    char **tab = copy_tab(cmd);
    clean_function(tab);

    if (!handling_errors(tab))
        return (1);
    else if (handling_errors(tab) == 2) {
        z = 1;
        alonecd(opt);
    } else {
        if (!my_strcmp(tab[1], "-"))
            return (cd_tiret(opt, str, pwd, z));
        else {
            z = 1;
            return (cd_arg(tab, opt, str, pwd));
        }
    }
    return (0);
}