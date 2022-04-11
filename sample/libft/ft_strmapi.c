/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawinter <mawinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:25:59 by mawinter          #+#    #+#             */
/*   Updated: 2022/03/26 14:41:23 by mawinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*newstring;
	int		size;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	size = ft_strlen(s) + 1;
	newstring = (char *)malloc(sizeof(char) * size);
	if (newstring == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		newstring[i] = (*f)(i, s[i]);
		i++;
	}
	newstring[i] = '\0';
	return (newstring);
}
