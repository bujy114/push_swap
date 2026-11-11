/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsallam <lsallam@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 16:17:30 by lsallam           #+#    #+#             */
/*   Updated: 2026/09/20 16:19:05 by lsallam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *c)
{
	size_t	counter;

	counter = 0;
	while (*c != '\0')
	{
		counter++;
		c++;
	}
	return (counter);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	size_t	n;
	char	*ptr;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ptr = malloc(s1len + s2len + 1);
	if (ptr == NULL)
		return (NULL);
	n = 0;
	while (n < s1len)
	{
		ptr[n] = s1[n];
		n++;
	}
	while (n < s2len + s1len)
	{
		ptr[n] = s2[n - s1len];
		n++;
	}
	ptr[n] = '\0';
	return (ptr);
}

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
        unsigned const char     *s;
        unsigned char           *d;

        s = src;
        d = dest;
        while (n != 0)
        {
                *d = *s;
                d++;
                s++;
                n--;
        }
        return (dest);
}

char    *ft_strdup(const char *s)
{
        size_t  len;
        char    *ptr;

        len = ft_strlen(s);
        ptr = malloc((len + 1));
        if (!ptr)
                return (NULL);
        ft_memcpy(ptr, s, len);
        ptr[len] = '\0';
        return (ptr);
}

char	*join_args(int argc, char **argv)
{
	char	*joined;
	char	*temp;
	int		i;

	temp = ft_strdup(argv[1]);
	if (!temp)
		return (NULL);
	i = 2;
	while (i < argc)
	{
		joined = ft_strjoin(temp, " ");
		free(temp);
		if (!joined)
			return (NULL);
		temp = ft_strjoin(joined, argv[i]);
		free(joined);
		if (!temp)
			return (NULL);
		i++;
	}
	return (temp);
}
