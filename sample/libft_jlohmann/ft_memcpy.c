/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlohmann <jlohmann@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:09:01 by jlohmann          #+#    #+#             */
/*   Updated: 2022/04/12 00:19:04 by jlohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*char_src;
	char		*char_dst;

	char_src = src;
	char_dst = dst;
	if (!dst && !src)
		return (NULL);
	while (n > 0)
	{
		*(char_dst++) = *(char_src++);
		--n;
	}
	return (dst);
}
