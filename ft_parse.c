/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:11:27 by tmoragli          #+#    #+#             */
/*   Updated: 2021/05/11 16:08:25 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initialiwe(struct s_list parsing)
{
	(*parsing).index = NULL;
	(*parsing).lindex = 0;
	(*parsing).precision = NULL;
	(*parsing).lprecision = 0;
	(*parsing).asterix = NULL;
	(*parsing).type = NULL;

}

void	ft_fillstruct(char *str,struct s_list parsing, int i)
{
	ft_initialize(&parsing);
	while (str[i])
	{	
		if (str[i] == "-")
		{	
			(*parsing).index = '-';
			(*parsing).lindex = ft_atoi(str, i);
			(*i)++;
		}
		if (str[i] == "0")
		{
			(*parsing).index = '0';
			(*parsing).lindex = ft_atoi(str, i);
			(*i)++;
		}
		if (str[i] == ".")
		{
			(*parsing).precision = ".";
			if (str[i + 1] == "*")
			{	
				(*parsing).lprecision = arg;
				break ;
			}
			else
			{	
				(*parsing).lprecision = ft_atoi(str, i);
			}
			i++;
		}
	}
	return (0);
}

void	ft_parse(const char *str, int i)
{
	struct s_list	parsing;

	ft_fillstruct(char *str, &parsing, &i);
	
}
