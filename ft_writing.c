/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:10:12 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/01 13:27:44 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"

void	ft_put_pointer(void *pointer);

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

		str_arg = NULL;
	if (first_arg->specifier == ('i') || first_arg->specifier == 'd')
		ft_putnbr_fd(va_arg(ap, int), 1);
	if (first_arg->specifier == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	if (first_arg->specifier == 's')
		ft_putstr_fd(va_arg(ap, char*), 1);
	if (first_arg->specifier == '%')
		write(1, "%%", 1);
	if (first_arg->specifier == 'p')
		ft_put_pointer(str_arg);
	if (first_arg->specifier == 'X')
		ft_hec_up(va_arg(ap, int));
	if (first_arg->specifier == 'x')
		ft_hex_low(va_arg(ap, int));
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
	write(1, "0x", 2);
	ft_putnbr_fd(&pointer, 1);
	////printf("address of pointer is: 0x%0X\n", (unsigned)&p);
    /////printf("address of pointer to pointer is: 0x%0X\n", (unsigned)&p_ptr);

}
