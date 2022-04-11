/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawinter <mawinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:58:20 by mawinter          #+#    #+#             */
/*   Updated: 2022/03/26 14:43:06 by mawinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	getdigits1(int n)
{
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n = -1 * n;
	if (n < 10)
		return (1);
	return (1 + getdigits1(n / 10));
}

int	getsign(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

void	putsignorlas(int sign, char *str, int i, int n)
{
	if (sign)
		str[i] = '-';
	else
		str[i] = (n % 10) + 48;
}

char	*ft_itoa(int n)
{
	char	*str;
	int		dg;
	int		sign;
	int		i;

	sign = getsign(n);
	dg = getdigits1(n);
	str = (char *)malloc(sizeof(char) * (dg + 1 + sign));
	if (str == NULL)
		return (NULL);
	i = (dg + sign);
	str[i--] = '\0';
	while (i > 0)
	{
		if (n % 10 < 0)
			str[i--] = (n % 10) * -1 + 48;
		else
			str[i--] = (n % 10) + 48;
		n = n / 10;
	}
	putsignorlas(sign, str, i, n);
	return (str);
}
