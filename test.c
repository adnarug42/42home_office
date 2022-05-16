#include "libft/libft.h"
#include <stdio.h>


int main ()
{
	int i = 0;
	char *s;

	s = "priv123priv";
	i = ft_atoi(s);
	printf ("%d", i);
	return (0);
}

/*#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void ft_print_s (char *s)
{
	size_t i = 0;
	while (s[i] != '\0')
	{
		s[i] = 'M';
		i++;
	}
	printf ("\nIn the function: %s", s);
	free(s);
	//s = NULL;
}

int main ()
{
	char *s;

	s = malloc(sizeof(char) * 6);
	strcpy(s, "hello");
	printf("Original: %s", s);
	ft_print_s(s);
	printf("\n After free: %s", s);
	return (0);
}*/
