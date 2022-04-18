/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:54:27 by mawinter          #+#    #+#             */
/*   Updated: 2022/04/18 15:10:57 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstring;
	int		i;
	int		len1;
	int		len2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	newstring = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (newstring == NULL)
		return (NULL);
	while (i < len1)
	{
		newstring[i] = s1[i];
		i++;
	}
	i = -1;
	while (++i < len2)
		newstring[len1 + i] = s2[i];
	newstring[len1 + len2] = '\0';
	return (newstring);
}
