/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** task02
*/

#include <stdarg.h>

#ifndef READ_SIZE
#define READ_SIZE (64)
#endif

char *get_next_line(int fd);
char *re_alloc(char *str, char c);
void my_putchar(char c);
int my_isneg(int nb);
void my_put_nbr(int nb);
void my_swap(int *a, int *b);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_rev_str(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_char_isalphanum(char str);
char *my_istrcat(const char *src, int j);
int my_wordlen(char *str, int i);
int my_str_words(char *str);
char **my_str_to_word_array(char const *str, char charact);
char *my_strdup(char const *src);
int sum_stdarg(int i, int nb, ...);
void print_char(va_list ap);
void print_str(va_list ap);
void print_nb(va_list ap);
int print(char *str, ...);
void convert_to_hexa(unsigned int nb);
int check_space(char *str, int i);
void print_hexa(va_list ap);
void convert_to_octal(unsigned int result);
void print_octal(va_list ap);
void print_hexa_up(va_list ap);
void convert_to_hexa_up(unsigned int result);
void convert_to_binary(unsigned int result);
void print_binary(va_list ap);
void print_pourcent(va_list ap);
void print_pourcent_char(char sign);
void convert_ascii(char a);
void print_unsignednbr(va_list ap);
void my_put_unsignednbr(unsigned int nb);
int lenght(long int nb);
void convert_to_hexa_p(long int result);
void print_adress_p(va_list ap);
int check_if_str0(char *str);
void print_big_s(va_list ap);
void print_char_non_printable(char *str);
int lenghtbis(unsigned int nb);
void print_octalbis(int i, int *stack);
int nb_len(int nb);
void print_withoutpourcent_char(char sign);
void  redirect_all_std(void);
void check_if_space_or_not(char *str, int i);
char *get_next_line(int fd);
int change_status(int a, int fd);
int dprint(int fd, char *str, ...);
int if_fonction(char *str, int i);
int function_pointers(char c, va_list ap);
void free_2darray(char **tab);

char *my_strcatrealloc(char *src, char *dest);
char **reorder_tab(char **tab);
int len_tab(char **tab);