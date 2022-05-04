/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:45:26 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/03 10:40:14 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"

#define LONG_MIN -2147483648
#define LONG_MAX 2147483647

void	ft_putnbr_unsigned(unsigned int n, int fd)
{
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
		return ;
	}
	ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
	return ;
}
