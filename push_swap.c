
#include "push_swap.h"



int main(int ac, char *av[])
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

	list = (int *)malloc(sizeof(int) * len);

	i = -1;
	while (split[++i] != NULL)
		list[i] = atoi(split[i]);

	if (check_dep(list) == 1)
		kill("Duplicate input");

	print_list(list);

}