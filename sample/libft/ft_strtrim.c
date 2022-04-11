/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawinter <mawinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:48:16 by mawinter          #+#    #+#             */
/*   Updated: 2022/03/26 14:41:13 by mawinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	in_set(char c, char const *set)
{
	int	i;
	int	setlen;

	setlen = ft_strlen(set);
	i = 0;
	while (i < setlen)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	counterfront(char const *s1, char const *set)
{
	int	i;
	int	count;
	int	firstnotinset;
	int	len;

	len = ft_strlen(s1);
	firstnotinset = 0;
	count = 0;
	i = 0;
	while (i < len && !firstnotinset)
	{
		if (in_set(s1[i], set))
			count++;
		else
			firstnotinset = 1;
		i++;
	}
	return (count);
}

int	counterback(char const *s1, char const *set)
{
	int	count;
	int	firstnotinset;
	int	len;

	len = ft_strlen(s1) - 1;
	firstnotinset = 0;
	count = 0;
	while (len >= 0 && !firstnotinset)
	{
		if (in_set(s1[len], set))
			count++;
		else
			firstnotinset = 1;
		len--;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*newstring;
	int		i;
	size_t	skipfront;
	size_t	skipback;

	if (s1 == NULL || set == NULL)
		return (NULL);
	skipfront = counterfront(s1, set);
	skipback = counterback(s1, set);
	if (skipback == ft_strlen(s1) || skipfront == ft_strlen(s1))
		return ((char *)ft_calloc(sizeof(char), (1)));
	len = ft_strlen(s1) - (skipfront + skipback);
	i = -1;
	newstring = (char *)malloc((len + 1) * sizeof(char));
	if (newstring == NULL)
		return (NULL);
	while (++i < len)
		newstring[i] = s1[skipfront + i];
	newstring[i] = '\0';
	return (newstring);
}
