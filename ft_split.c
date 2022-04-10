/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 10:04:33 by pguranda          #+#    #+#             */
/*   Updated: 2022/04/10 14:13:18 by pguranda         ###   ########.fr       */
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

/*#include <stdlib.h>
#include <stdio.h>
#include <string.h>*/
#include "libft.h"

unsigned int		count_strings(char const *s, char c);
int					s_mem(char const *s, char c);

char **ft_split(char const *s, char c)
{
	char				**array_str;
	int					i;
	int					count_s;
	int					arr_len;
	char				*p_str;
		
	count_s = 0;
	i = 0;
	arr_len = count_strings(s, c);
	array_str = (char **)malloc(arr_len*sizeof(char *) + sizeof(void *));
	if (s == NULL || array_str == NULL)
		return (NULL);
		while (count_s < arr_len)
	{
		array_str[count_s] = (char *)malloc(sizeof(char)*s_mem(s + i, c) + 1); // mem alloc
		p_str = array_str[count_s];
		while(s[i ] != c && s[i] != '\0')
		{
			*p_str = s[i];
			i++;
			p_str++;
		}
		if (s[i] == c)
		{
			*p_str = '\0'; //maybe next?
			i++;
			count_s++;  
		}
		else if (s[i] == '\0')
		{
			*p_str = '\0'; 
			count_s++;
		}
	}
	array_str[count_s++] = NULL;
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
		i++;
	if (i > 0 )
		return (i);
	else
		return (0);
}


/*#include <stdlib.h>
#include <unistd.h>

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int		main(int argc, const char *argv[])
{
	char	**tabstr;
	int		i;
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	i = 0;
	if ((arg = atoi(argv[1])) == 1)
	{
		if (!(tabstr = ft_split("          ", ' ')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != NULL)
			{
				ft_print_result(tabstr[i]);
				write(1, "\n", 1);
				i++;
			}
		}
	}
	else if (arg == 2)
	{
		if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != NULL)
			{
				ft_print_result(tabstr[i]);
				write(1, "\n", 1);
				i++;
			}
		}
	}
	else if (arg == 3)
	{
		if (!(tabstr = ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != NULL)
			{
				ft_print_result(tabstr[i]);
				write(1, "\n", 1);
				i++;
			}
		}
	}
	else if (arg == 4)
	{
		if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != NULL)
			{
				ft_print_result(tabstr[i]);
				write(1, "\n", 1);
				i++;
			}
		}
	}
	else if (arg == 5)
	{
		if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != NULL)
			{
				ft_print_result(tabstr[i]);
				write(1, "\n", 1);
				i++;
			}
		}
	}
	else if (arg == 6)
	{
		if (!(tabstr = ft_split("", 'z')))
			ft_print_result("NULL");
		else
			if (!tabstr[0])
				ft_print_result("ok\n");
	}
	return (0);
}
*/