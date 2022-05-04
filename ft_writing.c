/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:10:12 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/04 16:34:46 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"

void	ft_put_pointer(void *pointer);
void	putnbr_with_zeros(int precision, int num);
void 	sign(int i);
void space_sign(int i);

lst_arg	*ft_decode_all(const char *s, size_t z)
{
	lst_arg	*first_arg;
	size_t	arg_len;
	char	*str_arg;

	arg_len = 0;
	str_arg = 0;
	arg_len = find_len(s, z);
	str_arg = ft_substr(s, z, arg_len);	
	first_arg = ft_decode_char(str_arg, arg_len);
	return (first_arg);
}


void	write_decoded(lst_arg *first_arg, va_list ap)
{
		char	*str_arg;
		int		integer;

		str_arg = NULL;
		integer = 0;
		if (first_arg->width != 0 && first_arg->is_minus == 0)
		{
			if (first_arg->is_zero == 0)
				ft_width(first_arg->width);
			else
				ft_zero(first_arg->width);
		}
		if (first_arg->specifier == 'i' || first_arg->specifier == 'd')
		{	
			integer = va_arg(ap, int);
			if (first_arg->is_plus == 1)
				sign(integer);
			if (first_arg->is_space == 1 && first_arg->is_plus != 0)
				space_sign(integer);
			if (first_arg->precision != 0)
				putnbr_with_zeros(first_arg->precision, integer);
			else
				ft_putnbr_fd(integer, 1);
		}
		if (first_arg->specifier == 'c')
			ft_putchar_fd(va_arg(ap, int), 1);
		if (first_arg->specifier == 's')
		{
			if (first_arg->precision != 0)
				ft_precision(va_arg(ap, char*), first_arg->precision);
			else
				ft_putstr_fd(va_arg(ap, char*), 1);
		}
		if (first_arg->specifier == '%')
			write(1, "%%", 1);
		if (first_arg->specifier == 'p')
			ft_put_pointer(va_arg(ap, void*));
		if (first_arg->specifier == 'X')
		{
			if (first_arg->is_hash == 1)
				write (1,"0X", 2);
			ft_hex_up(va_arg(ap, int));
		}
		if (first_arg->specifier == 'x')
		{
			if (first_arg->is_hash == 1)
				write (1,"0x", 2);
			ft_hex_low(va_arg(ap, int));
		}
		if (first_arg->specifier == 'u')
			ft_putnbr_unsigned(va_arg(ap, unsigned int), 1);
		if (first_arg->width != 0 && first_arg->is_minus == 1)
			ft_width (first_arg->width);
		/*if(first_arg->flags == '-')
			ft_left_justified*/
}

size_t	find_len(const char *s, size_t arg_start)
{
	size_t	len;

	len = 0;
	while (ft_strchr(SPECIFIERS, s[arg_start + len]) == NULL)
		len++;
	return (len + 1);
}

void	ft_put_pointer(void *pointer)
{
	unsigned int	address;

	address = (unsigned int)pointer;
	write(1, "0x10", 4);
	ft_hex_low(address);
	return	;
}


void	putnbr_with_zeros(int precision, int num)
{
	int	i;
	int diff;
	int num2;

	i = 0;
	diff = 0;
	num2 = num;
	while (num != 0)
	{
		num = num/10;
		i++;
	}
	while (i < precision)
	{
	
		write (1, "0", 1);
		i++;
	}
	ft_putnbr_fd(num2, 1);
}

void sign(int i)
{
	if (i >= 0)
		write (1, "+", 1);
	if (i < 0)
		write (1, "-", 1);
}

void space_sign(int i)
{
	if (i >= 0)
		write (1, " ", 1);
	if (i < 0)
		write (1, "-", 1);
}