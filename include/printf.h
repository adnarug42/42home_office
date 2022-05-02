/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:17:35 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/02 12:21:14 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include "../libft/libft.h"
# define SPECIFIERS "cspdiuxX%%"
# define FLAGS "#+- 0"
# define SPECIFIERS_FLAGS "cspdiuxX%%#+- 0"

typedef struct lst_arg
{
	char			flags;
	int				width;
	int				precision;
	size_t			length;
	char			specifier;
	//struct lst_arg	*next;
}	lst_arg;

lst_arg *ft_decode_char(char *s, size_t i);
lst_arg	*ft_decode_all(const char *s, size_t z);
void	write_decoded(lst_arg *first_arg, va_list ap);
size_t	find_len(const char *s, size_t arg_start);
void ft_hex_up(unsigned int i);
void ft_hex_low(unsigned int i);

//printf ("%c %i %i %i %c", first_arg->flags, first_arg->width, first_arg->precision, first_arg->length, first_arg->specifier);
#endif