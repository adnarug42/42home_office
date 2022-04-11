/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 10:04:33 by pguranda          #+#    #+#             */
/*   Updated: 2022/04/11 11:02:49 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_count_strings(char const *s, char c);
int				ft_str_len(char const *s, char c);
int				ft_assign(char const *s, char *p_str, char c, int i);

char	**ft_split(char const *s, char c)
{
	char				**arr_str;
	int					i;
	int					count_s;
	int					arr_len;
	char				*p_str;

	count_s = 0;
	i = 0;
	arr_len = ft_count_strings(s, c);
	arr_str = (char **)malloc(arr_len * sizeof(char *) + sizeof(void *));
	if (s == NULL || arr_str == NULL)
		return (NULL);
	while (count_s < arr_len)
	{
		while (ft_str_len(s + i, c) == 0)
			i++;
		arr_str[count_s] = (char *)malloc(sizeof(char) * ft_str_len(s + i, c));
		p_str = arr_str[count_s];
		i = ft_assign(s, p_str, c, i);
		count_s++;
		if (s[i] == c)
			i++;
	}
	arr_str[count_s++] = NULL;
	return (arr_str);
}

int	ft_assign(char const *s, char *p_str, char c, int i)
{
	while (s[i] != c && s[i] != '\0')
	{
		*p_str = s[i];
		i++;
		p_str++;
	}
	*p_str = '\0';
	return (i);
}

unsigned int	ft_count_strings(char const *s, char c)
{
	int				i;
	int				counter;
	int				len;

	i = 0;
	counter = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			counter++;
		i++;
	}
	return (counter);
}

int	ft_str_len(char const *s, char c)
{
	int				i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (i > 0)
		return (i + 1);
	return (0);
}
