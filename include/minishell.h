/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** minishell.h
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
ssize_t getdelim(char **lineptr, size_t *n, int delim, FILE *stream);
char *strsignal(int sig);

typedef struct list_env
{
    char *data;
    struct list_env *next;
}env_t;

typedef struct redirect_p
{
    char **files;
    int *nb;
}red_t;

typedef struct line_s
{
    char *path;
    char **tpath;
    char **my_env;
    char **tab;
}command_t;

typedef struct read
{
    size_t size;
    char *s;
    int my_exit;
}r_t;

typedef struct mult_actions
{
    int *exit_pipe;
    int old_fd[2];
    int new_fd[2];
    int nb_pipe;
    char **exe;
    char ***command;
    char **pipe;
    red_t *red_pipe;
}point_coma_t;

typedef struct parsing
{
    char **sep;
    char ***cmd;
    int *sep_val;
}parser_t;

typedef struct alias
{
    char *pid;
    int echo_value;
    char **alias;
}alias_t;

typedef struct history
{
    char **set;
    char **history;
}history_t;

typedef struct all_flags_s
{
    int exit_v;
    red_t redirect;
    r_t getlines;
    env_t *envi;
    point_coma_t pcoma;
    command_t com;
    parser_t parsing;
    alias_t alias;
    history_t history;
}options_t;

typedef struct parsing_t {
    char const *val;
    struct parsing_t *next;
} parsing_t;

typedef struct line_t
{
    int pos;
    char *str;
    int pos_history;
} line_t;

line_t *get_line_p(int mode, line_t *p);
line_t init_line(void);
int my_getline(char **s);
char *fuse(char *a, char *b);
int setenvi(char **env, options_t *opt);
int print_env(env_t **envi, char **tab, options_t *opt);
int add_setenvi(env_t **envi, char **tab, options_t *opt);
int remove_envi(env_t **envi, char **tab, options_t *opt);
void clean_function_loop(char **functions, int i);
int set_return_pipe(options_t *opt, int check, int status);
int alias(env_t **envi, char **tab, options_t *opt);
int unalias(env_t **envi, char **tab, options_t *opt);
char *nbstr(int nb);
r_t set_read(void);
int cmp(char *str, char *tab);
int cmp(char *str, char *tab);
int new_exit(char **tab);
int my_exit(options_t *opt, char **cmd);
int set_red_built_in(options_t *opt);
int print_env(env_t **envi, char **tab, options_t *opt);
int cd(env_t **envi, char **tab, options_t *opt);
int search_coat(int *i, char *s);
char **set_argv(char *s);
int skip_back(char *s, int *i);
char *get_variable(env_t **envi, char *str);
int repeat(env_t **env, char **cmd, options_t *opt);
int func_with_path(options_t *opt);
int built_in(char **cmd, options_t *opt);
int len_2d(char **tab);
int find_index(char **func, char *tab);
int check_error(char **cmd, options_t *opt);
void set_name(env_t **envi);
int check_buf(char *s, int mode);
char *remove_slash(char *s);
char **parse_path(char *s);
int len_env(env_t **envi);
int func_return(int status);
int check_tab(char *str);
int cmpunsetenv(char *str, char *tab);
int find_var(char **my_env);
int handling_errors_of_setenv(char **tab);
char *newstr_of_exeve(char **path, struct dirent *lu, int i);
int my_fork(options_t *opt, char *exe);
int find_tmp(env_t *tmp, env_t *tmprev, char *tab);
char **put_argv(char *s, char c);
int gestion_err_fork(int pid, int status);
char find_what_redirections(char **tab, int *z);
char *name_of_files(char **tab, char a, int z);
char *modifstr(char *s);
int nb_red(char **s);
int simple_left(red_t red, int i);
int double_right(red_t red, int i);
int double_left(red_t red, int i);
int simple_right(red_t red, int i);
int search_path(options_t *opt);
int read_to_find(options_t *opt, int i);
int loop_sep(options_t *opt);
int check_var(options_t *opt, char *s2, int j);
int set(env_t **env, char **cmd, options_t *opt);
char *special_var(options_t *opt, char *var, char *cmd, int z);
int loop_sep(options_t *opt);
char *get_var(char **tab, char *s);
void manage_special_key(line_t *line, char tab[5], char c);
red_t set_redirect(red_t red, char **s);
char **fill_files(char **s, red_t red);
char **modifcmd(char **s);
int *directions(red_t red, char *s);
int search_pipe(char **s, options_t *opt);
void what_function_pipe(options_t *opt);
int red_fork(options_t *opt, char *exe);
char **stock_env(env_t **envi);
int fill_exe(options_t *opt, int i);
char *read_to_find_pipe(options_t *opt, int i, int j);
int my_fork_pipe_right(options_t *opt, char *exe2, int i, int fd[2]);
int my_child_left(int i, int fd[2], options_t *opt, char *exe1);
int echo_var(env_t **env, char **cmd, options_t *opt);
void clean_function(char **functions);
int check_echo_var(char **cmd, int *i, int j, options_t *opt);
int *set_sep_value(options_t *opt);
int set_command(options_t *opt);
int check_pipe(char *s, options_t *opt);
int ambiguous_red(char *s, red_t red);
char **parsing(char *s);
int bad_redi(char *s, options_t *opt);
int *find_nb_redirections(red_t red, char **s);
int my_child_red(options_t *opt, char *exe);
char *my_new_str(char **tab, char *str, char *newstr, int i);
int make_pipe(int pid, int *i, options_t *opt);
int my_fork_pipe_left(options_t *opt, char *exe1, int i);
void fill_command(options_t *opt, char **s);
int check_red_pipe(int i, options_t *opt);
int check_red_pipeb(int i, options_t *opt);
void add_word(char ***old_line, char *s);
char **first_parsing(char *input, int *ret);
int find_new_word(char **str);
int find_end(char *str, int rep);
void func_pars(int *i, char **input, char **av);
int func_pars_two(int *len, int *i, char **str, char *tmp);
void find(parsing_t **head, char *str);
char **parsing_2(char **tab);
char ***set_functions(char **tab, const char **r);
int is_over(char *str, char const **r);
int check_error_function(char **tab);
int find_pipe(char **tab, int way, int i);
int is_co(char *s);
void clean_function(char **functions);
void free_intermediate(options_t *opt);
void free_path(options_t *opt);
void free_opt(options_t *opt);
void free_pipe(options_t *opt);
alias_t init_alias(void);
void print_line(line_t line, int last_len);
int check_error_sep(char **cmd);
int var_interpreter(char **cmd, options_t *opt);
void clean_function_loop(char **functions, int i);
char **change_cmd_alias(char **tab, options_t *opt);
int where(env_t **envi, char **tab, options_t *opt);
void signal_handler(int num);
void change_alias(char **tab, options_t *opt, int line, int skip);
int count_char(char *str, char);
char **copy_tab(char **tab);
int get_total_size(char **tab);
char **copy_alias(char *str, int i, char **alias);
void print_alias(char **alias);
int is_quote(char **tab);
char **copy_alias_parent(char *str, int i, char **alias);
char *cut_str(char *str, int nb, char cut);
char *get_alias(char *);
int get_line(options_t *opt);
options_t *get_opt(int mode, options_t *p);
int search_binary(char *to_find, char *path, struct dirent *de, DIR *dir);
int check_slash(char *str);
char my_getch(void);
void shift(char *s);
int pipe_builtin(int i, options_t *opt, char *exe1);
int pipe_path(int i, options_t *opt, char *exe1);
int which(env_t **envi, char **tab, options_t *opt);
void retab_ends(options_t *opt, int tmp, int tmp2);
void removeb(char *s);
void clean_function(char **functions);
void clean_function_loop(char **functions, int i);
void addnode_end(env_t **start_queue, env_t *node);
char *change_str(char **tab, env_t **envi, options_t *opt);
env_t *crnode(char *data);
int handling_errors(char **tab);
char **fill_builtin(char **tab);
int check_builtin(char *str, int);
int check_alias(char *, char **, int);
int where_finds(char *to_find, char *all_path, int opt);
int manage_pipe(char **s, options_t *opt);
int get_path(char **);
history_t init_history(void);
void what_function(char **cmd, options_t *opt);
void add_history(options_t *opt);
