/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_old.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:40:44 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/01 13:06:29 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*1. Finish getting the address and the lenght of the string
2. Simplify ft_decoding here
3. Creating chained list with the arguments 
*/
#include "include/printf.h"

static int	ft_parse_args(const char *s);
static		lst_arg	*ft_decoding(const char *s, size_t num_of_args);

lst_arg *ft_printf(const char *s, ...)
{
	va_list			ap;
	//va_list		ap_copy;
	size_t			i;
	unsigned int	number;
	lst_arg			*arg;
	char			*str;

	va_start(ap, s);
	str = va_arg(ap, char *);
	number = va_arg(ap, int);
	va_end (ap);
	//ft_putstr_fd(str, 1);
	//ft_putnbr_fd(number , 1);
	i = ft_parse_args(s);
	printf("No of args:%zu \n", i);
	printf ("check");
	arg = ft_decoding(s, i);
	return (arg);
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

size_t	find_start(const char *s) // could be that after %come a flag but specifier never comes?
{
	size_t		i;

	i = 0;
	while (s[i] != '%' && ft_strchr(SPECIFIERS_FLAGS, s[i + 1]) == NULL) // making sure it is an argument with alignment or flags
	{
		i++;
		if (s[i] == '%' && ft_strchr(SPECIFIERS, s[i]) != NULL)
			return(i);
	}
	return (0);
}

size_t	find_len(const char *s, size_t arg_start)
{
	size_t	len;

	len = 0;
	while (ft_strchr(SPECIFIERS, s[arg_start + len]) != NULL)
		len++;
	return (len);
}


static lst_arg	*ft_decoding(const char *s, size_t num_of_args)
{


	lst_arg		*first_arg;
	lst_arg		*arg;
	size_t		arg_start;
	size_t		arg_len;
	char		*str_arg;

	
	arg_start = 0;
	arg_len = 0;
	first_arg = malloc(sizeof(lst_arg));
	arg = malloc(sizeof(lst_arg));
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

	arg_start = find_start(s);
	arg_len = find_len(s, arg_start);
	str_arg = ft_substr(s, arg_start, arg_len);
	first_arg = ft_decode_char(str_arg, arg_len, arg);
		/*num_of_args--;
		while (str_arg > 0)
		{
			arg = ft_decode_char(str_arg, arg_len, arg);
			ft_lstadd_front_arg(first_arg, arg);
		}*/
	return (first_arg);
}

int main ()
{
	lst_arg	*first_arg;
	first_arg = ft_printf("Hello %-0s how are you %+13.12s and how many who knows", "privet", 24);
	printf ("%c %i %i %i %c", first_arg->flags, first_arg->width, first_arg->precision, first_arg->length, first_arg->specifier);
	return(0);
}
