/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlohmann <jlohmann@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:51:48 by jlohmann          #+#    #+#             */
/*   Updated: 2022/04/12 00:16:05 by jlohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*ptr;
	size_t		memsize;

	if (!s1 || !set)
		return (NULL);
	while (*s1 != '\0' && ft_strchr(set, *s1))
		++s1;
	memsize = ft_strlen(s1);
	if (memsize > 0)
	{
		while (ft_strchr(set, s1[memsize - 1]))
			--memsize;
	}
	ptr = malloc(sizeof(char) * (memsize + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, memsize + 1);
	return (ptr);
}
