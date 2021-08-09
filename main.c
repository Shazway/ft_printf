#include "ft_printf.h"

int main(void)
{
	printf("\n\n");
	printf("RETURN PRINTF : %d\n", printf("printf    :  %d\n", 0));
	printf("RETURN FT_PRINTF : %d\n", ft_printf("ft_printf :  %d\n", 0));
}