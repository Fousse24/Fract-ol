/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 12:55:48 by sfournie          #+#    #+#             */
/*   Updated: 2021/07/30 20:27:45 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/fractol.h"

t_color	ft_createcolor(int r, int g, int b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

static int	ft_shiftrgb(int c1, int c2, double force)
{
	unsigned int	diff;
	unsigned int	result;

	if (c2 < c1)
	{
		diff = c1 - c2;
		result = c1 - diff * force;
	}
	else
	{
		diff = c2 - c1;
		result = c1 + diff * force;
	}
	return (result);
}

int	ft_colorshift(int c1, int c2, double force)
{
	t_color	col1;
	t_color	col2;
	t_color	result;
	t_frac	settings;

	settings = *ft_getsettings();
	if (settings.color_mode == 1)
		return (ft_shiftrgb(c1, c2, force));
	col1 = ft_createcolor(ft_get_trgb(c1, 'r'), \
	 					ft_get_trgb(c1, 'g'), ft_get_trgb(c1, 'b'));
	col2 = ft_createcolor(ft_get_trgb(c2, 'r'), \
	 					ft_get_trgb(c2, 'g'), ft_get_trgb(c2, 'b'));
	if (c1 == c2)
		return (c1);
	result.r = ft_shiftrgb(col1.r, col2.r, force);
	result.g = ft_shiftrgb(col1.g, col2.g, force);
	result.b = ft_shiftrgb(col1.b, col2.b, force);
	return (result.r * 65536 + result.g * 256 + result.b);
}

int	ft_get_trgb(int trgb, char c)
{
	if (c == 't')
		return (trgb & (0xFF << 24));
	if (c == 'r')
		return ((trgb & (0xFF << 16)) / 65536);
	if (c == 'g')
		return ((trgb & (0xFF << 8)) / 256);
	if (c == 'b')
		return (trgb & 0xFF);
	return (0);
}
