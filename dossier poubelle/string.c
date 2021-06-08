#include <stdio.h>
#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_string(char *str, int s)
{
	int i;
	int j;

	i = 0;
	j = s - ft_strlen(str);
	while (j > 0)
	{	
		write(1, " ", 1);
		j--;
	}
	while (str[i])
	{	
		write(1, &str[i], 1);
		i++;
	}
}
int main(void)
{
	ft_test("42, 24", 10);
	printf("\n");
	printf("%10s", "42, 24");
}
