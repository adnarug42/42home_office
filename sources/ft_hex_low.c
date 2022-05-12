/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_low.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:22:54 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/12 17:27:47 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"


int	ft_hex_low(unsigned long num)
{
	static int counter;
	if (num >= 16)
	{
		ft_hex_low(num / 16);
		ft_hex_low(num % 16);
	}
	else
	{
		if (num <= 9)
		{
			ft_putchar_fd((num + '0'), 1);
			counter += 1;
		}
		else
		{
			ft_putchar_fd((num - 10 + 'a'), 1);
			counter += 1;
		}
	}
	return (counter);
}
