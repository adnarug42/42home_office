/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:52:45 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/11 17:51:50 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_put_pointer(void *pointer)
{
	int counter;
	unsigned long	address;

	counter = 0;
	address = (unsigned long)pointer;
	write(1, "0x", 2);
	counter = ft_hex_low(address);
	counter += 2; 
	return (counter + 1);
}
