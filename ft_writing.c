/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:10:12 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/24 13:25:02 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdio.h>

void	write_struct(lst_arg *arg, va_list ap, int *counter)
{
		int		integer;
		int		*sub_counter;
	
		integer = 0;
		sub_counter = malloc (sizeof(size_t));
		*sub_counter = 0;

		/*if (arg->width != 0 && arg->is_minus == 0)
		{
			if (arg->is_zero == 0)
				*counter += ft_width(arg->width);
			else
				*counter += ft_zero(arg->width);
		}*/
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
			{
				ft_minus_width(ft_putnbr_printf, arg, integer, sub_counter);
				*counter += *sub_counter;
			}
		}
		if (arg->specifier == 'c')
				*counter += ft_putchar_printf(va_arg(ap, int), arg, 1);
		if (arg->specifier == 's')
		{
			if (arg->precision != 0)
				*counter += ft_precision_string(va_arg(ap, char*), arg->precision);
			else
				*counter += ft_putstr_printf(va_arg(ap, char*), arg, 1);
		}
		if (arg->specifier == '%')
		{
			*counter += 1;	
			write(1, "%%", 1);
		}
		if (arg->specifier == 'p')
			*counter += ft_put_pointer(va_arg(ap, void*), arg);
		if (arg->specifier == 'X')
		{
			if (arg->is_hash == 1)
				write (1,"0X", 2);
			if (arg->precision != 0)
				ft_precision_hex_up(arg->precision, va_arg(ap, int long), sub_counter);
			else
				ft_minus_width(ft_hex_up, arg, va_arg(ap, int long), sub_counter);
			*counter += *sub_counter;
		}
		if (arg->specifier == 'x')
		{
			if (arg->is_hash == 1)
				write (1,"0x", 2);
			if (arg->precision != 0)
				ft_precision_hex_low(arg->precision, va_arg(ap, int long), sub_counter);
			else 
				ft_minus_width(ft_hex_low, arg, va_arg(ap, int long), sub_counter);
			*counter += *sub_counter;
		}
		if (arg->specifier == 'u')
		{
			if (arg->precision != 0)
				 ft_precision_unsigned(arg->precision, va_arg(ap, int), sub_counter);
			else
			
				ft_minus_width(ft_putnbr_unsigned, arg, va_arg(ap, unsigned int), sub_counter);
			*counter += *sub_counter;
			
		}
		// if (arg->width != 0 && arg->is_minus == 1)
		// 	*counter += ft_width(arg->width);
		free(sub_counter);
		sub_counter= NULL;
}
