/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:11:27 by tmoragli          #+#    #+#             */
/*   Updated: 2021/05/25 17:01:14 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initialize(t_data *parsing)
{
	parsing->flag = 0;
	parsing->width = 0;
	parsing->lwidth = 0;
	parsing->precision = 0;
	parsing->lprecision = 0;
	parsing->asterisk = 0;
	parsing->type = 0;
}

void	ft_flag(char **str, t_data *parsing)
{
	while (*str && **str && (**str == '-' || **str == '0'))
	{
		if (parsing->flag != '-')	
			parsing->flag = **str;
		(*str)++;
	}
}
void	ft_width(char **str, t_data *parsing)
{
	if (ft_isdigit(**str))
	{	
		parsing->width = 1;
		parsing->lwidth = ft_atoi(*str);
	}
	while (*str && **str && ft_isdigit(**str))
		(*str)++;
}
void	ft_precision(char **str, t_data *parsing)
{
	if (**str == '.')
	{	
		parsing->precision = 1;
		(*str)++;
		parsing->lprecision = ft_atoi(*str);
	}
	while (*str && **str && ft_isdigit(**str))
		(*str)++;
}

void	ft_parse(char *str)
{
	t_data	*parsing;
	if (!(parsing = malloc(sizeof(t_data))))
   		return ;
	str++;
	ft_initialize(parsing);
	ft_flag(&str, parsing);
	ft_width(&str, parsing);
	ft_precision(&str, parsing);
	parsing->type = *str;
	printf("flag = %c\nwidth = %d %d\nprecision = %d %d\ntype = %c\n", parsing->flag, parsing->width, parsing->lwidth, parsing->precision, parsing->lprecision, parsing->type);
}
