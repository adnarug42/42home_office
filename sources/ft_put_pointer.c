/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:52:45 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/12 17:24:41 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_put_pointer(void *pointer)
{
	int counter;
	unsigned long	address;
	int	*hex_counter;

	hex_counter = malloc(sizeof(int));
	*hex_counter = 0;
	counter = 0;
	address = (unsigned long)pointer;
	write(1, "0x", 2);
	ft_hex_low_pointer(address, hex_counter);
	counter = 2 + *hex_counter; 
	free(hex_counter);
	hex_counter = NULL;
	return (counter);
}
