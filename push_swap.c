
#include "push_swap.h"

int main(int ac, char *av[])
{
	t_stack *stack_a;

	int *list = parsing(ac, av);

	while (*list)
		add_node(&stack_a, *(list++));

	printf("Linkd List :");

	t_stack *temp = stack_a;

	while (temp)
	{
		printf("\n%d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}