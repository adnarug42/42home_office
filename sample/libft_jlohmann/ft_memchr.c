/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlohmann <jlohmann@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:25:09 by jlohmann          #+#    #+#             */
/*   Updated: 2022/04/10 03:09:59 by jlohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*char_s;
	unsigned char	char_c;

	char_c = c;
	char_s = (unsigned char *)s;
	while (n > 0)
	{
		if (*char_s == char_c)
			return (char_s);
		++char_s;
		--n;
	}
	return (NULL);
}
