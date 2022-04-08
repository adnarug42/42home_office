/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 09:43:32 by pguranda          #+#    #+#             */
/*   Updated: 2022/04/01 10:03:40 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char				*p_s;
	unsigned char				*element;

	p_s = (unsigned char *)s;
	element = NULL;
	while (*p_s != '\0' && n > 0)
	{
		if (*p_s == (unsigned char)c)
		{
			element = p_s;
			return (element);
		}
		n--;
		p_s++;
	}
	return (0);
}
