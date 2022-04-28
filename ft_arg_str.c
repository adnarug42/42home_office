/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:03:51 by pguranda          #+#    #+#             */
/*   Updated: 2022/04/28 10:10:10 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"

char		*ft_arg_str(const char *s)
{
	size_t		i;


	i = 0;
	while (s[i] != '%' && ft_strchr(SPECIFIERS_FLAGS, s[z + 1]) == NULL) // making sure it is an argument with alignment or flags
	{
		i++;
		if (s[i] == '%' && ft_strchr(SPECIFIERS, s[i]) != NULL)
			return(&s[i]);
	}
	return (NULL);
}
