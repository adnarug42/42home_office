/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlohmann <jlohmann@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:21:49 by jlohmann          #+#    #+#             */
/*   Updated: 2022/04/12 00:15:12 by jlohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	memsize;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	memsize = ft_strlen(s1);
	memsize += ft_strlen(s2);
	ptr = malloc(sizeof(char) * (memsize + 1));
	if (!ptr)
		return (NULL);
	while (*s1 != '\0')
		*(ptr++) = *(s1++);
	while (*s2 != '\0')
		*(ptr++) = *(s2++);
	*ptr = '\0';
	return (ptr - memsize);
}
