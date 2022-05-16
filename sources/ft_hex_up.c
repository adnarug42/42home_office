/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:22:54 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/16 10:12:30 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_hex_up(long num, int *hex_counter_up)
{
	if (num == 9223372036854775807LL || (unsigned)num == ULONG_MAX)
	{
		write(1, "FFFFFFFF", 8);
		*hex_counter_up += 8;
		return ;
	}
	if (num >= 16)
	{
		ft_hex_up(num / 16, hex_counter_up);
		ft_hex_up(num % 16, hex_counter_up);
	}
	else
	{
		if (num <= 9)
		{
			ft_putchar_fd((num + '0'), 1);
			*hex_counter_up += 1;
		}
		else
		{
			ft_putchar_fd((num - 10 + 'A'), 1);
			*hex_counter_up += 1;
		}
	}
	return ;
}
