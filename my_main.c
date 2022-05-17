#include "include/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
	int *s;
	int my_len = 0;
	int print_len = 0;

	*s = 4645;

// 	ft_printf("*********FT_PRINTF*******\n\
// TEST1:%c  TEST2: %c TEST3: %c TEST4: %c TEST 5: %c %c %c TEST6: %c %c %c TEST7: %c %c %c TEST8: %c %c %c TEST9: %c %c %c",\
// '0', '0', '0' -256, '0' +256, '0', 0, '1', ' ', ' ', ' ', '1', '2', '3', '2', '1', 0, 0, '1', '2');
//  //ft_printf("*****FT_PRINTF********\nHere is: %23.0s", "proverka");
// 	printf("\n**********PRINTF*********\n\
// TEST1:%c  TEST2: %c TEST3: %c TEST4: %c TEST 5: %c %c %c TEST6: %c %c %c TEST7: %c %c %c TEST8: %c %c %c TEST9: %c %c %c",\
// '0', '0', '0' -256, '0' +256, '0', 0, '1', ' ', ' ', ' ', '1', '2', '3', '2', '1', 0, 0, '1', '2');
 my_len = ft_printf("!%-10d!", -123);
 print_len = printf("!%-10d!", -123);
 printf("\nmy len: %d print len: %d", my_len, print_len);
    return (0);
}