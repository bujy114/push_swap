/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsallam <lsallam@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 14:02:14 by lsallam           #+#    #+#             */
/*   Updated: 2026/09/29 13:49:50 by lsallam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_length(char const *ptr, char c)
{
	size_t		size;
	char const	*walkthro;

	size = 0;
	walkthro = ptr;
	while (*walkthro != c && *walkthro != '\0')
	{
		size++;
		walkthro++;
	}
	return (size);
}

static char	*copy_word(size_t len, char const *origin)
{
	size_t	count;
	char	*copy;

	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	count = 0;
	while (count < len)
	{
		copy[count] = origin[count];
		count++;
	}
	copy[count] = '\0';
	return (copy);
}

static void	free_split(char **ptr, size_t words_num)
{
	size_t	num;

	num = 0;
	while (num < words_num)
	{
		free(ptr[num]);
		num++;
	}
	free(ptr);
}

static char	**fill_split(char const *s, char **ptr, char c)
{
	size_t	i;
	size_t	word;
	size_t	len;

	word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
		{
			len = get_length(s + i, c);
			ptr[word] = copy_word(len, s + i);
			if (ptr[word] == NULL)
			{
				free_split(ptr, word);
				return (NULL);
			}
			word++;
			i += len;
		}
		if (s[i] != '\0')
			i++;
	}
	ptr[word] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char		**ptr;
	char const	*walkthro;
	size_t		num;
	size_t		i;

	i = 0;
	num = 0;
	if (!s)
		return (NULL);
	walkthro = s;
	if (walkthro[0] != c && walkthro[0] != '\0')
	{
		num++;
		i++;
	}
	while (walkthro[i] != '\0')
	{
		if (walkthro[i] == c && walkthro[i + 1] != c && walkthro[i + 1] != '\0')
			num++;
		i++;
	}
	ptr = malloc((num + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	return (fill_split(s, ptr, c));
}
