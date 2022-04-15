/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlohmann <jlohmann@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:24:18 by jlohmann          #+#    #+#             */
/*   Updated: 2022/04/13 17:11:10 by jlohmann         ###   ########.fr       */
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

static char	*ft_gen_str(int n)
{
	char	*str;
	int		sign;
	size_t	len_str;

	sign = n < 0;
	if (sign)
		n = -n;
	len_str = sign + ft_get_len(n);
	str = malloc(sizeof(char) * (len_str + 1));
	if (!str)
		return (NULL);
	str += len_str;
	*(str--) = '\0';
	while (n > 0)
	{
		*(str--) = (n % 10) + '0';
		n /= 10;
	}
	if (sign)
		*str = '-';
	else
		++str;
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;

	if (n == 0)
	{
		str = malloc(sizeof(char) * 2);
		if (!str)
			return (NULL);
		ft_strlcpy(str, "0", 2);
		return (str);
	}
	else if (n == -2147483648)
	{
		str = malloc(sizeof(char) * 12);
		if (!str)
			return (NULL);
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	return (ft_gen_str(n));
}
