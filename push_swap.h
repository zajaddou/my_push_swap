
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "LIBFT/libft.h"

#ifndef PUSH_SWAP
#define PUSH_SWAP

typedef struct stack
{
   int    data;
   int    index;
   struct stack *next;
} t_stack;

void    ft_free(void *ptr);
void    *ft_malloc(size_t size);
void    ft_exit(char *why);
int     is_valid(char *arg);
void    print_list(int *list, int len);
void    check_args(char *av[]);
int     check_dep(int *list);
int     count_word(char const *s);
char    *combine_args(int ac, char **av);
int     *parsing(int ac, char **av, int *len);

void    add_node(t_stack **real, int data);
void    index_node(t_stack **stack_a);
void    print_node(t_stack *stack_a);


#endif