/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:16:24 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/04 17:19:38 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"
#include "libft/libft.h"

size_t	find_len(const char *s, size_t arg_start)
{
	size_t	len;

	len = 0;
	while (ft_strchr(SPECIFIERS, s[arg_start + len]) == NULL)
		len++;
	return (len + 1);
}
