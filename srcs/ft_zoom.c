/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 13:20:13 by sfournie          #+#    #+#             */
/*   Updated: 2021/07/30 20:28:12 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/fractol.h"

static double	ft_interpolate(double start, double end, double force)
{
	return (start + ((end - start) * force));
}

static void	ft_zoom(double mag)
{
	t_frac	*f;

	f = ft_getsettings();
	if (f == NULL)
		return ;
	f->r_min = ft_interpolate(f->x_mouse, f->r_min, mag);
	f->r_max = ft_interpolate(f->x_mouse, f->r_max, mag);
	f->i_min = ft_interpolate(f->y_mouse, f->i_min, mag);
	f->i_max = ft_interpolate(f->y_mouse, f->i_max, mag);
	if (mag < 0)
	{
		f->max_iter--;
		f->mag *= fabs(mag);
	}
	else if (mag > 0)
	{
		f->max_iter++;
		f->mag /= fabs(mag);
	}
	return ;
}

void	ft_zoominput(int keycode, int x, int y)
{
	t_frac	*f;
	double	mx;
	double	my;
	double	mag;
	int		neg;

	f = ft_getsettings();
	mag = 1 / MAG_FORCE;
	neg = 1;
	if (keycode == 125 || keycode == 5)
		mag = MAG_FORCE;
	mx = ((double)x - WIN_W / 2) / (WIN_W / (f->r_max - f->r_min)) + f->r_min;
	my = ((double)y - WIN_H / 2) / (WIN_H / (f->i_max - f->i_min)) + f->i_min;
	f->x_mouse = mx;
	f->y_mouse = my;
	ft_zoom(mag);
	return ;
}
