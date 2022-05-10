/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:50:51 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/10 15:33:21 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int ft_width(size_t width)
{
	int	counter;

	counter = 0;
	while (width > 0)
	{
		write (1, " ", 1);
		--width;
		counter++;
	}
	return (counter);
}