/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlohmann <jlohmann@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:53:40 by jlohmann          #+#    #+#             */
/*   Updated: 2022/04/10 03:10:35 by jlohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*byte_s1;
	unsigned char	*byte_s2;

	byte_s1 = (unsigned char *)s1;
	byte_s2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*byte_s1 != *byte_s2)
			return (*byte_s1 - *byte_s2);
		++byte_s1;
		++byte_s2;
		--n;
	}
	return (0);
}
