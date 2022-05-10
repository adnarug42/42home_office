#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void ft_print_s (int *d)
{

	*d = 1;
	printf ("\nIn the function: %d", *d);
	// free(d);
	//s = NULL;
}

int main ()
{
	int *d;
	*d = 0;
	printf("Original: %d", *d);
	ft_print_s(d);
	printf("\nAfter free: %d", *d);
	system("leaks a.out");
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
