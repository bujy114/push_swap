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
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
    int     *values;
    int     size;
    int     capacity;
}   t_stack;

char	**ft_split(char const *s, char c);
int	    ft_isdigit(int c);
long	ft_atol(const char *nptr);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *c);
char	*join_args(int argc, char **argv);



#endif
