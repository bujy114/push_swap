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

int main(int argc, char **argv)
{
    char            **thenums;
    int             *num;
    int             size;

    if(argc < 2)
        return (0);
    thenums = ft_split(argv[1], ' ');
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
    free(num);
    return (0);
}