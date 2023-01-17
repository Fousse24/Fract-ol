/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 12:56:39 by sfournie          #+#    #+#             */
/*   Updated: 2021/12/22 13:40:12 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include	<stdarg.h>
# include	<stdio.h>
# include	<limits.h>
# include	<stddef.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<math.h>
# include	<complex.h>
# include	"./mlx/mlx.h"
# include	"./libft/libft.h"
# define	MAX_ITER	75
# define	DEEP_COLOR	0x000000
# define	SURF_COLOR	0xFFFFFF
# define	WIN_W		800
# define	WIN_H		600
# define	MAG_FORCE	1.1
# define	MOVE_FORCE	0.1	
# define	WHITE 		0xFFFFFF
# define	BLACK 		0x000000
# define	RED 		0xFF0000
# define	YELLOW 		0xFFFF00
# define	GREEN 		0x00FF00
# define	AQUA 		0x00FFFF
# define	BLUE 		0x0000FF
# define	PINK 		0xFF00FF

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_comp
{
	double	r;
	double	i;
}				t_comp;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	img;
}				t_vars;

typedef struct s_frac
{
	int		(*fractal)(t_comp *);
	double	x_mod;
	double	y_mod;
	double	x_mouse;
	double	y_mouse;
	double	r_min;
	double	r_max;
	double	i_min;
	double	i_max;
	double	c_r;
	double	c_i;
	double	c_r_mod;
	double	c_i_mod;
	double	mag;
	int		deep_color;
	int		surf_color;
	int		max_iter;
	int		psy_mode;
	int		color_mode;
	int		anim_mode;
}				t_frac;

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;

int		ft_handle_args(char **args);
void	ft_show_error(char *error);
void	ft_show_help(void);
int		ft_julia_type(int code);
int		ft_julia_args(char **args);
t_frac	*ft_getsettings(void);
void	ft_toggle_setting(int *set);
void	ft_defaults(t_frac *f);
void	ft_reset(t_frac *f);
t_color	ft_createcolor(int r, int g, int b);
int		ft_get_as_int(t_color col);
int		ft_colorshift(int c1, int c2, double force);
void	ft_zoominput(int keycode, int x, int y);
void	ft_moveinput(int keycode);
void	ft_move(double x, double y);
int		ft_get_trgb(int trgb, char c);
void	ft_put_pixel(t_data *data, int x, int y, int color);
void	ft_draw_img(t_vars *vars, void *img, int x, int y);
int		ft_is_in_win(int x, int y);
int		ft_fractal(t_vars *vars);
void	*ft_getfractal(char *fractal);
int		ft_mandelbrot(t_comp *cn);
int		ft_julia(t_comp *cn);
int		ft_burning_ship(t_comp *cn);
int		ft_keyhandler(int keycode, t_vars *vars);
int		ft_mousehandler(int keycode, int x, int y);
int		ft_exit(t_vars *vars);
#endif