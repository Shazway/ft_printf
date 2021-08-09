/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:03:56 by tmoragli          #+#    #+#             */
/*   Updated: 2021/08/10 01:39:35 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "../libft/libft.h"
typedef struct		s_data
{
	char	flag;
	int		width;
	int		lwidth;
	char	precision;
	char	asterisk;
	int		lprecision;
	char	type;
	int		count;
	va_list	argptr;
}					t_data;

int		ft_printf(const char *str, ...);
void	ft_parsing(char **str, t_data *parsing);
void	ft_putnbr_base(int nbr, char *base, t_data *parsing);
void	ft_putnbr_base_2(long unsigned int nbr, char *base, t_data *parsing);

#endif
