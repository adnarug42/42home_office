/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_low.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:22:54 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/04 18:03:47 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void ft_hex_low(unsigned int i)
{
	char	*hexa_num;
	int		r;
	int		counter;
	int		z;

	counter = 0;
	r = 0;
	z = 0;
	hexa_num = malloc(sizeof(char) * 16);
	if (hexa_num == NULL)
		return ;
	while (i != 0)
	{
		r = i % 16;
		if (r < 10)
		{
			*hexa_num = r + 48;
			hexa_num++;
		}
		else
		{
			*hexa_num = r + 87;
			hexa_num++;
		}
		i = i / 16;
		counter++;
	}
	while (counter >= 0)
	{
		write (1, hexa_num-- , 1);
		counter--;
	}
}
