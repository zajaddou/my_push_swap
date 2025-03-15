
#include "push_swap.h"

void leak()
{
	system("leaks push_swap");
}

int main(int ac, char *av[])
{
	//atexit(leak);
	t_stack *stack_a = NULL;

	int len = 0;
	int i  = -1; 
	int *list = parsing(ac, av, &len);
	
	while (++i < len)
		add_node(&stack_a, list[i]);

	index_node(&stack_a);
	print_node(stack_a);

}
