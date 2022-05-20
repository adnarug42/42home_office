/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:29:00 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/20 12:26:46 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putstr_printf(char *s, lst_arg *arg, int fd)
{
	size_t	i;
	int		len;
	int		width;
	int		z;

	i = 0;
	z = 0;
	width = arg->width;
	if (s == NULL)
	{
		write (1,"(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	if (arg->is_minus == 0 && width > len)
	{
		width = width - len;
		while (width > 0)
		{
			write (1, " ", 1);
			width--;
			z++;
		}
	}
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	if (s[i] == '\0')
		write (fd, "\0", 1);
	if (arg->is_minus == 1 && width > len)
	{
		width = width - len;
		while (width > 0)
		{
			write (1, " ", 1);
			width--;
			z++;
		}
	}
	return (z + i);
}
