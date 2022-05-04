/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_with_zeroes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:54:37 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/04 18:11:39 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void	putnbr_with_zeroes(int precision, int num)
{
	int	i;
	int diff;
	int num2;

	i = 0;
	diff = 0;
	num2 = num;
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
	ft_putnbr_fd(num2, 1);
}