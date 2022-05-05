# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 17:39:15 by pguranda          #+#    #+#              #
#    Updated: 2022/05/05 15:38:34 by pguranda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

LIBFT	=	libft/libft.a

SRCS		=	sources/digit.c\
				sources/find_len.c\
				sources/ft_hex_low.c\
				sources/ft_hex_up.c\
				ft_parse_decode.c\
				sources/ft_precision.c\
				ft_printf.c\
				sources/ft_putnbr_unsigned.c\
				sources/ft_width.c\
				ft_writing.c\
				sources/ft_zero.c\
				sources/put_pointer.c\
				sources/putnbr_with_zeroes.c\
				sources/sign.c\
				sources/space_sign.c

OBJS		=	$(SRCS:%.c=%.o)

CC		=		cc

CFLAGS	=		-c -Wall -Wextra -Werror 

INCLUDE =		include/ft_printf.h

all		: $(NAME)

$(NAME)	: $(OBJS) $(HEADER)
	@MAKE -C ./libft
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