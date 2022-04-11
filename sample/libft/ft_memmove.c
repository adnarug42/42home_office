/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawinter <mawinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:57:18 by mawinter          #+#    #+#             */
/*   Updated: 2022/03/26 14:42:23 by mawinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	*chardest;
	char	*charsrc;

	i = -1;
	if (!dest && !src)
		return (dest);
	if (dest < src)
	{
		chardest = (char *) dest;
		charsrc = (char *)src;
		while ((size_t)++i < n)
			chardest[i] = charsrc[i];
		return (dest);
	}
	else
	{
		chardest = (char *) dest + n - 1;
		charsrc = (char *)src + n - 1;
		while ((size_t)++i < n)
			*chardest-- = *charsrc--;
		return (dest);
	}
}
