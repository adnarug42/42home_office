/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:45:26 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/18 13:57:21 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbr_unsigned(int n, int *sub_counter)
{
	
	if ((unsigned)n < 10)
	{
		ft_putchar_fd((unsigned)n + '0', 1);
		*sub_counter += 1;
		return 0;
	}
	*sub_counter += 1;
	ft_putnbr_unsigned((unsigned)n / 10, sub_counter);
	ft_putchar_fd(((unsigned)n % 10) + '0', 1);
	return (*sub_counter);
}
