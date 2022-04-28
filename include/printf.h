/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:17:35 by pguranda          #+#    #+#             */
/*   Updated: 2022/04/28 16:15:56 by pguranda         ###   ########.fr       */
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
	int				length;
	char			specifier;
	struct lst_arg	*next;
}	lst_arg;

lst_arg *ft_decode_char(char *s, size_t i);
//printf ("%c %i %i %i %c", first_arg->flags, first_arg->width, first_arg->precision, first_arg->length, first_arg->specifier);
#endif