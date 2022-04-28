/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decode_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:58:09 by pguranda          #+#    #+#             */
/*   Updated: 2022/04/28 16:34:41 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"

//1. takes the char and the struct, returns a struct
int	ft_digit(int c);

lst_arg *ft_decode_char(char *s, size_t i)
{
	lst_arg	*arg;
	size_t	counter;
	int		flag_or_zero;
	char	*address_dot;

	counter = 0;
	address_dot = NULL;
	arg = malloc(sizeof(lst_arg));
	arg->specifier = s[i - 1];
	flag_or_zero = 0;
	while (counter != (i - 1))
	{
		if (ft_digit(s[counter]) == 1 && flag_or_zero == 0)
			flag_or_zero = 1;
		if (ft_strchr(FLAGS, s[counter]) != NULL)
		{
			if ((s[counter] == '0' && flag_or_zero == 0) || (s[counter] != '0'))
				arg->flags = s[counter];
		}
		if (s[counter] == '.')
		{
			arg->precision = ft_atoi(s + counter + 1);
			address_dot = &s[counter];
		}
		if (ft_isdigit(s[counter]) == 1 && ((&s[counter] < address_dot) || address_dot == 0))
			arg->width = ft_atoi(s + counter - 1);
		counter++; 
	}
return (arg);
}

int	ft_digit(int c)
{
	if (c > '0' && c <= '9')
		return (1);
	return (0);
}
