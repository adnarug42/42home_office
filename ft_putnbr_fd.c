/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:45:26 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/04 15:20:34 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"

void	putnbr_with_zeros(int precision, int num)
{
	int	i;
	int diff;

	i = 0;
	diff = 0;
	while (num != 0)
	{
		num = num/10;
		i++;
	}
	if (i <= precision)
	{
		write (1, "0", 1);
		i++;
	}
	ft_putnbr_fd(num, 1);
}