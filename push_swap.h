/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsallam <lsallam@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 11:06:39 by lsallam           #+#    #+#             */
/*   Updated: 2026/11/03 11:06:43 by lsallam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack_node
{
    int                 nbr;
    int                 index;
    struct s_stack_node *next;
    struct s_stack_node *prev;
} t_stack_node;

char	**ft_split(char const *s, char c);
int	    ft_isdigit(int c);

#endif
