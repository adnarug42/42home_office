/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:55:54 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/23 16:09:12 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_precision_string(char *str, int i)
{
	int	counter;

	counter = 0;
	if (i == -1)
		return 0;
	//printf ("length: %d", i);
		while(i != 0 && str[counter] != '\0')
		{
			write(1, &str[counter], 1);
			counter++;
			i--;
		}
	return (counter);
}