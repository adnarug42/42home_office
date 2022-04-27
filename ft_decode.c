/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:58:09 by pguranda          #+#    #+#             */
/*   Updated: 2022/04/27 16:32:22 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"

//1. takes the char and the struct, returns a struct

lst_arg *ft_decode_char(char *s, size_t i, lst_arg *arg)
{
	size_t	counter;
	char	*address_dot;

	counter = 0;
	address_dot = NULL;
	arg->specifier = (char)s[i - 1];
	while (counter != i - 1)
	{
		if (ft_strchr(SPECIFIERS, s[counter]))
			arg->specifier = s[counter];
		if (ft_strchr(FLAGS, s[counter]))
			arg->flags = s[counter];
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