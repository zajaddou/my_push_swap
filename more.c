
#include "push_swap.h"

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
			ft_exit("Invalid Args");
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
	char	*temp;
	int 	i;

	i = 0;
	input = NULL;
	while (++i < ac)
	{
		temp = input;
		input = ft_strjoin(input, av[i]);
		free(temp);
		if ((i+1) < ac)
		{
			temp = input;
			input = ft_strjoin(input, " ");
			free(temp);
		}
	}
	return (input);
}

void print_list(int *list, int len)
{
	int i = -1;
	while (++i < len)
		printf("[%d]\n", list[i]);
}

int check_dep(int *list)
{
    int		a;
	int		b;

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

int *parsing(int ac, char **av, int *len)
{
	char	**split;
	char	*input;
	int		*list;
	int		i;

	if (ac == 1)
		ft_exit("No argements");

	check_args(av);

	input = combine_args(ac, av);
	*len  = count_word(input);
	split = ft_malloc(sizeof(char *) * (*len + 1));
	split = ft_split(input, ' ');
	free(input);
	split[*len] = NULL;

	list = ft_malloc(sizeof(int) * (*len));
	i = -1;
	while (split[++i] != NULL)
		list[i] = atoi(split[i]);

	print_list(list, *len);

	// work 

	i = 0;
	while (split[i] != NULL)
		free(split[i++]);
	free(split);

	if (check_dep(list) == 1)
		ft_exit("Duplicate input");
	return (list); 
}
