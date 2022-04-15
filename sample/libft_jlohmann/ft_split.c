/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlohmann <jlohmann@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:06:04 by jlohmann          #+#    #+#             */
/*   Updated: 2022/04/13 20:08:53 by jlohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_arr_size(char const *s, char c)
{
	size_t	arr_size;

	arr_size = 0;
	while (*s != '\0')
	{
		while (*s == c)
			++s;
		if (*s != '\0')
			++arr_size;
		while (*s != c && *s != '\0')
			++s;
	}
	return (arr_size);
}

static char	*ft_add_to_arr(char **arr, size_t i_arr, char *s, char *str)
{
	arr[i_arr] = malloc(sizeof(char) * (str - s + 1));
	if (!arr[i_arr])
	{
		while (i_arr >= 0)
		{
			free(arr[i_arr]);
			if (i_arr == 0)
				break ;
			--i_arr;
		}
		free(arr);
		return (NULL);
	}
	ft_strlcpy(arr[i_arr], s, (str - s + 1));
	return (arr[i_arr]);
}

static char	**ft_fill_arr(char **arr, size_t arr_size, const char *s, char c)
{
	const char	*str;
	size_t		i_arr;

	str = s;
	i_arr = 0;
	while (i_arr < arr_size)
	{
		while (*s == c)
			++s;
		str = s;
		while (*str != c && *str != '\0')
			++str;
		arr[i_arr] = ft_add_to_arr(arr, i_arr, (char *)s, (char *)str);
		if (!arr[i_arr])
			return (NULL);
		++i_arr;
		s = ++str;
	}
	arr[i_arr] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char		**arr;
	size_t		arr_size;

	if (!s)
		return (NULL);
	arr_size = ft_get_arr_size(s, c);
	arr = malloc(sizeof(char *) * (arr_size + 1));
	if (!arr)
		return (NULL);
	arr = ft_fill_arr(arr, arr_size, s, c);
	if (!arr)
		return (NULL);
	return (arr);
}
