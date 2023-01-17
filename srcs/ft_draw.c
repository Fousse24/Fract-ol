/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 12:54:55 by sfournie          #+#    #+#             */
/*   Updated: 2021/07/25 18:39:05 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/fractol.h"

void	ft_put_pixel(t_data *i, int x, int y, int color)
{
	char	*dst;

	if (ft_is_in_win(x, y))
	{
		dst = i->addr + (y * i->line_length + x * (i->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	ft_is_in_win(int x, int y)
{
	if (x < WIN_W && x >= 0 && y < WIN_H && y >= 0)
		return (1);
	return (0);
}

void	ft_draw_img(t_vars *vars, void *img, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
}
