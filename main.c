/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsallam <lsallam@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 11:06:55 by lsallam           #+#    #+#             */
/*   Updated: 2026/11/03 11:06:57 by lsallam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check(char **argv)
{
    int i;
    int j;

    i = 0;
    while(argv[i])
    {
        j = 0;
        if (argv[i][j] == '-' || argv[i][j] == '+')
            j++;
        if (argv[i][j] == '\0')
            return (0);
        while(argv[i][j])
        {
            if (ft_isdigit(argv[i][j]) == 0)
                return (0);
            j++;
        }
        i++;
    }
    return (i > 0);
}

void free_thenums(char **thenums)
{
    int i;

    if (!thenums)
        return ;
    i = 0;
    while(thenums[i])
    {
        free(thenums[i]);
        i++;
    }
    free(thenums);
}

int *makeint(char **thenums, int *i)
{
    int     *num;
    long    test;

    *i = 0;
    while(thenums[*i])
    {
        (*i)++;
    }
    if (*i == 0)
        return (NULL);
    num = malloc((*i)*sizeof(*num));
    if (!num)
        return (NULL);
    *i = 0;
    while(thenums[*i])
    {
        test = ft_atol(thenums[*i]);
        if (test == -2147483649 || test == 2147483648)
        {
            free(num);
            return (NULL);
        }
        num[*i] = test;
        (*i)++;
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

int check_dup(int *num, int size)
{
    int i;
    int j;

    i = 0;
    while(i < size)
    {
        j = i + 1;
        while(j < size)
        {
            if (num[i] == num[j])
                return (1);
            j++;
        }
        i ++;
    }
    return (0);
}

int	init_stacks(t_stack *a, t_stack *b, int *num, int size)
{
    int i;

    if (!a || !b || !num || size <= 0)
		return (1);
    a->values = NULL;
    b->values = NULL;
    a->values = malloc (size * sizeof(int));
    if (!(a->values))
        return (1);
    b->values = malloc (size * sizeof(int));
    if  (!(b->values))
    {
        free(a->values);
        a->values = NULL;
        return (1);
    }
    i = 0;
    while (i < size)
    {
        a->values[i] = num[i];
        i++;
    }
    a->size = size;
    a->capacity = size;
    b->size = 0;
    b->capacity = size;
    return (0);
}

int main(int argc, char **argv)
{
    char            **thenums;
    char            *all_args;
    int             *num;
    int             size;
    t_stack a;
    t_stack b;
    
    if(argc < 2)
        return (0);
    if (!check_empty_args(argc, argv))
    {
        write(2, "Error\n", 6);
        return (1);
    }
    all_args = join_args(argc, argv);
    if (!all_args)
    {
        write(2, "Error\n", 6);
        return (1);
    }
    thenums = ft_split(all_args, ' ');
    free(all_args);
    if (!thenums || !check(thenums))
    {
        write(2, "Error\n", 6);
        free_thenums(thenums);
        return (1);
    }
    num = makeint(thenums, &size);
    free_thenums(thenums);
    if (!num)
    {
        write(2, "Error\n", 6);
        return (1);
    }
    if (check_dup(num, size))
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