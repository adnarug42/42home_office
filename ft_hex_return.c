/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_return.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:56:28 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/02 14:56:53 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"

void ft_hex_return(unsigned int i)
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
