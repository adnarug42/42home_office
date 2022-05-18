/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:09:09 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/18 13:32:30 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void ft_minus_width(int (*f)(int, int *), lst_arg *arg, int integer, int *sub_counter)
{
	int	len;
	int	width;

	len = 0;
	width = arg->width;
	len = f(integer, sub_counter);
	if (integer < 0)
		len++;
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
}