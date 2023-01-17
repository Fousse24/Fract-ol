/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 13:15:59 by sfournie          #+#    #+#             */
/*   Updated: 2021/07/30 20:28:47 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/fractol.h"

static int	ft_is_number_key(int kc)
{
	if (kc >= 18 && kc <= 29 && kc != 27)
		return (1);
	return (0);
}

int	ft_keyhandler(int keycode, t_vars *vars)
{
	t_frac	*f;

	f = ft_getsettings();
	if (keycode == 53)
		ft_exit(vars);
	if (keycode == 46)
		f->fractal = ft_getfractal("mandelbrot");
	if (keycode == 38)
		f->fractal = ft_getfractal("julia");
	if (keycode == 11)
		f->fractal = ft_getfractal("burning");
	if (keycode == 0)
		ft_toggle_setting(&f->anim_mode);
	if (keycode == 35)
		ft_toggle_setting(&f->psy_mode);
	if (keycode == 8)
		ft_toggle_setting(&f->color_mode);
	if (keycode == 126 || keycode == 125 || keycode == 124 || keycode == 123)
		ft_moveinput(keycode);
	if (keycode == 15)
		ft_reset(ft_getsettings());
	if (ft_is_number_key(keycode) == 1)
		ft_julia_type(keycode);
	return (1);
}

int	ft_mousehandler(int keycode, int x, int y)
{
	t_frac	*f;

	f = ft_getsettings();
	if (keycode == 4 || keycode == 5)
		ft_zoominput(keycode, x, y);
	return (1);
}
