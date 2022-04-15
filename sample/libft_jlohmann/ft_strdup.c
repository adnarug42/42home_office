/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlohmann <jlohmann@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:39:33 by jlohmann          #+#    #+#             */
/*   Updated: 2022/04/10 04:21:17 by jlohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	ptr = malloc(sizeof(char) * (len_s1 + 1));
	if (!ptr)
		return (NULL);
	while (*s1 != '\0')
		*(ptr++) = *(s1++);
	*ptr = '\0';
	return (ptr - len_s1);
}
