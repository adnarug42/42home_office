/*
1. Iterating through the string
2. Taking the index of each char to the function as the first argument
3. Using malloc to allocate the memory to the respective string
4. Check if it is a null allocation.
*/
#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char				*p_s;
	int					i;
	int					len;

	p_s = NULL;
	i = 0;
	len = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) + 1;
	p_s = (char *)malloc(sizeof(char) * len);
	if (p_s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		p_s[i] = (*f)(i, s[i]);
		i++;
	}
	p_s[i] = '\0';
	return (p_s);
}