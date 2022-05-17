//#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>


void ft_transfer(int d)
{
	printf ("%d ", d);
	return ;
}

int ft_retransfer(void *f(int), char c)
{
	write (1, &c, 1);
	*f(5);
	return (10);
}
int main ()
{
	ft_retransfer(ft_transfer, 'c');
	return 0;
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
