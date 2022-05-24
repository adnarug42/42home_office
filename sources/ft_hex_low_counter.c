/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_low_counter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:22:54 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/24 12:02:51 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_hex_low_counter(int num, int *sub_counter)
{
	int	counter;

	counter = 0;
	if ((long)num == 9223372036854775807LL || (unsigned long)num == ULONG_MAX)
	{
		*sub_counter += 8;
		return (8);
	}
	if ((unsigned)num >= 16)
	{
		ft_hex_low_counter((unsigned)num / 16, sub_counter);
		ft_hex_low_counter((unsigned)num % 16, sub_counter);
	}
	else
			*sub_counter += 1;
	return (*sub_counter);
}
