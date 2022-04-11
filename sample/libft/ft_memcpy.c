/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawinter <mawinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:05:09 by mawinter          #+#    #+#             */
/*   Updated: 2022/03/26 14:42:31 by mawinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	char				*d;
	char				*s;

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	while (i < n && (dst || src))
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
