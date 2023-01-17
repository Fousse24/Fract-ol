/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 13:20:15 by sfournie          #+#    #+#             */
/*   Updated: 2021/07/29 13:39:36 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/fractol.h"

void	ft_move(double x, double y)
{
	t_frac	*f;

	f = ft_getsettings();
	f->x_mod += x;
	f->y_mod += y;
	return ;
}

void	ft_moveinput(int keycode)
{
	t_frac	f;
	double	movex;
	double	movey;

	f = *ft_getsettings();
	movex = MOVE_FORCE / f.mag;
	movey = MOVE_FORCE / f.mag;
	if (keycode == 126)
		ft_move(0, movey);
	if (keycode == 125)
		ft_move(0, -movey);
	if (keycode == 123)
		ft_move(-movex, 0);
	if (keycode == 124)
		ft_move(movex, 0);
	return ;
}
