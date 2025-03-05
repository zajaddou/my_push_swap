
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef PUSH_SWAP
#define PUSH_SWAP

typedef struct  s_unit
{
    int             data;
    struct s_unit   *next;
}               t_unit;

void kill(char *flag);
int  is_valid(char *arg);
void check_args(char *av[]);
void add_node(t_unit **real, int data);

#endif