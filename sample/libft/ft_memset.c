/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawinter <mawinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:45:06 by mawinter          #+#    #+#             */
/*   Updated: 2022/03/25 16:16:22 by mawinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	int				i;

	i = 0;
	ptr = s;
	while ((size_t)i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (s);
}
