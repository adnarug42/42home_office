# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 17:39:15 by pguranda          #+#    #+#              #
#    Updated: 2022/05/25 17:35:45 by pguranda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

LIBFT	=	libft/libft.a

SRCSDIR		=	sources/
SRCS_UTIL	=	digit.c\
				find_len.c\
				ft_hex_low.c\
				ft_hex_up.c\
				ft_precision_string.c\
				ft_putnbr_unsigned.c\
				ft_zero.c\
				ft_put_pointer.c\
				ft_putnbr_with_zeroes.c\
				ft_sign.c\
				ft_space_sign.c\
				ft_hex_low_pointer.c\
				ft_putstr_printf.c\
				ft_putchar_printf.c\
				ft_putnbr_printf.c\
				ft_precision_unsigned.c\
				ft_hex_counter.c\
				ft_precision_hex_low.c\
				ft_precision_hex_up.c\
				ft_write_width.c\
				ft_minus_width.c

SRCS_MAIN	=	ft_parse_decode.c\
				ft_printf.c\
				ft_writing.c

OBJFILES		=	$(SRCS:.c=.o)

CC		=		cc

CFLAGS	=		-c -Wall -Wextra -Werror 

INCLUDE =		include/ft_printf.h

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(MAKE) -C ./libft
	cp ./libft/libft.a $(NAME)
	$(CC) $(CFLAGS) $(INCLUDE) $(SRCS)
	ar rcs $(NAME) $(OBJS)

clean	:
	$(MAKE) clean -C ./libft
	@rm -rf $(OBJS)
	rm -rf *.o

fclean	: clean
	$(MAKE) fclean -C ./libft
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus