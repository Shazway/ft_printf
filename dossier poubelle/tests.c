#include <stdio.h>
#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;
	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return(i);
}

int main(void)
{
	char *str = "Explosion";
	int precision = 2;
	int width = 10;
	int j;
	while (*str && precision)
	{
		write(1, str, 1);
		str++;
		precision--;
	}
	j = width - ft_strlen(str);
	while (j > 0)
	{
		write(1, " ", 1);
		j--;
	}
}
