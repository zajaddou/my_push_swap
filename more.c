
#include "push_swap.h"

void kill(char *flag)
{
	printf("\033[1;31mE: %s\033[0m\n", flag);
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

int *parsing(int ac, char **av)
{
	char	**split;
	char	*input;
	int		*list;
	int 	len;
	int		i;

	if (ac == 1)
		kill("No argements");
		 
	check_args(av);

	if (ac > 2)
		input = combine_args(ac, av);
	else
		input = av[1];

	len = count_word(input);

	split = malloc(sizeof(char *) * (len + 1));
	split = ft_split(input, ' ');
	split[len] = NULL;

	list = malloc(sizeof(int) * len);
	i = -1;
	while (split[++i] != NULL)
		list[i] = atoi(split[i]);

	if (check_dep(list) == 1)
		kill("Duplicate input");
	return (list);
}

