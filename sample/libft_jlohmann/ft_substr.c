/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlohmann <jlohmann@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:18:31 by jlohmann          #+#    #+#             */
/*   Updated: 2022/04/10 04:22:26 by jlohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start > size || size == 0)
		return (ft_strdup(""));
	s += start;
	size -= start;
	if (size > len)
		size = len;
	ptr = malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	len = size;
	while (size > 0)
	{
		*(ptr++) = *(s++);
		--size;
	}
	*ptr = '\0';
	return (ptr - len);
}
