/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_decode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:58:09 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/05 16:35:46 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

lst_arg	*parse_args(const char *s, size_t z)
{
	lst_arg	*arg;
	size_t	arg_len;
	char	*str_arg;

	arg_len = 0;
	str_arg = NULL;
	arg_len = find_len(s, z);
	str_arg = malloc(arg_len + 1);
	if (str_arg == NULL)
		return (NULL);
	str_arg = ft_substr(s, z, arg_len);	
	arg = ft_decode_to_struct(str_arg, arg_len);
	free(str_arg);
	return (arg);
}

lst_arg *ft_decode_to_struct(char *s, size_t i)
{
	lst_arg	*arg;
	size_t	counter;
	int		flag_or_zero;
	char	*address_dot;

	counter = 0;
	address_dot = NULL;
	arg = malloc(sizeof(lst_arg));
	if (arg == NULL)
		return NULL;
	arg->specifier = s[i - 1];
	arg->length = i;
	flag_or_zero = 0;
	while (counter != i)
	{
		if (digit(s[counter]) == 1 && flag_or_zero == 0)
			flag_or_zero = 1;
		if (s[counter] == '#')
			arg->is_hash = 1;
		if (s[counter] == '-')
			arg->is_minus = 1;
		if (s[counter] == '0' && flag_or_zero == 0)
			arg->is_zero = 1;
		if (s[counter] == '+')
			arg->is_plus = 1;
		if (s[counter] == ' ')
			arg->is_space = 1;
		if (s[counter] == '.')
		{
			if (s[counter + 1] == arg->specifier)
				arg->precision = 0;
			arg->precision = ft_atoi(s + counter + 1);
			address_dot = &s[counter];
		}
		if (digit(s[counter]) == 1 && ((&s[counter] < address_dot) || address_dot == NULL))
			arg->width = ft_atoi(s + counter - 1);
		counter++; 
	}
	free(address_dot);
return (arg);
}

