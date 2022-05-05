/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:55:54 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/05 14:54:56 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_precision(char *str, int i)
{
	int	counter;

	counter = 0;
	while(counter < i)
	{
		write(1, &str[counter], 1);
		counter++;
	}
}