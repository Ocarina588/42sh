/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** nb_len
*/

int nb_len(int nb)
{
    int tmp = nb;
    int len = 0;

    while (tmp) {
        tmp /= 10;
        len++;
    }
    return (nb ? len : 1);
}