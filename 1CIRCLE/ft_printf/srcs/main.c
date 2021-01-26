#include <stdio.h>

int		main()
{
	printf("%.5s\n", "hi");
	printf("%0.5s\n", "hi");
	printf("%5s\n", "hi");
	printf("%-5s\n", "hi");
	printf("%-05s\n", "hi");
	printf("%-0.5s\n", "hi");
	printf("%05.5s\n", "hi");
	printf("%5.5s\n", "hi");
	printf("%5.5s\n", "asdfghjk");
	printf("%5.10s\n", "asdfghjk");
	printf("%10.5s\n", "asdfghjk");
}
