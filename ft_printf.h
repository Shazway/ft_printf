/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:03:56 by tmoragli          #+#    #+#             */
/*   Updated: 2021/05/11 16:08:33 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
#define FT_PRINTF_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct		s_list
{
	char	index;
	int		lindex;
	char	precision;
	char	asterix;
	int		lprecision;
	char	type;
}					t_flag;



#endif
