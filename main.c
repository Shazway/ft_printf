#include "ft_printf.h"

int main(void)
{
	printf("\n\n");
	printf("RETURN PRINTF : %d", printf("%s\n", "Coco Toto"));
	printf("RETURN FT_PRINTF : %d", ft_printf("%s\n", "Coco Toto"));
}