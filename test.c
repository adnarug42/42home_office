//#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>



int main ()
{
	int	i;

	i = ULONG_MAX;
	if ((long long)i > 0)
		printf ("ok");
	else
		printf ("not ok");	
	return 0;
}
