/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:03:51 by pguranda          #+#    #+#             */
/*   Updated: 2022/04/27 17:13:57 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"

char    *ft_arg_str(const char *s)
{
	size_t		i;
	size_t		z;

	i = 0;
	count = 0;
	if (s[z] == '%' && ft_strchr(SPECIFIERS_FLAGS, s[z + 1]) != NULL) // making sure it is an argument with alignment or flags
		{
			i++;
			printf("check");
			arg_start = i;
			arg_len = 1;
			while (ft_strchr(SPECIFIERS, s[i]) == NULL)
			{
				i++;
				arg_len++;
			}
		}
	return ()
}