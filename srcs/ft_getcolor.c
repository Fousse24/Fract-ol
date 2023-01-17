/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 12:55:48 by sfournie          #+#    #+#             */
/*   Updated: 2021/07/27 17:22:30 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/fractol.h"

int	ft_get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int	ft_get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int	ft_get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int	ft_get_b(int trgb)
{	
	return (trgb & (0xFF));
}

int	ft_get_as_int(t_color col)
{	
	return (col.r * 65536 + col.g * 256 + col.b);
}
