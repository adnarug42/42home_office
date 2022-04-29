/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:40:44 by pguranda          #+#    #+#             */
/*   Updated: 2022/04/29 13:22:05 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*1. Finish getting the address and the lenght of the string
2. Simplify ft_decoding here
3. Creating chained list with the arguments 
*/
#include "include/printf.h"

lst_arg *ft_printf(const char *s, ...)
{
	va_list			ap;
	size_t			i;
	size_t			z;
	lst_arg			*arg;

	arg = malloc(sizeof(lst_arg));
	z = 0;
	i = 0;
	/*i = ft_parse_args(s);
	printf("No. of args:%zu \n", i);
	arg = ft_decoding(s, i);*/
	va_start(ap, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%' && ft_strchr(SPECIFIERS_FLAGS, s[i + 1]) != NULL)
		{
			arg = ft_decode_all(s, i + 1);
			write_decoded(arg, ap);
			i += arg->length;
		}
		else
			write(1, &s[i], 1);
		i++;
	}
	va_end (ap);
	return (arg);
}

/*static int	ft_parse_args(const char *s)
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
}*/

/*size_t	find_start(const char *s) // could be that after %come a flag but specifier never comes?
{
	size_t		i;

	i = 0;
	while (s[i] != '\0') // making sure it is an argument with alignment or flags
	{
		i++;
		if (s[i] == '%' && ft_strchr(SPECIFIERS_FLAGS, s[i + 1]) != NULL)
			return(i + 1); // starting from the next element
	}
	return (0);
}*/


/*static lst_arg	*ft_decoding(const char *s, size_t num_of_args)
{
	lst_arg		*first_arg;
	size_t		arg_start;
	size_t		arg_len;
	size_t		i;
	char		*str_arg;

	arg_start = 0;
	arg_len = 0;
	first_arg = malloc(sizeof(lst_arg));
	num_of_args = 1;
	arg_start = find_start(s);
	arg_len = find_len(s, arg_start);
	while (s[i] < arg_start)
	{
		write (1, &c, 1);
		i++;
	}
	str_arg = ft_substr(s, arg_start, arg_len);
	printf("%s\n", str_arg);
	first_arg = ft_decode_char(str_arg, arg_len);
	write_function
	return(first_arg);
}*/

int main ()
{
	lst_arg	*first_arg;
	first_arg = ft_printf("Hello how are you %i and how many who knows", 24);

	return(0);
}
