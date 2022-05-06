#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void ft_print_s (char **s);
int main ()
{
	char *s;

	s = (char *)malloc(6*sizeof(char));
	s = "privet";
	printf ("%s", s);
	ft_print_s(&s);
	return (0);
}

void ft_print_s (char **s)
{
	int i = 0;

	while (*s[i] != '\0')
	{
		*s[i] = 'M';
		i++;
	}
	//printf ("%s", &s);
	//free(s);
}