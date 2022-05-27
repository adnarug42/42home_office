/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:29:00 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/27 15:34:45 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putstr_printf(char *s, t_arg *arg, int *sub_counter)
{
	size_t	i;
	int		len;
	int		width;

	i = 0;
	width = arg->width;
	if (s == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	if (arg->is_minus == 0 && width > len)
		ft_write_width(width - len, sub_counter);
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	if (arg->is_minus == 1 && width > len)
		ft_write_width(width - len, sub_counter);
	return (*sub_counter + i);
}
