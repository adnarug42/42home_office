/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlohmann <jlohmann@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:53:23 by jlohmann          #+#    #+#             */
/*   Updated: 2022/04/12 00:17:08 by jlohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	index;
	size_t			len_str;

	if (!s)
		return (NULL);
	index = 0;
	len_str = ft_strlen(s);
	str = malloc(sizeof(char) * (len_str + 1));
	if (!str)
		return (NULL);
	while (index < len_str)
	{
		str[index] = f(index, s[index]);
		++index;
	}
	str[index] = '\0';
	return (str);
}
