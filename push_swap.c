
#include "push_swap.h"

int main(int ac, char *av[])
{
  t_unit *stack_a = NULL;
  int i = 0;
  
  if (ac == 1)
    kill("No argements\n");
     
  check_args(av);
  
  stack_a = malloc(sizeof(t_unit));
  stack_a->next = NULL;
  
  while (av[++i])
    add_node(&stack_a, atoi(av[i]));
}