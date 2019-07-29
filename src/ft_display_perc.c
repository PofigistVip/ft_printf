/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_perc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlyne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 12:37:42 by larlyne           #+#    #+#             */
/*   Updated: 2019/05/26 12:37:44 by larlyne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int		ft_display_perc(int fd, t_printf_elem *el)
{
	int		i;
	int		width;
	char	space;

	width = el->width;
	if (width <= 1)
	{
		write(fd, "%", 1);
		return (1);
	}
	i = 1;
	space = ((el->flags & FT_PRINTF_ZERO) && !(el->flags & FT_PRINTF_MINUS))
		? '0' : ' ';
	if (el->flags & FT_PRINTF_MINUS)
	{
		write(fd, "%", 1);
		while (i++ < width)
			write(fd, &space, 1);
		return (width);
	}
	while (i++ < width)
		write(fd, &space, 1);
	write(fd, "%", 1);
	return (width);
}
