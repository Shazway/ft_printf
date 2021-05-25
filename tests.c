#include <stdio.h>
int main(void)
{
	printf("nb = %d\n", printf("[%10.10d]", "42"));
	printf("\n");
	printf("nb = %d\n", printf("[%.10d]", 42));
	printf("\n");
	printf("nb = %d\n", printf("[%c]", 'c'));
}
