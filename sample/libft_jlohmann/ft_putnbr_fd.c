/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlohmann <jlohmann@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:50:23 by jlohmann          #+#    #+#             */
/*   Updated: 2022/04/11 21:00:14 by jlohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_len(int n)
{
	size_t	len_str;

	len_str = 0;
	while (n > 0)
	{
		n /= 10;
		++len_str;
	}
	return (len_str);
}

static int	ft_gen_str(char *str, int sign, int n)
{
	size_t	index;
	size_t	len_str;

	len_str = ft_get_len(n);
	index = 11;
	while (index > 0)
	{
		if (index + !sign > len_str)
			str[index] = '\0';
		else
		{
			str[index] = (n % 10) + '0';
			n /= 10;
		}
		--index;
	}
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	str[12];
	int		sign;

	ft_bzero(str, 12);
	if (n == 0)
		write(fd, "0", 1);
	else if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		sign = n < 0;
		if (sign)
		{
			str[0] = '-';
			n = -n;
		}
		n = ft_gen_str(str, sign, n);
		if (!sign)
			str[0] = (n % 10) + '0';
		write(fd, str, ft_strlen(str));
	}
}
