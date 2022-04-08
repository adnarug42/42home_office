/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 10:04:33 by pguranda          #+#    #+#             */
/*   Updated: 2022/04/08 17:14:11 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates (with malloc(3)) and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter. 
The array must end with a NULL pointer.*/

/*
1. Initialzing the array at the end is a null pointer
2. Find the delimeter in the string
	- Iteration loop checking if the letter is not delimeter adding it to a set
3. Make the split
	- Use front trim where any letter until the delimiter is a set and 
3. Allocate the memory to the array, including the pointers
4. abaabZeeef
		set: abababb
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include "libft.h"

unsigned int		count_strings(char const *s, char c);
int					s_mem(char const *s, char c);

char **ft_split(char const *s, char c)
{
	char				**array_str;
	char				*s1;
	int					i;
	int					count_s;
	int					i_mem;
	int					len;
		
	array_str = (char **)malloc(count_strings(s, c)*sizeof(char *) + 1);
	count_s = 0;
	i = 0;
	s1 = NULL;
	i_mem = 0;
	len = count_strings(s, c);

	while (count_s <= len)
	{
		while(s[i] != c && s[i] != '\0')
			{
				array_str[count_s] = (char *)malloc(sizeof(char*)*s_mem(s, c) + 1);
				*array_str[count_s] = s[i];
				i++;
				*array_str[count_s] += 1;
				if (s[i] == c)
					*array_str[count_s] = '\0';
			}
		i++;
		count_s++;
	}
	array_str[count_s] = s1;
	return (array_str);
}

unsigned int	count_strings(char const *s, char c)
{
	int				i;
	int				counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		while(s[i] != c && s[i] != '\0')
		{
			i++;
		}
	counter++;
	i++;
	}
	return (counter);
}

int	s_mem(char const *s, char c)
{
	int				i;

	i = 0;
		while(s[i] != c && s[i] != '\0')
		{
			i++;
		}

	return (i);
}

int				main()
{
	char s[20] = "obladiZoblaZda";
	char c = 'Z';
	char 	**array;

	array = ft_split (s, c);
	printf ("%s", array[0]);
	return (0);
}