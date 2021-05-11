/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:17:11 by tmoragli          #+#    #+#             */
/*   Updated: 2021/05/11 15:18:21 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	int i;

	i = 0;
	while (str[i])
	{	
		if (str[i] == %)
		{
			if (str[i + 1] == %)
			{
				write (1, "%", 1);
				i+=2;
				continue ;
			}
			else
				ft_parse(str, &i);
				ft_printarg(str, &i);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
