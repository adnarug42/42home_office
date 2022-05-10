/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_with_zeroes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:54:37 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/10 17:27:16 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbr_with_zeroes(int precision, int num)
{
	int	i;
	int diff;
	int num2;
	int counter;

	i = 0;
	diff = 0;
	num2 = num;
	counter = 0;
	while (num != 0)
	{
		num = num/10;
		i++;
	}
	while (i < precision)
	{
	
		write (1, "0", 1);
		i++;
	}
	ft_putnbr_fd(num2, 1, 0);
	return (counter);
}