/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcristin <tcristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:36:25 by tcristin          #+#    #+#             */
/*   Updated: 2021/10/19 18:38:45 by tcristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char c)
{
	char	*white;

	white = " \t\n\v\f\r\0";
	while (*white)
	{
		if (c == *(white++))
			return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	nb;
	int	sign;

	nb = 0;
	sign = 1;
	while (check(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		if (nb > 1000000000 && sign == 1)
			return (-1);
		else if (nb > 1000000000 && sign == -1)
			return (0);
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (nb * sign);
}
