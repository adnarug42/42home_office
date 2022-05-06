/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:17:35 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/06 14:52:03 by pguranda         ###   ########.fr       */
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
	int				is_hash;
	int				is_minus;
	int				is_zero;
	int				is_plus;
	int				is_space;
	size_t			width;
	int				precision;
	size_t			length;
	char			specifier;
}	lst_arg;

void 		ft_decode_to_struct(char **s, size_t i, lst_arg* out);
void		parse_args(const char *s, size_t z, lst_arg* out);
void		write_struct(lst_arg *first_arg, va_list ap);
size_t		find_len(const char *s, size_t arg_start);
void 		ft_hex_up(unsigned int i);
void 		ft_hex_low(unsigned int i);
void		ft_putnbr_unsigned(unsigned int n, int fd);
void		ft_width(size_t width);
void		ft_zero(size_t width);
void		ft_precision(char *str, int i);
void		put_pointer(void *pointer);
void		putnbr_with_zeroes(int precision, int num);
void		sign(int i);
void		space_sign(int i);
int			digit(int c);
size_t		find_len(const char *s, size_t arg_start);
int 		ft_printf(const char *s, ...);

//printf ("%c %i %i %i %c", first_arg->flags, first_arg->width, first_arg->precision, first_arg->length, first_arg->specifier);
//cc -Wextra -Wall libft.a ft_hex_up.c ft_hex_low.c ft_putnbr_unsigned.c putnbr_with_zeroes.c put_pointer.c ft_width.c ft_zero.c ft_precision.c sign.c space_sign.c ft_writing.c ft_decode_char.c ft_printf.c
#endif