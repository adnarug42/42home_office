/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:52:45 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/04 16:54:52 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"

void	put_pointer(void *pointer)
{
	unsigned int	address;

	address = (unsigned int)pointer;
	write(1, "0x10", 4);
	ft_hex_low(address);
	return	;
}