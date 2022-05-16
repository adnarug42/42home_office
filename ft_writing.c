/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:10:12 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/16 10:09:04 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void	write_struct(lst_arg *arg, va_list ap, int *counter)
{
		int		integer;
		int		*unsigned_counter;
		int		*hex_counter_low;
		int		*hex_counter_up;
	
		integer = 0;
		unsigned_counter = malloc(sizeof(size_t));
		*unsigned_counter = 0;
		hex_counter_low = malloc(sizeof(size_t));
		*hex_counter_low = 0;
		hex_counter_up = malloc(sizeof(size_t));
		if (arg->width != 0 && arg->is_minus == 0)
		{
			if (arg->is_zero == 0)
				*counter += ft_width(arg->width);
			else
				*counter += ft_zero(arg->width);
		}
		if (arg->specifier == 'i' || arg->specifier == 'd')
		{	
			integer = va_arg(ap, int);
			if (arg->is_plus == 1 || integer < 0)
				*counter += ft_sign(integer);
			if (arg->is_space == 1 && arg->is_plus != 0)
				*counter += ft_space_sign(integer);
			if (arg->precision != 0)
				*counter += ft_putnbr_with_zeroes(arg->precision, integer);
			else
				*counter += ft_putnbr_fd(integer, 1, 0);
		}
		if (arg->specifier == 'c')
			*counter += ft_putchar_fd(va_arg(ap, int), 1);
		if (arg->specifier == 's')
		{
			if (arg->precision != 0)
				*counter += ft_precision(va_arg(ap, char*), arg->precision);
			else
				*counter += ft_putstr_fd(va_arg(ap, char*), 1);
		}
		if (arg->specifier == '%')
		{
			*counter += 1;	
			write(1, "%%", 1);
		}
		if (arg->specifier == 'p')
			*counter += ft_put_pointer(va_arg(ap, void*));
		if (arg->specifier == 'X')
		{
			if (arg->is_hash == 1)
				write (1,"0X", 2);
			ft_hex_up(va_arg(ap, long), hex_counter_up);
			*counter += *hex_counter_up;
		}
		if (arg->specifier == 'x')
		{
			if (arg->is_hash == 1)
				write (1,"0x", 2);
			ft_hex_low(va_arg(ap, long), hex_counter_low);
			*counter += *hex_counter_low;
		}
		if (arg->specifier == 'u')
		{
			ft_putnbr_unsigned(va_arg(ap, unsigned int), 1, unsigned_counter);
			*counter += *unsigned_counter;
		}
		if (arg->width != 0 && arg->is_minus == 1)
			*counter += ft_width(arg->width);
		free(unsigned_counter);
		unsigned_counter = NULL;
		free(hex_counter_low);
		hex_counter_low = NULL;
		free(hex_counter_up);
		hex_counter_up = NULL;
}
