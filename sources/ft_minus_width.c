/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:09:09 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/17 17:05:08 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void ft_minus_width(int (*f)(int, int*), lst_arg *arg, int integer, int *counter)
{
	int	len;
	int	width;

	len = 0;
	width = arg->width;
	len = f(integer, counter);
	if (arg->is_minus == 1 && width > len)
	{
		width = width - len;
		while (width > 0)
		{
			write (1, " ", 1);
			width--;
			*counter += 1;
		}
		*counter += 1;
	}
}