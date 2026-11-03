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

void    lstaddback(char **argv, )
{
    t_stack_node    *x;

    *x->next = NULL;

}

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
    return (1);
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

int main(int argc, char **argv)
{
    t_stack_node    a;
    t_stack_node    b;
    char            **thenums;

    if(argc < 2)
        return (0);
    thenums = ft_split(argv[1], ' ');
    if (!thenums || !check(thenums))
    {
        write(2, "Error\n", 6);
        free_thenums(thenums);
        return (1);
    }
    free_thenums(thenums);
    return (0);
}