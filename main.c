#include "include/ft_printf.h"
#include <stdio.h>
int main()
{
	void *s;

	s = "null";

	ft_printf("*********FT_PRINTF*******\n\
Here is a hex x: %#X\nHere is an int: %d\nHere is a char: %c\n\
Here is %%: %% \nHere is pointer: %p\nHere is unsigned: %u \nHere is a str:*%10.5s*\n",\
 0x564F86, 25, 'a', s, -5, "privet");
 //ft_printf("*****FT_PRINTF********\nHere is: %23.0s", "proverka");
	printf("\n**********PRINTF*********\n\
Here is a hex x: %#X\nHere is an int: %d\nHere is a char: %c\n\
Here is %%: %% \nHere is pointer: %p\nHere is unsigned: %u\nHere is a str:*%10.5s*\n",
 +0x564F86, 25, 'a', s, -5, "privet");

    return (0);
}