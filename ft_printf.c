/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:40:44 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/17 11:36:32 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"


int ft_printf(const char *s, ...)
{
	va_list			ap;
	int				i;
	lst_arg			*arg;
	int				*str_len;

	str_len = malloc(sizeof(int));
	*str_len = 0;
	arg = malloc(sizeof(lst_arg));
	if (arg == NULL)
		return 0;
	i = 0;
	va_start(ap, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			parse_args(s, i + 1, arg);
			write_struct(arg, ap, str_len);
			i += arg->length;
			//*str_len += i - arg->length;
			arg->width = 0;
		}
		else
		{
			write(1, &s[i], 1);
			*str_len += 1;
		}
		i++;
	}
	va_end (ap);
//  printf(" \n \n hash: %i \n minus: %i \n zero: %i \n plus: %i \n space: %i \n width: %d \n\
//  precision: %d \n length: %zu \n specifier: %c \n \n", arg->is_hash, arg->is_minus, arg->is_zero, arg->is_plus, arg->is_space, arg->width, arg->precision, arg->length, arg->specifier);
	
	//printf ("str_len: %d i: %d\n ", *str_len, i);
	free(arg);
	arg = NULL;
	i = *str_len;
	free(str_len);
	return (i);
}
