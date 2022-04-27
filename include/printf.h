/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:17:35 by pguranda          #+#    #+#             */
/*   Updated: 2022/04/27 17:22:13 by pguranda         ###   ########.fr       */
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
	char			length;
	char			specifier;
	struct lst_arg	*next;
}	lst_arg;

lst_arg *ft_decode_char(char *s, size_t i, lst_arg *arg);

#endif