/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_sign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:12:24 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/25 15:46:12 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_space_sign(int i)
{
	int	counter;

	counter = 1;
	if (i >= 0)
		write (1, " ", 1);
	if (i < 0)
		write (1, "-", 1);
	return (counter);
}
