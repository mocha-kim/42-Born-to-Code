#include "../includes/ft_printf.h"
#include <stdio.h>

int		main()
{
	int	a = -1234567890;
	unsigned int b = 3060399406;

	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", (int)b);
	printf("%u\n", a);
	printf("%u\n", b);
	printf("%u\n", (unsigned int)a);
}
