/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawinter <mawinter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:50:23 by mawinter          #+#    #+#             */
/*   Updated: 2022/03/25 16:17:13 by mawinter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')
		|| ('0' <= c && c <= '9'))
		return (1);
	else
		return (0);
}