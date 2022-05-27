/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_zeroes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:51:59 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/27 15:10:11 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_write_zeroes(int width, int *sub_counter)
{
	while (width > 0)
	{
		write (1, "0", 1);
		width--;
		*sub_counter += 1;
	}
}
