/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:17:35 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/24 17:09:31 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include "../libft/libft.h"
# define SPECIFIERS "cspdiuxX%%"
# define FLAGS "#+- 0"
# define SPECIFIERS_FLAGS "cspdiuxX%%#+- 0123456789"
# define LONG_MIN	-__LONG_MAX__ -1L
# define LONG_MAX	2147483647
# define ULONG_MAX	4294967295
 

typedef struct lst_arg
{
	int				is_hash;
	int				is_minus;
	int				is_zero;
	int				is_plus;
	int				is_space;
	int				width;
	int				precision;
	size_t			length;
	char			specifier;
}	lst_arg;

void 		ft_decode_to_struct(const char *str_arg, size_t i, lst_arg* out);
void		parse_args(const char *s, size_t z, lst_arg* out);
void		write_struct(lst_arg *first_arg, va_list ap, int *counter);
size_t		find_len(const char *s, size_t arg_start);
int 		ft_hex_up(int i, int *sub_counter, int *sign_flag);
int			ft_hex_low(int num, int *sub_counter, int *sign_flag);
void		ft_hex_low_pointer(unsigned long num, int *hex_counter);
int			ft_putnbr_unsigned(int n, int *sub_counter, int *sign_flag);
int			ft_width(int width);
int			ft_zero(size_t width);
int			ft_precision_string(char *str, int i);
int			ft_put_pointer(void *pointer, lst_arg *out);
int			ft_putnbr_with_zeroes(int precision, int num);
int			ft_sign(int i);
int			ft_space_sign(int i);
int			digit(int c);
int			ft_putstr_printf(char *s, lst_arg *arg, int fd);
int			ft_putchar_printf(char s, lst_arg *arg, int fd);
size_t		find_len(const char *s, size_t arg_start);
void		ft_minus_width(int (*f)(int, int*, int*), lst_arg *arg, int integer, int *sub_counter);
int			ft_putnbr_printf(int n, int *sub_counter, int *sign_flag);
int			ft_precision_unsigned(int precision, int num, int *sub_counter);
int			ft_printf(const char *s, ...);
int			ft_precision_hex_low(int precision, int num,  int *sub_counter);
int			ft_precision_hex_up(int precision, int num,  int *sub_counter);
int			ft_hex_counter(int num, int *sub_counter);

//printf ("%c %i %i %i %c", first_arg->flags, first_arg->width, first_arg->precision, first_arg->length, first_arg->specifier);
//cc -Wextra -Wall libft.a ft_hex_up.c ft_hex_low.c ft_putnbr_unsigned.c putnbr_with_zeroes.c put_pointer.c ft_width.c ft_zero.c ft_precision.c sign.c space_sign.c ft_writing.c ft_decode_char.c ft_printf.c
#endif