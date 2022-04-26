/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:40:44 by pguranda          #+#    #+#             */
/*   Updated: 2022/04/26 21:26:31 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"

static int	ft_parse_args(const char *s);
static lst_arg	*ft_decoding(const char *s);

int ft_printf(const char *s, ...)
{
	va_list		ap;
	//va_list		ap_copy;
	size_t		i;
	char			*str;
	unsigned int	number;
	lst_arg			*arg;

	va_start(ap, s);
	str = va_arg(ap, char *);
	number = va_arg(ap, int);
	va_end (ap);
	ft_putstr_fd(str, 1);
	ft_putnbr_fd(number , 1);
	i = ft_parse_args(s);
	arg = ft_decoding(s);
	printf ("%c", arg->specifier);
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
		if (s[i] == '%') 
			count++;
		i++;
	}
	return (count);
}

static lst_arg	*ft_decoding(const char *s)
{
	size_t		i;
	lst_arg		*arg;

	i = 0;
	arg = malloc(sizeof(lst_arg));
	while (s[i] != '\0')
	{
		if (s[i] == '%' && ft_strchr(SPECIFIERS, s[i + 1]) == NULL) // making sure it is an argument
		{ 
			while (ft_strchr(SPECIFIERS, s[i++]) != NULL) // starting to decode arguments into a struct 
			{
			}
			arg->specifier = s[i];
			break;
		}
	i++;
	}
	return (arg);
}

int main ()
{
	ft_printf("Hello %s how are you %i and how many who knows", "privet", 24);
	return(0);
}
