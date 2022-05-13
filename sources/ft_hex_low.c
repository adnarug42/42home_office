/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_low.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:22:54 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/13 17:06:27 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
// #include <limits.h>
// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
// int				ft_putchar_fd(char c, int fd);

void	ft_hex_low(long num, int *hex_counter_low)
{
	if (num == 9223372036854775807LL || (unsigned)num == ULONG_MAX)
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
			ft_putchar_fd((num - 10 + 'A'), 1);
			*hex_counter_low += 1;
		}
	}
	return ;
}

// int main ()
// {
// 	int i = 0;
// 	int z = 0;
// 	int *counter;

// 	*counter = malloc (sizeof(int));
// 	*counter = 0;

// 	ft_hex_low(INT_MAX, counter);
// 	ft_hex_low(INT_MIN, counter);
// 	ft_hex_low(LONG_MAX, counter);
// 	 ft_hex_low(LONG_MIN, counter);
//  	ft_hex_low(ULONG_MAX, counter);
// 	ft_hex_low(0, counter);
	
// 	z = printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// 	printf ("my printf:%d printf: %d", *counter, z);
// 	free(counter);
// 	return (0);
// }