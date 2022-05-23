/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:09:09 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/23 16:08:16 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void ft_minus_width(int (*f)(int, int *, int *), lst_arg *arg, int integer, int *sub_counter)
{
	int	len;
	int	width;
	int	*sign_flag;

	len = 0;
	width = arg->width;
	sign_flag = malloc(sizeof(size_t));
	*sign_flag = 0;
	if (width > 0 && arg->is_minus == 0)
	{
		while (width > 0)
		{
			write (1, " ", 1);
			width--;
			*sub_counter += 1;
		} 
	}
	if (arg->precision )
	len = f(integer, sub_counter, sign_flag);
	// printf ("width %d len %d integer %d sub counter %d sign flag %d", width, len, integer, *sub_counter, *sign_flag);
	if (*sign_flag == 1)
		len += 1;
	if (arg->is_minus == 1 && width > len)
	{
		width = width - len;
		while (width > 0)
		{
			write (1, " ", 1);
			width--;
			*sub_counter += 1;
		} 
	}
	free(sign_flag);
}