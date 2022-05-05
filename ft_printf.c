/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:40:44 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/05 14:05:03 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int ft_printf(const char *s, ...)
{
	va_list			ap;
	int			i;
	lst_arg			*arg;

	arg = malloc(sizeof(lst_arg));
	if (arg == NULL)
		return 0;
	i = 0;
	va_start(ap, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			arg = parse_args(s, i + 1);
			write_struct(arg, ap);
			i += arg->length;
		}
		else
			write(1, &s[i], 1);
		i++;
	}
	va_end (ap);
	/*printf(" \n \n hash: %i \n minus: %i \n zero: %i \n plus: %i \n space: %i \n width: %zu \n\
 precision: %d \n length: %zu \n specifier: %c \n \n", arg->is_hash, arg->is_minus, arg->is_zero, arg->is_plus, arg->is_space, arg->width, arg->precision, arg->length, arg->specifier);*/
	return (i);
}

/*int main ()
{
	void *s;

	s = "null";

	ft_printf("*********FT_PRINTF*******\n\
Here is a hex x: %#X\nHere is an int: %d\nHere is a char: %c\n\
Here is %%: %% \nHere is pointer: %p\nHere is unsigned: %u \nHere is a str:*%10.5s*\n",\
 0x564F86, 25, 'a', s, -5, "privet");
 //ft_printf("*****FT_PRINTF********\nHere is: %23.0s", "proverka");
	printf("\n**********PRINTF*********\n\
Here is a hex x: %#X\nHere is an int: %d\nHere is a char: %c\n\
Here is %%: %% \nHere is pointer: %p\nHere is unsigned: %u\nHere is a str:*%10.5s*\n",
 +0x564F86, 25, 'a', s, -5, "privet");
	return(0);
}*/