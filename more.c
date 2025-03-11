
#include "push_swap.h"

void kill(char *flag)
{
	printf("E: %s\n", flag);
	exit(1);
}

int is_valid(char *str)
{
	while (*str)
	{
		if ((*str >= '0' && *str <= '9') || *str == ' ')
			str++;
		else if (*str == '-' || *str == '+')
		{
			str++;
			if (!(*str >= '0' && *str <= '9'))
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

void check_args(char *av[])
{
	while (*(++av))
		if (!is_valid(*av))
			kill("Invalid Args");
}

int	count_word(char const *s)
{
	int	c_words;
	int	i;

	i = 0;
	c_words = 0;
	while (s[i])
	{
		if (s[i] != ' ')
		{
			c_words++;
			while (s[i] && s[i] != ' ')
				i++;
		}
		else
			i++;
	}
	return (c_words);
}

char *combine_args(int ac, char **av)
{
	char	*input;
	int 	i;

	i = 0;
	input = NULL;
	while (++i < ac)
	{
		input = ft_strjoin(input, av[i]);
		if ((i+1) < ac)
			input = ft_strjoin(input, " ");
	}
	return (input);
}

void print_list(int *list)
{
	int i = -1;
	while (list[++i])
		printf("%d\n", list[i]);
}

int check_dep(int *list)
{
    int	a;
	int	b;

    a = 0;
    while (list[a])
    {
        b = a + 1;
        while (list[b])
        {
            if (list[a] == list[b])
                return (1);
            b++;
        }
        a++;
    }
    return (0);
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