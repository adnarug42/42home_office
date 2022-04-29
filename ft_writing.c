/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:10:12 by pguranda          #+#    #+#             */
/*   Updated: 2022/04/29 13:22:22 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"

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
	if (first_arg->specifier == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1);
}

size_t	find_len(const char *s, size_t arg_start)
{
	size_t	len;

	len = 0;
	while (ft_strchr(SPECIFIERS, s[arg_start + len]) == NULL)
		len++;
	return (len + 1);
}
