/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:25:43 by sfournie          #+#    #+#             */
/*   Updated: 2022/04/11 13:39:54 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/fractol.h"

static int	ft_init_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_W, WIN_H, "fract-ol");
	vars->img.img = mlx_new_image(vars->mlx, WIN_W, WIN_H);
	vars->img.addr = mlx_get_data_addr(vars->img.img, \
					&vars->img.bpp, &vars->img.line_length, &vars->img.endian);
	mlx_key_hook(vars->win, ft_keyhandler, vars);
	mlx_mouse_hook(vars->win, ft_mousehandler, vars);
	mlx_loop_hook(vars->mlx, ft_fractal, vars);
	return (1);
}

static int	ft_plot_fractal(t_frac *f, t_data *img)
{
	t_comp	cn;
	int		x;
	int		y;
	int		iter;
	int		color;


	x = -1;
	y = -1;
	while (++x < WIN_W)
	{
		while (++y < WIN_H)
		{
			cn.r = f->r_min + (((double)x - WIN_W / 2) / WIN_W) * \
				(f->r_max - f->r_min) + f->x_mod;
			cn.i = f->i_min + (((double)y - WIN_H / 2) / WIN_H) * \
				(f->i_max - f->i_min) - f->y_mod;
			iter = f->fractal(&cn);
			color = ft_colorshift(f->surf_color, f->deep_color, \
				(double)iter / ft_getsettings()->max_iter);
			ft_put_pixel(img, x, y, color);
		}
		y = -1;
	}

	return (0);
}

void	*ft_getfractal(char *fractal)
{
	if (fractal == NULL)
		return (NULL);
	if (ft_strncmp(fractal, "mandelbrot", ft_strlen(fractal)) == 0)
		return ((*ft_mandelbrot));
	if (ft_strncmp(fractal, "julia", ft_strlen(fractal)) == 0)
		return ((*ft_julia));
	if (ft_strncmp(fractal, "burning", ft_strlen(fractal)) == 0)
		return ((*ft_burning_ship));
	return (NULL);
}

int	ft_fractal(t_vars *vars)
{
	t_frac	*f;
	static int	timer = 1000;
	int		timer_max = 1000;

	if (timer == 0)
	{
		f = ft_getsettings();
		if (f->anim_mode == 1 && f->fractal == ft_julia)
		{
			f->c_r_mod -= 0.003;
			f->c_i_mod -= 0.003;
		}
			if (f != NULL && f->fractal != NULL)
		{
			if (f->psy_mode == 1)
			{
				f->surf_color = ft_colorshift(f->surf_color, \
								f->surf_color - 65284, 1);
				f->deep_color = ft_colorshift(f->deep_color, \
								f->deep_color + 65284, 1);
			}
			mlx_clear_window(vars->mlx, vars->win);
			ft_plot_fractal(f, &vars->img);
			ft_draw_img(vars, vars->img.img, 0, 0);
		}
		timer = timer_max;
		
	}
	else
	{
		//printf("%d\n", timer);
		timer--;
	}
	return (0);
}

int	main(int argn, char **argc)
{
	t_vars	vars;
	t_frac	*f;

	f = ft_getsettings();
	if (f == NULL)
		return (0);
	if (argn >= 2)
	{
		if (ft_handle_args(&argc[1]) == 0)
		{
			ft_show_help();
			return (ft_exit(&vars));
		}
	}
	else
	{
		ft_show_help();
		return (ft_exit(&vars));
	}
	ft_init_mlx(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
