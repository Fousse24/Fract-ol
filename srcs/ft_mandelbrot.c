/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 13:20:27 by sfournie          #+#    #+#             */
/*   Updated: 2021/07/30 21:21:02 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/fractol.h"

int	ft_mandelbrot(t_comp *cn)
{
	double	xr;
	double	yi;
	int		iter;
	double	xrtemp;

	xr = 0;
	yi = 0;
	iter = 0;
	while (xr * xr + yi * yi <= 4 && iter < ft_getsettings()->max_iter)
	{
		xrtemp = xr * xr - yi * yi + cn->r;
		yi = 2 * xr * yi + cn->i;
		xr = xrtemp;
		iter++;
	}
	return (iter);
}
