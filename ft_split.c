/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcristin <tcristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:59:34 by tcristin          #+#    #+#             */
/*   Updated: 2021/10/19 18:47:27 by tcristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_elem(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		if (s[i])
			i++;
	}
	return (count);
}

static size_t	count_let(char const *s, char c, size_t	i)
{
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	fill_arr(char **arr, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = count_let(s, c, i);
			arr[k] = ft_calloc(j - i + 1, sizeof(**arr));
			if (!arr[k])
				return (0);
			ft_memcpy(arr[k], s + i, j - i);
			k++;
			i = j - 1;
		}
		i++;
	}
	arr[k] = NULL;
	return (1);
}

static char	**free_arr(char **arr)
{
	size_t	i;

	if (!arr)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = ft_calloc(count_elem(s, c) + 1, sizeof(*arr));
	if (!arr)
		return (NULL);
	if (!fill_arr(arr, s, c))
		return (free_arr(arr));
	return (arr);
}
