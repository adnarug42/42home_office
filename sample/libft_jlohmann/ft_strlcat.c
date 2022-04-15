/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlohmann <jlohmann@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:10:16 by jlohmann          #+#    #+#             */
/*   Updated: 2022/04/13 19:42:08 by jlohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = 0;
	while (dstsize > 0 && dst[dst_len] != '\0')
	{
		dst_len++;
		dstsize--;
	}
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (dst_len + src_len);
	if (src_len < dstsize)
		ft_memcpy(dst + dst_len, src, src_len + 1);
	else
	{
		ft_memcpy(dst + dst_len, src, dstsize - 1);
		dst[dst_len + dstsize - 1] = '\0';
	}
	return (dst_len + src_len);
}
