/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:35:22 by pguranda          #+#    #+#             */
/*   Updated: 2022/04/08 10:04:22 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_trim_front(char *s1, char const *set);
char	*ft_trim_back(char *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char				*s1_trimmed;
	char				*s1_final;
	int					i;

	i = 0;
	s1_trimmed = ft_strdup(s1);
	ft_trim_front(s1_trimmed, set);
	ft_trim_back (s1_trimmed, set);
	s1_final = (char *)malloc(ft_strlen(s1_trimmed) + 1);
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1_trimmed == 127)
		s1_trimmed++;
	while (*s1_trimmed != 127 && *s1_trimmed != '\0')
	{
		s1_final[i] = *s1_trimmed;
		i++;
		s1_trimmed++;
	}
	s1_final[i] = '\0';
	return (s1_final);
}

char	*ft_trim_front(char *s1, char const *set)
{
	while (ft_strchr(set, s1[0]) != NULL && *s1 != '\0')
	{
		s1[0] = 127;
		s1++;
	}
	return (s1);
}

char	*ft_trim_back(char *s1, char const *set)
{
	unsigned int				len;

	len = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[len]) != NULL && *s1 != '\0')
	{
		s1[len] = 127;
		len--;
	}
	return (s1);
}
