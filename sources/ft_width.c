/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:50:51 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/16 17:03:13 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int ft_width(int width)
{
	int	counter;

	counter = 0;
	while (width > 1)
	{
	//	write (1, " ", 1);
		width--;
		counter++;
	}
	return (counter);
}