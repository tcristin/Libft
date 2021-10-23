/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcristin <tcristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:42:45 by tcristin          #+#    #+#             */
/*   Updated: 2021/10/19 18:40:05 by tcristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	s;
	size_t	e;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	s = 0;
	while (s1[s] && c_set(s1[s], set))
		s++;
	e = ft_strlen(s1);
	while (e > s && c_set(s1[e - 1], set))
		e--;
	str = (char *)ft_calloc((e - s + 1), sizeof(*str));
	if (!str)
		return (NULL);
	i = 0;
	while (s + i < e)
	{
		str[i] = s1[s + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
