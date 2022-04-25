/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:40:44 by pguranda          #+#    #+#             */
/*   Updated: 2022/04/25 16:11:06 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
- Function to handle different cases:
	- Parse the string and count the number of the arguments
	FT_PARSE: count the arguments IN: const char*s OUT: number of arguments 
	NUANCE:
		- Check if %%
	- Read the letters in the flags
	If that is a % the read the flag and go over again 
	- Call on the va_arg with the respective type
	- Continue doing it until it is exhausted 
	- Go through the string and find the spots where the special elements are used. Return the address  
		Loop through the string and find the symbol and keep a couunt of which element (maybe in the function)
		Return the address
	- Input the respective element with the corresponding type
		Go to that address and put in the element
((*s + 1) == 'c') || (*s + 1) == "s" || (*s + 1) == "p" || (*s + 1) == "d" || (*s + 1) == "i" || (*s + 1) == "u" || (*s + 1) == "x" || (*s + 1) == "X" || (*s + 1) == "%%"
*/
#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

static int	ft_parse_args(const char *s);

int ft_printf(const char *s, ...)
{
	va_list		ap;
	//va_list		ap_copy;
	//size_t		i;
	char			*str;
	unsigned int	number;

	va_start(ap, s);
	str = va_arg(ap, char *);
	number = va_arg(ap, int);
	/*ft_putstr_fd(str, 1);
	ft_putnbr_fd(number , 1);*/
	va_end (ap);
	printf ("%i", ft_parse_args(s));
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
			i++;
		count++;
	}
	return (count);
}

int main ()
{
	ft_printf("Hello %s how are you %i and how many who knows", "privet", 24);
	return(0);
}

