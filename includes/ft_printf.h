/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:03:56 by tmoragli          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/06/08 19:00:58 by tmoragli         ###   ########.fr       */
=======
/*   Updated: 2021/06/08 18:55:14 by tmoragli         ###   ########.fr       */
>>>>>>> 867b4d588f69ec4df4bd71c6442507d78fc82e7e
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

#endif
