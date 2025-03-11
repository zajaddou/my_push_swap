
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "LIBFT/libft.h"

#ifndef PUSH_SWAP
#define PUSH_SWAP

typedef struct  s_unit
{
    int             data;
    struct s_unit   *next;
}               t_unit;

void    kill(char *flag);
int     is_valid(char *arg);
void    print_list(int *list);
void    check_args(char *av[]);
int     count_word(char const *s);
char    *combine_args(int ac, char **av);
void    add_node(t_unit **real, int data);

#endif