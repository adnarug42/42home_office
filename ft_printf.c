/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:40:44 by pguranda          #+#    #+#             */
/*   Updated: 2022/04/27 17:09:00 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"

static int	ft_parse_args(const char *s);
static		lst_arg	*ft_decoding(const char *s, size_t num_of_args);

int ft_printf(const char *s, ...)
{
	va_list			ap;
	//va_list		ap_copy;
	size_t			i;
	char			*str;
	unsigned int	number;
	lst_arg			*arg;

	va_start(ap, s);
	str = va_arg(ap, char *);
	number = va_arg(ap, int);
	va_end (ap);
	//ft_putstr_fd(str, 1);
	//ft_putnbr_fd(number , 1);
	i = ft_parse_args(s);
	printf("%zu", i);
	arg = ft_decoding(s, i);
	printf ("Specifier:%c Flags:%c Precision:%i Width:%i\n", arg->specifier, arg->flags, arg->precision, arg->width);
	free(arg);
	return (0);
}

static int	ft_parse_args(const char *s)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && ft_strchr(SPECIFIERS_FLAGS, s[i + 1]) != NULL) 
			count++;
		i++;
	}
	return (count);
}

static lst_arg	*ft_decoding(const char *s, size_t num_of_args)
{
	size_t		i;
	size_t		z;
	lst_arg		*arg;
	lst_arg		*first_arg;
	size_t		arg_start;
	size_t		arg_len;
	char		*str_arg;

	i = 0;
	z = 0;
	arg = malloc(sizeof(lst_arg));
	first_arg = malloc(sizeof(lst_arg));
	num_of_args = 1;
	/*while (s[z] != '\0')
	{
		i = z;
		if (s[z] == '%' && ft_strchr(SPECIFIERS_FLAGS, s[z + 1]) != NULL) // making sure it is an argument with alignment or flags
		{
			i++;
			printf("check");
			arg_start = i;
			arg_len = 1;
			while (ft_strchr(SPECIFIERS, s[i]) == NULL)
			{
				i++;
				arg_len++;
			}*/
			str_arg = ft_substr(s, arg_start, arg_len);
			first_arg = ft_decode_char(str_arg, arg_len, arg);
			num_of_args--;
			while (str_arg > 0)
			{
				arg = ft_decode_char(str_arg, arg_len, arg);
				ft_lstadd_front_arg(first_arg, arg);
			}
		}
	z++;
	}
	return (arg);
}

int main ()
{
	ft_printf("Hello %-0s how are you %+13.12s and how many who knows", "privet", 24);
	return(0);
}
