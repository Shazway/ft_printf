/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 19:07:49 by telli             #+#    #+#             */
/*   Updated: 2021/08/10 23:51:43 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fill_array(long int n, char *dest, int count)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		dest[i] = '-';
		n = n * -1;
		i++;
	}
	if (n >= 0 && n <= 9)
	{
		dest[i] = n + 48;
		return (dest);
	}
	while (n >= 10)
	{
		dest[count] = (n % 10) + 48;
		n = n / 10;
		count--;
	}
	dest[count] = (n % 10) + 48;
	return (dest);
}

char	*ft_allocate_array(long int n, char *dest, int count)
{
	long int	temp;

	temp = n;
	if (n < 0)
		count++;
	if (n < 0)
		n = n * -1;
	if (n >= 0 && n <= 9)
	{
		dest = malloc(sizeof(char) * (count + 1));
		if (!dest)
			return (NULL);
		dest[count] = '\0';
		return (ft_fill_array(temp, dest, count));
	}
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	dest = malloc(sizeof(char) * count + 1);
	if (!dest)
		return (NULL);
	dest[count] = '\0';
	return (ft_fill_array(temp, dest, count - 1));
}

char	*ft_itoa(int n)
{
	char		*dest;
	long int	temp;

	temp = n;
	dest = NULL;
	dest = ft_allocate_array(temp, dest, 1);
	return (dest);
}
