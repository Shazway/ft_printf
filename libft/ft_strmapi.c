/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:17:59 by telli             #+#    #+#             */
/*   Updated: 2021/08/10 15:51:56 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	int		i;
	char	*dest;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	dest = malloc(sizeof(char) * i + 1));
	if (!dest)
		return (NULL);
	dest[i] = '\0';
	i = 0;
	while (s[i])
	{
		dest[i] = (*f)(i, s[i]);
		i++;
	}
	return (dest);
}
