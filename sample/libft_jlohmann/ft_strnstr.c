/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlohmann <jlohmann@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:59:28 by jlohmann          #+#    #+#             */
/*   Updated: 2022/04/10 03:21:05 by jlohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i_haystack;
	size_t	i_needle;

	if (*needle == '\0')
		return ((char *)haystack);
	i_haystack = 0;
	while (haystack[i_haystack] != '\0' && i_haystack < len)
	{
		i_needle = 0;
		while ((needle[i_needle] != '\0' && i_haystack + i_needle < len))
		{
			if (haystack[i_haystack + i_needle] != needle[i_needle])
				break ;
			++i_needle;
		}
		if (needle[i_needle] == '\0')
			return ((char *)haystack + i_haystack);
		++i_haystack;
	}
	return (NULL);
}
