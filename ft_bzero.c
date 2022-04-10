/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:29:08 by pguranda          #+#    #+#             */
/*   Updated: 2022/04/01 11:50:05 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_bzero(void *s, size_t n)
{
	char				*p;

	p = s;
	while (n > 0)
	{
		*p = '\0';
		p++;
		n--;
	}
}	
