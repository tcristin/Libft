/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcristin <tcristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:49:48 by tcristin          #+#    #+#             */
/*   Updated: 2021/10/20 14:44:15 by tcristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static void	ft_strrev(char *str)
{
	int		len;
	int		i;
	char	tmp;

	len = ft_strlen(str) - 1;
	i = 0;
	while (i <= len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i];
		str[len - i] = tmp;
		i++;
	}
}

static size_t	count_nb(int n)
{
	size_t	count;

	count = 0;
	if (n / 10)
	{
		while (n)
		{
			count++;
			n /= 10;
		}
		return (count);
	}
	return (1);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	size_t	i;

	sign = (n < 0);
	str = ft_calloc(count_nb(n) + sign + 1, sizeof(*str));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	i = 0;
	while (n != 0)
	{
		str[i] = '0' + ft_abs(n % 10);
		n = (n / 10);
		i++;
	}
	if (sign)
		str[i] = '-';
	ft_strrev(str);
	return (str);
}
