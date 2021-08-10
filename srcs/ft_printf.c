/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:17:11 by tmoragli          #+#    #+#             */
/*   Updated: 2021/08/10 14:56:12 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printchar(char c, t_data *parsing)
{	
	write(1, &c, 1);
	parsing->count++;
	//printf("count = %d ", parsing->count);
}
void	ft_lprintarray(char *str, t_data *parsing, int precision)
{
	while (*str && precision && str)
	{
		write(1, str, 1);
		str++;
		precision--;
		parsing->count++;
	}
}
void	ft_printarray(char *str, t_data *parsing)
{
	while (str && *str)
	{
		write(1, str, 1);
		str++;
		parsing->count++;
	}
}
void	ft_c(t_data *parsing, char c)
{
	int j;

	if (parsing->flag == '-' && parsing->lwidth != 0)
	{
		ft_printchar(c, parsing);
		j = parsing->lwidth - 1;
		while (j > 0)
		{
			ft_printchar(' ', parsing);
			j--;
		}
	}
	else if (parsing->flag == '0')
	{
		j = parsing->lwidth - 1;
		while (j > 0)
		{
			ft_printchar('0', parsing);
			j--;
		}
		ft_printchar(c, parsing);
	}
	else if (parsing->width > 0 && parsing->flag == 0)
	{
		j = parsing->lwidth - 1;
		while (j > 0)
		{
			ft_printchar(' ', parsing);
			j--;
		}
		ft_printchar(c, parsing);
	}
	else
		ft_printchar(c, parsing);
}

void	ft_s(t_data *parsing, char *s)
{
	int j;

	if (parsing->flag == '-' && parsing->lwidth != 0)
	{
		printf("ici");
		ft_lprintarray(s, parsing, parsing->lprecision);
		j = parsing->lwidth -  ft_strlen(s);
		if (parsing->precision != 0)
			j = parsing->lwidth - parsing->lprecision;
		else
			ft_printarray(s, parsing);
		while (j > 0)
		{
			ft_printchar(' ', parsing);
			j--;
		}
	}
	if ((!parsing->flag) && parsing->precision && parsing->lprecision > 0)
		ft_lprintarray(s, parsing, parsing->lprecision);
	else if((!parsing->flag))
		ft_printarray(s, parsing);
}
void	ft_hex(t_data *parsing, unsigned int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		parsing->count++;
		return ;
	}
	parsing->count++;
	if (parsing->type == 'x' && nb > 0)
	{
		ft_putnbr_base_2(nb, "0123456789abcdef", parsing);
		return ;
	}
	if (parsing->type == 'X' && nb > 0)
	{
		ft_putnbr_base_2(nb, "0123456789ABCDEF", parsing);
		return ;
	}
}
void	ft_d(t_data *parsing, int nb)
{
	(void)parsing;
	if (nb == -2147483648)
	{
		ft_s(parsing, "-2147483648");
		return ;
	}
	if (nb == 0)
	{	
		write(1, "0", 1);
		parsing->count++;
		return ;
	}
	parsing->count++;
	ft_putnbr_base(nb, "0123456789", parsing);
}
void	ft_p(t_data *parsing, long unsigned int p)
{
	if (p ==  0)
		write(1, &p, 1);
	write(1, "0", 1);
	write(1, "x", 1);
	parsing->count += 3;
	ft_putnbr_base_2(p, "0123456789abcdef", parsing);
	parsing->type = 0;
}
void	ft_u(t_data *parsing, unsigned int u)
{
	if (u == 0)
	{
		write(1, "0", 1);
		parsing->count++;
		return ;
	}
	parsing->count++;
	ft_putnbr_base_2(u, "0123456789", parsing);
}
void	ft_node(t_data *parsing)
{
	if (parsing->type == '%')
		write(1, "%", 1);
	if (parsing->type == 'c')
		ft_c(parsing, va_arg(parsing->argptr, int));
	if (parsing->type == 's')
		ft_s(parsing, va_arg(parsing->argptr, char *));
	if (parsing->type == 'p')
		ft_p(parsing, va_arg(parsing->argptr, long unsigned int));
	if (parsing->type == 'd' || parsing->type == 'i')
		ft_d(parsing, va_arg(parsing->argptr, int));
	if (parsing->type == 'u')
		ft_u(parsing, (unsigned int)va_arg(parsing->argptr, unsigned int));
	if ((parsing->type == 'x') || (parsing->type == 'X'))
		ft_hex(parsing, (unsigned int)va_arg(parsing->argptr, unsigned int));
}
int		ft_printf(const char *str, ...)
{
	t_data	*parsing;
	int count;

	if (!(parsing = malloc(sizeof(t_data))))
		return (0);
	parsing->count = 0;
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
			//printf("ici");
			ft_printchar(*str, parsing);
		//printf("c = %c ", *str);
		str++;
	}
	count = parsing->count;
	free(parsing);
	return (count);
}
