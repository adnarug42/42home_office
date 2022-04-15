/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlohmann <jlohmann@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:35:32 by jlohmann          #+#    #+#             */
/*   Updated: 2022/04/10 03:25:42 by jlohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*char_src;
	char		*char_dst;

	char_src = src;
	char_dst = dst;
	if (src == dst)
		return (dst);
	else if (src < dst)
	{
		while (len > 0)
		{
			--len;
			char_dst[len] = char_src[len];
		}
	}
	else
	{
		while (len > 0)
		{
			*(char_dst++) = *(char_src++);
			--len;
		}
	}
	return (dst);
}
