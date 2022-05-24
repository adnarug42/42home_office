/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:40:44 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/24 17:05:46 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdio.h> //TO REMOVE

static void	find_args(const char *s, va_list ap, int *str_len, lst_arg *arg);

int	ft_printf(const char *s, ...)
{
	va_list			ap;
	lst_arg			*arg;
	int				i;
	int				*str_len;

	str_len = malloc(sizeof(int));
	arg = malloc(sizeof(lst_arg));
	if (arg == NULL)
		return (0);
	*str_len = 0;
	i = 0;
	va_start(ap, s);
	find_args(s, ap, str_len, arg);
	va_end(ap);
 	// // printf(" \n \n hash: %i \n minus: %i \n zero: %i \n plus: %i \n space: %i \n width: %d \n\
 	// // precision: %d \n length: %zu \n specifier: %c \n \n", arg->is_hash, arg->is_minus, arg->is_zero, arg->is_plus, arg->is_space, arg->width, arg->precision, arg->length, arg->specifier);
	// printf ("str_len: %d i: %d\n", *str_len, i);
	i = *str_len;
	free(arg);
	arg = NULL;
	free(str_len);
	str_len = NULL;
	return (i);
}

/*searching for args, parsing into struct and writing,
while counting the length*/
static void	find_args(const char *s, va_list ap, int *str_len, lst_arg *arg)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			parse_args(s, i + 1, arg);
			write_struct(arg, ap, str_len);
			i += arg->length;
			arg->width = 0;
		}
		else
		{
			write(1, &s[i], 1);
			*str_len += 1;
		}
		i++;
	}
}
