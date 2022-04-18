/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:45:26 by pguranda          #+#    #+#             */
/*   Updated: 2022/04/18 15:49:35 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define LONG_MIN -2147483648LL

int		ft_count_digits(int n);
int		ft_pwr(int n, int pwr);
int		ft_neg_check(int n, int fd);
int		ft_long_min(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	int				digit;
	char			c;
	int				pwr;

	digit = 0;
	pwr = ft_count_digits(n) - 1;
	if (ft_long_min(n, fd) == 1)
		return ;
	n = ft_neg_check(n, fd);
	while (n >= 10)
	{
		digit = n / ft_pwr(10, pwr);
		c = digit + '0';
		write(fd, &c, 1);
		n = n - (digit * ft_pwr(10, pwr));
		pwr--;
	}
	c = n + '0';
	write(fd, &c, 1);
}

int	ft_neg_check(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	return (n);
}

int	ft_count_digits(int n)
{
	int				counter;

	counter = 0;
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		n = n / 10;
		counter++;
	}
	counter++;
	return (counter);
}

int	ft_pwr(int n, int pwr)
{
	int				result;

	result = n;
	while (pwr > 1)
	{
		result = result * n;
		pwr--;
	}
	return (result);
}

int	ft_long_min(int n, int fd)
{
	if (n == LONG_MIN)
	{
		write(fd, "-2147483648", 11);
		return (1);
	}
	else
		return (0);
}
