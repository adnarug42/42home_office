/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_with_zeroes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:54:37 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/24 11:32:52 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbr_with_zeroes(int precision, int num)
{
	int	i;
	int num2;
	int counter;

	i = 0;
	num2 = num;
	counter = 0;
	if (num < 0)
		num *= -1;
	if (num == 0)
		i = 1;
	while (num != 0)
	{
		num = num/10;
		i++;
	}
	//printf (" i is: %d and precision is: %d ", i, precision);
	precision = precision - i;
	while (precision > 0)
	{
		write (1, "0", 1);
		precision--;
		counter++;
	}
	counter += ft_putnbr_fd(num2, 1, 0);
	return (counter);
}