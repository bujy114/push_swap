/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsallam <lsallam@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 13:01:50 by lsallam           #+#    #+#             */
/*   Updated: 2026/09/21 09:37:27 by lsallam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	get_limit(const char *nptr, int *i, int *sign)
{
	*sign = 1;
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	if (*sign == -1)
		return (2147483648);
	return (2147483647);
}

long	ft_atol(const char *nptr)
{
	int		i;
	int		sign;
	long	result;
	long	limit;

	i = 0;
	result = 0;
	limit = get_limit(nptr, &i, &sign);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (result > (limit - (nptr[i] - '0')) / 10)
		{
			if (sign == -1)
				return (-2147483649);
			return (2147483648);
		}
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	if (sign == -1)
		return (-result);
	return (result);
}