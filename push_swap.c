
#include "push_swap.h"

void leak()
{
    system("leaks push_swap");
}

int main(int ac, char *av[])
{
	atexit(leak);
	t_stack *stack_a = NULL;

	int *list = parsing(ac, av);

	while (*list)
		add_node(&stack_a, *(list++));

	index_node(&stack_a);
	print_node(stack_a);
}
