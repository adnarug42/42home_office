/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:22:54 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/01 13:24:52 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"
void ft_hex(int i)
{
	char	*hexa_num;
	int		r;
	int		counter;

	counter = 0;
	r = 0;
	hexa_num = malloc(sizeof(char) * 16);
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
			*hexa_num = r + 55;
			hexa_num++;
		}
		i = i / 16;
		counter++;
	}
   	*hexa_num = '\0';
	while (counter >= 0)
	{
		write (1, hexa_num - counter, 1);
		counter--;
	}
		write (1, &hexa_num[0], 1);
}
