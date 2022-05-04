/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:10:22 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/04 18:12:17 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void sign(int i)
{
	if (i >= 0)
		write (1, "+", 1);
	if (i < 0)
		write (1, "-", 1);
}