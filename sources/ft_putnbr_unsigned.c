/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:45:26 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/10 17:05:01 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n, int fd)
{
	static int	counter;
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
		return 1;
	}
	counter++;
	ft_putnbr_unsigned(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
	return (counter);
}
