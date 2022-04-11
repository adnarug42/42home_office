/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawinter <mawinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:48:33 by mawinter          #+#    #+#             */
/*   Updated: 2022/03/25 18:09:37 by mawinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	cchar;
	unsigned char	*ss;
	size_t			i;

	cchar = (unsigned char)c;
	ss = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ss[i] == cchar)
			return ((void *)s + i);
		i++;
	}
	return ((void *)0);
}
