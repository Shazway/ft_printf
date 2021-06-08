/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:17:11 by tmoragli          #+#    #+#             */
/*   Updated: 2021/06/08 18:03:56 by tmoragli         ###   ########.fr       */
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
	else if (parsing->flag == '0')
	{
		j = parsing->lwidth - 1;
		while (j > 0)
		{
			write(1, "0", 1);
			j--;
		}
		write(1, &c, 1);
	}
	else if (parsing->width > 0 && parsing->flag == -1)
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
	t_data	*parsing;

	if (!(parsing = malloc(sizeof(t_data))))
		return (0);
	va_start(parsing->argptr, str);
	while (str && *str)
	{
		if (*str == '%')
		{
			str++;
			ft_parsing((char **)&str, parsing);
			ft_node(parsing);
		}
		else
			write(1, str, 1);
		str++;
	}
	free(parsing);
	return (1);
}
