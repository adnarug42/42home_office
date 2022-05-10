/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_decode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:58:09 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/10 12:13:58 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdio.h>

void	parse_args(const char *s, size_t z, lst_arg *out)
{
	size_t	arg_len;
	char	*str_arg;

	str_arg = NULL;
	arg_len = find_len(s, z);
	str_arg = ft_substr(s, z, arg_len);
	if (str_arg == NULL)
		return ;
	ft_decode_to_struct(str_arg, arg_len, out);
	free(str_arg);
	str_arg = NULL;
	return ;
}

void ft_decode_to_struct(char *str_arg, size_t i, lst_arg *out)
{
	size_t	counter;
	int		flag_or_zero;
	char	*address_dot;

	counter = 0;

	address_dot = NULL;
	out->specifier = str_arg[i - 1];
	out->length = i;
	flag_or_zero = 0;

	while (counter != i)
	{
		if (digit(str_arg[counter]) == 1 && flag_or_zero == 0)
			flag_or_zero = 1;
		if (str_arg[counter] == '#')
			out->is_hash = 1;
		if (str_arg[counter] == '-')
			out->is_minus = 1;
		if (str_arg[counter] == '0' && flag_or_zero == 0)
			out->is_zero = 1;
		if (str_arg[counter] == '+')
			out->is_plus = 1;
		if (str_arg[counter] == ' ')
			out->is_space = 1;
		if (str_arg[counter] == '.')
		{
			if (str_arg[counter + 1] == out->specifier)
				out->precision = 0;
			out->precision = ft_atoi(str_arg + counter + 1);
			address_dot = &str_arg[counter];
		}
		if ((digit(str_arg[counter]) == 1 && &str_arg[counter] < address_dot) || address_dot == NULL)
			out->width = ft_atoi(str_arg + counter - 1);
		counter++; 
	}
	if (address_dot != NULL)
		address_dot = NULL;
}
