#include "ft_printf.h"

int main(void)
{
	char *str = "s";
	printf("\n\n");
	printf("RETURN PRINTF : %d\n", printf("printf    :  Explosion : %d pourquoi tu %s va a cette adresse ? %p quand clairement %x", 42, "blblbl", str, 42));
	printf("RETURN FT_PRINTF : %d\n", ft_printf("ft_printf :  Explosion : %d pourquoi tu %s va a cette adresse ? %p quand clairement %x", 42, "blblbl", str, 42));
}