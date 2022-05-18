/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:45:26 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/18 13:22:06 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#define LONG_MIN -__LONG_MAX__ -1L
#define LONG_MAX 2147483647

int	ft_putnbr_printf(int n, int *sub_counter)
{	

	if ((long)n > LONG_MAX || (long)n < LONG_MIN)
		return 0;
	if (n == -2147483648)
	{
		ft_putstr_fd("2147483648", 1);
		*sub_counter += 10;
		return (10);
	}
	if (n < 0)
	{
		n = n * -1;
	}
	if (n < 10)
	{
		ft_putchar_fd(n + '0', 1);
		*sub_counter += 1;
		return 1;
	}
	*sub_counter += 1;
	ft_putnbr_printf(n / 10, sub_counter);
	ft_putchar_fd((n % 10) + '0', 1);
	return (*sub_counter);
}
