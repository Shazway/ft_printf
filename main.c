#include "ft_printf.h"

int main(void)
{
	printf("\n\n");
	printf("RETURN PRINTF : %d\n", printf("printf    :  %s\n", "r"));
	printf("RETURN FT_PRINTF : %d\n", ft_printf("ft_printf :  %s\n", "r"));
}