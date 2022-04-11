/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawinter <mawinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:10:54 by mawinter          #+#    #+#             */
/*   Updated: 2022/03/26 14:28:25 by mawinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	getdigits(int n)
{
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n = -1 * n;
	if (n < 10)
		return (1);
	return (1 + getdigits(n / 10));
}

int	power(int num, int pow)
{
	if (pow == 0)
		return (1);
	if (pow == 1)
		return (num);
	return (num * power(num, pow - 1));
}

void	helper(int n, int fd, int dg)
{
	char	c;
	int		temp;

	if (n == 0 && dg == 0)
		return ;
	if (dg == 0)
		return ;
	if (n < 0)
	{
		temp = -1 * (n / power(10, dg - 1));
		c = temp + '0';
		temp *= -1;
	}
	else
	{
		temp = n / power(10, dg - 1);
		c = temp + '0';
	}
	write(fd, &c, 1);
	helper(n - temp * power(10, dg - 1), fd, dg - 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	dg;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	dg = getdigits(n);
	if (n < 0)
		write(fd, "-", 1);
	helper(n, fd, dg);
}
