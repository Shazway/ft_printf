/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:25:31 by tmoragli          #+#    #+#             */
/*   Updated: 2021/08/10 16:00:00 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_malloc_array(int size, char *p, int count)
{
	p = malloc(sizeof(size) * (count + 1));
	if (!p)
		return (0);
	return (1);
}
