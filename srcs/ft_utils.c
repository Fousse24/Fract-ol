/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:07:58 by sfournie          #+#    #+#             */
/*   Updated: 2021/08/02 14:51:01 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/fractol.h"

int	ft_exit(t_vars *vars)
{
	t_frac	*f;

	f = ft_getsettings();
	if (vars != NULL && vars->mlx != NULL && vars->win != NULL)
		mlx_destroy_window(vars->mlx, vars->win);
	if (f != NULL)
	{
		free(f);
		f = NULL;
	}
	exit(0);
	return (0);
}

int	ft_handle_args(char **args)
{
	int		arg_n;
	int		valid;
	t_frac	*f;

	arg_n = 0;
	valid = 1;
	f = ft_getsettings();
	arg_n = 0;
	if (ft_isdigit(*args[0]))
		f->max_iter = abs(ft_atoi(args[arg_n++]));
	if (f->max_iter > 1000)
		f->max_iter = 1000;
	f->fractal = ft_getfractal(args[arg_n++]);
	if (f->fractal == NULL)
	{
		ft_show_error("You need to enter a valid fractal type as argument \
			example : fractal mandelbrot");
		valid = 0;
	}
	if (f->fractal != NULL && f->fractal == ft_julia)
		if (!ft_julia_args(&args[arg_n]))
			valid = 0;
	return (valid);
}

void	ft_show_help(void)
{
	ft_putendl_fd("\nThis program plot and show a fractal \
	for you to manipulate.", 1);
	ft_putendl_fd("How to use it :", 1);
	ft_putendl_fd("\tfractal [max_iterations] [fractal_type] [type_options]", 1);
	ft_putendl_fd("\tmax_iterations\t: 0...1000 (default is 75)", 1);
	ft_putendl_fd("\tfractal_type\t: mandelbrot julia burning", 1);
	ft_putstr_fd("\n\ttype_options (options specific to a ", 1);
	ft_putendl_fd("fractal in particular) :", 1);
	ft_putstr_fd("\t\tjulia\t: [decimal] [decimal]", 1);
	ft_putendl_fd(" (if omitted, default is -0.038088 and 0.9754633)", 1);
	ft_putendl_fd("\n\tKeybinds for graphic manipulation :", 1);
	ft_putendl_fd("\t\tZoom : mouse wheel", 1);
	ft_putendl_fd("\t\tMove : arrows", 1);
	ft_putstr_fd("\t\tChange fractal : first letter of ", 1);
	ft_putendl_fd("the fractal type (m, j, ...)", 1);
	ft_putendl_fd("\t\tReset position, zoom, colors and modes : r", 1);
	ft_putendl_fd("\t\tToggle alternate color mode : c", 1);
	ft_putendl_fd("\t\tToggle psychedelic mode : p", 1);
	ft_putendl_fd("\t\tToggle Julia's animation : a", 1);
	ft_putendl_fd("\t\tChange Julia's values : [1...9]", 1);
}

void	ft_show_error(char *error)
{
	ft_putstr_fd("\nError : ", 1);
	ft_putendl_fd(error, 1);
}
