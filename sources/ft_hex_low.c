/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_low.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:22:54 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/16 11:09:20 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_hex_low(unsigned int num, int *hex_counter_low)
{
	if ((long)num == 9223372036854775807LL || (unsigned)num == ULONG_MAX)
	{
		write(1, "ffffffff", 8);
		*hex_counter_low+= 8;
		return ;
	}
	if (num >= 16)
	{
		ft_hex_low(num / 16, hex_counter_low);
		ft_hex_low(num % 16, hex_counter_low);
	}
	else
	{
		if (num <= 9)
		{
			ft_putchar_fd((num + '0'), 1);
			*hex_counter_low += 1;
		}
		else
		{
			ft_putchar_fd((num - 10 + 'a'), 1);
			*hex_counter_low += 1;
		}
	}
	return ;
}
