/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:15:23 by pguranda          #+#    #+#             */
/*   Updated: 2022/04/15 13:03:08 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_string;
	unsigned int	i;

	i = 0;

	if (len > (size_t)ft_strlen(s))
		len = (size_t)ft_strlen(s);
	sub_string = (char *)(malloc((len + 1)*sizeof(char)));
	if (s == NULL || sub_string == NULL)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
	{
		free(sub_string);
		return ((char*)ft_calloc(1, sizeof(char)));
	}
	while (i < len && s[start] != '\0')
	{
		sub_string[i] = s[start];
		i++;
		start++;
	}
	sub_string[i] = '\0';
	return (sub_string);
}

/*int main ()
{
	char		s[20] = "tripouillee";
	printf ("%s", ft_substr (s, 0, 42000));
	return(0);
}*/