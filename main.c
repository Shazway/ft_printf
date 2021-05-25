#include "ft_printf.h"

int main(void)
{
	char *str = "%052d";
    printf("%s\n", str);
	ft_parse(str);
}