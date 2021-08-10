#include "ft_printf.h"

int main(void)
{
	printf("\n\n");
	//printf("RETURN PRINTF : %d\n", printf("printf    :  %x %X\n", 154, 154));
	printf("RETURN FT_PRINTF : %d\n", ft_printf("ft_printf : %x %X\n", 154, 154));
}