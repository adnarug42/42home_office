# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 17:39:15 by pguranda          #+#    #+#              #
#    Updated: 2022/05/04 18:01:31 by pguranda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC		=	digit.c	find_len.c	ft_hex_low.c	ft_hex_up.c\
			ft_parse_decode.c	ft_precision.c	ft_printf.c\
			ft_putnbr_unsigned.c	ft_width.c	ft_writing.c\
			ft_zero.c

OBJ		=	$(SRC:%.c=%.o)

HEADER	=	include/ft_printf.h

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

$(NAME): $(OBJ) $(HEADER)
	ar rcs $(NAME) $(OBJ)

%.o		:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJ)