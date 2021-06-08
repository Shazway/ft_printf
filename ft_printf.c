/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:17:11 by tmoragli          #+#    #+#             */
/*   Updated: 2021/06/08 17:19:21 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c(t_data *parsing, char c)
{
	int j;
	if (parsing->flag == '-' && parsing->lwidth != 0)
	{
		write(1, &c, 1);
		j = parsing->lwidth - 1;
		while (j > 0)
		{
			write(1, " ", 1);
			j--;
		}
	}
	if (parsing->flag == 0)
	{
		j = parsing->lwidth - 1;
		while (j > 0)
		{
			write(1, "0", 1);
			j--;
		}
		write(1, &c, 1);
	}
	if (parsing->width > 0 && parsing->flag == -1)
	{
		j = parsing->lwidth - 1;
		while (j > 0)
		{
			write(1, " ", 1);
			j--;
		}
		write(1, &c, 1);
	}
	else
		write(1, &c, 1);
	
}

void	ft_node(t_data *parsing)
{
	if (parsing->type == 'c')
		ft_c(parsing, va_arg(parsing->argptr, int));
}

int		ft_printf(const char *str, ...)
{
	int i;
	t_data	*parsing;

	if (!(parsing = malloc(sizeof(t_data))))
		return (0);
	va_start(parsing->argptr, str);
	i = 0;
	while (str && str[i])
	{
		if (str[i] == '%')
		{	
			ft_parsing(str, parsing);
			ft_node(parsing);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	return (1);
}
