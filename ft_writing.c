/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:10:12 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/04 18:02:22 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void	write_struct(lst_arg *arg, va_list ap)
{
		char	*str_arg;
		int		integer;

		str_arg = NULL;
		integer = 0;
		if (arg->width != 0 && arg->is_minus == 0)
		{
			if (arg->is_zero == 0)
				ft_width(arg->width);
			else
				ft_zero(arg->width);
		}
		if (arg->specifier == 'i' || arg->specifier == 'd')
		{	
			integer = va_arg(ap, int);
			if (arg->is_plus == 1)
				sign(integer);
			if (arg->is_space == 1 && arg->is_plus != 0)
				space_sign(integer);
			if (arg->precision != 0)
				putnbr_with_zeroes(arg->precision, integer);
			else
				ft_putnbr_fd(integer, 1);
		}
		if (arg->specifier == 'c')
			ft_putchar_fd(va_arg(ap, int), 1);
		if (arg->specifier == 's')
		{
			if (arg->precision != 0)
				ft_precision(va_arg(ap, char*), arg->precision);
			else
				ft_putstr_fd(va_arg(ap, char*), 1);
		}
		if (arg->specifier == '%')
			write(1, "%%", 1);
		if (arg->specifier == 'p')
			put_pointer(va_arg(ap, void*));
		if (arg->specifier == 'X')
		{
			if (arg->is_hash == 1)
				write (1,"0X", 2);
			ft_hex_up(va_arg(ap, int));
		}
		if (arg->specifier == 'x')
		{
			if (arg->is_hash == 1)
				write (1,"0x", 2);
			ft_hex_low(va_arg(ap, int));
		}
		if (arg->specifier == 'u')
			ft_putnbr_unsigned(va_arg(ap, unsigned int), 1);
		if (arg->width != 0 && arg->is_minus == 1)
			ft_width(arg->width);
}
