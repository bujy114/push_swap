
#include "push_swap.h"

int	check(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (argv[i][j] == '\0')
			return (0);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (i > 0);
}

void	free_thenums(char **thenums)
{
	int	i;

	if (!thenums)
		return ;
	i = 0;
	while (thenums[i])
	{
		free(thenums[i]);
		i++;
	}
	free(thenums);
}

int	count_nums(char **thenums)
{
	int	i;

	i = 0;
	while (thenums[i])
		i++;
	return (i);
}

int	fill_nums(char **thenums, int *num, int size)
{
	int		i;
	long	test;

	i = 0;
	while (i < size)
	{
		test = ft_atol(thenums[i]);
		if (test == -2147483649 || test == 2147483648)
			return (1);
		num[i] = (int)test;
		i++;
	}
	return (0);
}

int	*makeint(char **thenums, int *i)
{
	int	*num;

	*i = count_nums(thenums);
	if (*i == 0)
		return (NULL);
	num = malloc(*i * sizeof(int));
	if (!num)
		return (NULL);
	if (fill_nums(thenums, num, *i))
	{
		free(num);
		return (NULL);
	}
	return (num);
}

int	check_empty_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] == ' ')
			j++;
		if (argv[i][j] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	check_dup(int *num, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (num[i] == num[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	allocate_stacks(t_stack *a, t_stack *b, int size)
{
	a->values = malloc(size * sizeof(int));
	if (!a->values)
		return (1);
	b->values = malloc(size * sizeof(int));
	if (!b->values)
	{
		free(a->values);
		a->values = NULL;
		return (1);
	}
	return (0);
}

void	copy_values(t_stack *a, int *num, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		a->values[i] = num[i];
		i++;
	}
}

int	init_stacks(t_stack *a, t_stack *b, int *num, int size)
{
	if (!a || !b || !num || size <= 0)
		return (1);
	a->values = NULL;
	b->values = NULL;
	a->size = size;
	a->capacity = size;
	b->size = 0;
	b->capacity = size;
	if (allocate_stacks(a, b, size))
		return (1);
	copy_values(a, num, size);
	return (0);
}

int	*get_numbers(int argc, char **argv, int *size)
{
	char	**thenums;
	char	*all_args;
	int		*num;

	if (check_empty_args(argc, argv))
		return (NULL);
	all_args = join_args(argc, argv);
	if (!all_args)
		return (NULL);
	thenums = ft_split(all_args, ' ');
	free(all_args);
	if (!thenums || !check(thenums))
	{
		free_thenums(thenums);
		return (NULL);
	}
	num = makeint(thenums, size);
	free_thenums(thenums);
	return (num);
}

int	main(int argc, char **argv)
{
	int		*num;
	int		size;
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	num = get_numbers(argc, argv, &size);
	if (!num || check_dup(num, size))
	{
		free(num);
		write(2, "Error\n", 6);
		return (1);
	}
	if (init_stacks(&a, &b, num, size))
	{
		free(num);
		write(2, "Error\n", 6);
		return (1);
	}
	free(num);
	free(a.values);
	free(b.values);
	return (0);
}

