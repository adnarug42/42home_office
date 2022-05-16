/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:19:59 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/16 16:32:27 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putchar_printf(char c, lst_arg *arg, int fd)
{
	int		width;
	int		z;

	z = 0;
	width = arg->width;
	if (arg->is_minus == 0 && width != 0)
	{
		width = width - 1;
		while (width > 0)
		{
			write (1, " ", 1);
			width--;
			z++;
		}
	}
	write (1, &c, fd);
	if (arg->is_minus == 1 && width != 0)
	{
		width = width - 1;
		while (width > 0)
		{
			write (1, " ", 1);
			width--;
			z++;
		}
	}
	return (z + 1);
}
