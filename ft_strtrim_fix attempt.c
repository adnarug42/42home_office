/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:35:22 by pguranda          #+#    #+#             */
/*   Updated: 2022/04/15 16:16:27 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <unistd.h>
#include <stdlib.h>
#include <string.h>*/

unsigned int    ft_trim_front(char const *s1, char const *set);
unsigned int    ft_trim_back(char const *s1, char const *set);

char    *ft_strtrim(char const *s1, char const *set)
{
	char                *s1_final;
	unsigned int        i_front;
	unsigned int        i_back;
	int                    i;
	size_t				en;

	i = 0;
	i_front = ft_trim_front(s1, set);
	i_back = ft_trim_back (s1, set);
	len = strlen((char *)s1);
	s1_final = (char *)malloc((len - i_front - i_back + 1 )*sizeof(char));
	if (s1 == NULL || set == NULL || s1_final == NULL)
		return (NULL);
	while (i_front < (len - i_back))
	{
		s1_final[i] = s1[i_front];
		i++;
		i_front++;
	}
	s1_final[i] = '\0';
	return (s1_final);
}

unsigned int	ft_trim_front(char const *s1, char const *set)
{
	unsigned int	i;

	i = 0;
	while (strchr(set, *s1) != NULL && *s1 != '\0')
	{
		s1++;
		i++;
	}
	return (i);
}

unsigned int	ft_trim_back(char const *s1, char const *set)
{
	unsigned int	len;
	unsigned int	i;

	i = 0;
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[len]) != NULL && *s1 != '\0')
	{
		len--;
		i++;
	}
	i--;
	return (i);
}


int main()
{
	ft_strtrim ("123Privet123", "123");
	return (0);
}