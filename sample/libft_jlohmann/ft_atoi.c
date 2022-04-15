/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlohmann <jlohmann@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:36:08 by jlohmann          #+#    #+#             */
/*   Updated: 2022/04/10 03:16:52 by jlohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	value;

	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		++str;
	if (!ft_isdigit(*str) && *str != '+' && *str != '-')
		return (0);
	sign = 1;
	if (*str == '-')
	{
		sign = -sign;
		++str;
	}
	else if (*str == '+')
		++str;
	value = 0;
	while (ft_isdigit(*str))
	{
		value *= 10;
		value += *str - '0';
		++str;
	}
	return (sign * value);
}
