/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:45:26 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/12 19:29:11 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n, int fd, int *unsigned_counter)
{
	
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
		*unsigned_counter += 1;
		return ;
	}
	ft_putnbr_unsigned(n / 10, fd, unsigned_counter);
	ft_putchar_fd((n % 10) + '0', fd);
	*unsigned_counter += 1;
	return ;
}