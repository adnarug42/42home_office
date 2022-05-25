/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:10:12 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/25 16:19:42 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"


static void	write_int_dec(int integer, t_arg *arg, \
			int *counter, int *sub_counter);
static void	write_str(char *s, t_arg *arg, int *counter, int *sub_counter);
static void	write_hex(int long num, t_arg *arg, \
			int *counter, int *sub_counter);
static void	write_unsigned(int num, t_arg *arg, \
			int *counter, int *sub_counter);

void	write_struct(t_arg *arg, va_list ap, int *counter)
{
	int		integer;
	int		*sub_counter;

	integer = 0;
	sub_counter = malloc (sizeof(size_t));
	*sub_counter = 0;
	if (arg->specifier == 'i' || arg->specifier == 'd')
		write_int_dec(va_arg(ap, int), arg, counter, sub_counter);
	if (arg->specifier == 'c')
		*counter += ft_putchar_printf(va_arg(ap, int), arg, sub_counter);
	if (arg->specifier == 's')
		write_str(va_arg(ap, char *), arg, counter, sub_counter);
	if (arg->specifier == '%')
	{
		*counter += 1;
		write(1, "%%", 1);
	}
	if (arg->specifier == 'p')
		*counter += ft_put_pointer(va_arg(ap, void *), arg, sub_counter);
	if (arg->specifier == 'X' || arg->specifier == 'x')
		write_hex(va_arg(ap, long int), arg, counter, sub_counter);
	if (arg->specifier == 'u')
		write_unsigned(va_arg(ap, int), arg, counter, sub_counter);
	free(sub_counter);
	sub_counter = NULL;
}

static void	write_int_dec(int integer, t_arg *arg, \
			int *counter, int *sub_counter)
{
	if (arg->is_plus == 1 || integer < 0)
		*counter += ft_sign(integer);
	if (arg->is_space == 1 && arg->is_plus != 0)
		*counter += ft_space_sign(integer);
	if (arg->precision != 0)
		*counter += ft_putnbr_with_zeroes(arg->precision, integer, sub_counter);
	else
	{
		ft_minus_width(ft_putnbr_printf, arg, integer, sub_counter);
		*counter += *sub_counter;
	}
}

static void	write_str(char *s, t_arg *arg, int *counter, int *sub_counter)
{
	if (arg->precision != 0)
		*counter += ft_precision_string(s, arg->precision);
	else
		*counter += ft_putstr_printf(s, arg, sub_counter);
}

static void	write_hex(int long num, t_arg *arg, \
			int *counter, int *sub_counter)
{
	if (arg->specifier == 'X')
	{
		if (arg->is_hash == 1)
		{
			write (1, "0X", 2);
			*counter += 2;
		}
		if (arg->precision != 0)
			ft_precision_hex_up(arg->precision, num, sub_counter);
		else
			ft_minus_width(ft_hex_up, arg, num, sub_counter);
	}
	if (arg->specifier == 'x')
	{
		if (arg->is_hash == 1)
		{
			write (1, "0x", 2);
			*counter += 2;
		}
		if (arg->precision != 0)
			ft_precision_hex_low(arg->precision, num, sub_counter);
		else
			ft_minus_width(ft_hex_low, arg, num, sub_counter);
	}
		*counter += *sub_counter;
}

static void	write_unsigned(int num, t_arg *arg, \
			int *counter, int *sub_counter)
{
	if (arg->precision != 0)
		ft_precision_unsigned(arg->precision, num, sub_counter);
	else
		ft_minus_width(ft_putnbr_unsigned, arg, num, sub_counter);
	*counter += *sub_counter;
}
