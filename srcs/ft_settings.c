/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 13:49:33 by sfournie          #+#    #+#             */
/*   Updated: 2021/07/29 19:58:01 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/fractol.h"

void	ft_toggle_setting(int *set)
{
	if (*set == 0)
		*set = 1;
	else
		*set = 0;
	return ;
}

void	ft_defaults(t_frac *f)
{
	f->mag = 1;
	f->x_mod = 0;
	f->y_mod = 0;
	f->r_min = 0;
	f->r_max = 1.5;
	f->i_min = 0;
	f->i_max = 1;
	f->x_mouse = 0;
	f->y_mouse = 0;
	f->c_r = -0.038088;
	f->c_i = 0.9754633;
	f->c_r_mod = 0;
	f->c_i_mod = 0;
	f->deep_color = DEEP_COLOR;
	f->surf_color = SURF_COLOR;
	f->fractal = NULL;
	f->max_iter = MAX_ITER;
	f->psy_mode = 0;
	f->color_mode = 0;
	f->anim_mode = 0;
	return ;
}

void	ft_reset(t_frac *f)
{
	f->mag = 1;
	f->x_mod = 0;
	f->y_mod = 0;
	f->x_mouse = 0;
	f->y_mouse = 0;
	f->r_min = 0;
	f->r_max = 1.5;
	f->i_min = 0;
	f->i_max = 1;
	f->c_r_mod = 0;
	f->c_i_mod = 0;
	f->deep_color = DEEP_COLOR;
	f->surf_color = SURF_COLOR;
	f->psy_mode = 0;
	f->color_mode = 0;
	f->anim_mode = 0;
	return ;
}

t_frac	*ft_getsettings(void)
{
	static t_frac	*f;

	if (f == NULL)
	{
		f = (t_frac *)malloc(sizeof(t_frac));
		if (f == NULL)
			return (NULL);
		ft_defaults(f);
	}
	return (f);
}
