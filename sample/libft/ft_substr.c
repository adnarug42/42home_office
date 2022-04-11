/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawinter <mawinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:15:07 by mawinter          #+#    #+#             */
/*   Updated: 2022/03/26 17:17:21 by mawinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstring;
	int		i;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (len > slen)
		len = slen;
	if (start >= ft_strlen(s))
		return ((char *)ft_calloc(sizeof(char), 1));
	i = -1;
	newstring = (char *)malloc((len + 1) * sizeof(char));
	if (newstring == NULL)
		return (NULL);
	while ((size_t)(++i) < len && s[(unsigned int)i + start] != '\0')
		newstring[i] = s[i + start];
	newstring[i] = '\0';
	return (newstring);
}
