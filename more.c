#include "push_swap.h"

void kill(char *flag)
{
   printf("E: %s\n", flag);
   exit(1);
}

int is_valid(char *arg)
{
  while (*arg)
  {
    if (!((*arg >= '0' && *arg <= '9') || *arg == ' '))
      return (0);
    arg++;
  }
  return (1);
}

void check_args(char *av[])
{
  int i = 1;
  
  while(av[i])
  {
    if (!is_valid(av[i]))
       kill("Invalid Args");  
    i++;
  }
}

void add_node(t_unit **real, int data)
{
    t_unit *temp;
    t_unit *new;
    
    temp = *real;
    
    new = malloc(sizeof(t_unit));
    
    printf("%d\n", data);
    new->data = data;
    new->next = NULL;
    
    while (temp->next != NULL)
       temp = temp->next;
    temp->next = new;
}