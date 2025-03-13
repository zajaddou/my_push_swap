
#include "push_swap.h"

void index_node(t_stack **stack_a)
{
    t_stack *temp;
    t_stack *min;
    int		index;

	index = 0;
    while (1)
    {
        temp = *stack_a;
        min = NULL;

        while (temp)
        {
            if (temp->index == -1)
            {
                if (min == NULL)
                    min = temp;
                else if (temp->data < min->data)
                    min = temp;
            }
            temp = temp->next;
        }
        if (min == NULL)
            break;
        min->index = index++;
    }
}

void print_node(t_stack *stack_a)
{
	t_stack *temp = stack_a;

	printf("Linkd List :");
	while (temp)
	{
		printf("\n%d | %d ", temp->index , temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void add_node(t_stack **real, int data)
{
    t_stack *temp;
    t_stack *new;

    if (*real == NULL)
	{
        *real = malloc(sizeof(t_stack));
        (*real)->data = data;
        (*real)->index = -1;
        (*real)->next = NULL;
    }
    else {
        temp = *real;
        new = malloc(sizeof(t_stack));
        new->data = data;
        new->index = -1;
        new->next = NULL;

        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    }
}
