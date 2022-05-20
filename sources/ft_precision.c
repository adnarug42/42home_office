/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:55:54 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/20 12:27:05 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

int	ft_precision(char *str, int i)
{
	int	counter;

	counter = 0;
	if (i != -1)
	{
	//printf ("length: %d", i);
		while(counter < i)
		{
			write(1, &str[counter], 1);
			counter++;
		}
	}
	else
		counter = 1;
	return (counter - 1);
}