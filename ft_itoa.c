/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:06:04 by pguranda          #+#    #+#             */
/*   Updated: 2022/04/11 14:25:00 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define LONG_MIN -2147483648

int		ft_count_digits(int n);
char	*ft_allocation(int n, char *s);

char	*ft_itoa(int n)
{
	char				*s;
	int					i;
	char				s_null;

	s_null = '0';
	i = 0;
	if (n == LONG_MIN)
	{
		s = (char *)(malloc(12));
		ft_strlcpy(s, "-2147483648", 12);
		return (s);
	}
	s = (char *)malloc((ft_count_digits(n) + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	s = ft_allocation(n, s);
	return (s);
}

int	ft_count_digits(int n)
{
	int				counter;
	int				digit;

	counter = 0;
	digit = 0;
	if (n < 0)
	{
		counter++;
		n *= -1;
	}
	while (n >= 10)
	{
		digit = n % 10;
		n = n / 10;
		counter++;
	}
	counter++;
	return (counter);
}

char	*ft_allocation(int n, char *s)
{
	int				i;
	int				digit;
	int				len;

	i = 0;
	digit = 0;
	len = ft_count_digits(n);
	s[len] = '\0';
	len--;
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	while (n >= 10)
	{
		digit = n % 10;
			s[len] = digit + '0';
			len--;
			n = n / 10;
	}
	s[len] = n + '0';
	return (s);
}
