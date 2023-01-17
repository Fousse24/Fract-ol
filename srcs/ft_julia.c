/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 13:52:04 by sfournie          #+#    #+#             */
/*   Updated: 2021/08/02 14:53:17 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/fractol.h"

static int	ft_set_julia(double r, double i)
{
	t_frac	*frac;

	frac = ft_getsettings();
	frac->c_r = r;
	frac->c_i = i;
	return (1);
}

int	ft_julia_args(char **args)
{
	t_frac	*frac;

	frac = ft_getsettings();
	if (args != NULL && args[0] != NULL)
	{
		if (ft_isdigit(*args[0]) || *args[0] == '-' || *args[0] == '+')
			frac->c_r = ft_atod(args[0]);
		else
		{
			ft_show_error("Invalid number as julia's argument.");
			return (0);
		}
		if (args[1] != NULL)
		{
			if (ft_isdigit(*args[1]) || *args[1] == '-' || *args[1] == '+')
				frac->c_i = ft_atod(args[1]);
			else
			{
				ft_show_error("Invalid number as julia's argument.");
				return (0);
			}
		}
	}
	return (1);
}

int	ft_julia_type(int code)
{
	t_frac	*frac;

	frac = ft_getsettings();
	if (code == 18)
		ft_set_julia(-0.038088, 0.9754633);
	if (code == 19)
		ft_set_julia(0.4, 0.6);
	if (code == 20)
		ft_set_julia(0.285, 0.01);
	if (code == 21)
		ft_set_julia(-0.8, 0.156);
	if (code == 22)
		ft_set_julia(0.285, 0);
	if (code == 23)
		ft_set_julia(0, -0.618033);
	if (code == 24)
		ft_set_julia(-0.70176, -0.3842);
	if (code == 25)
		ft_set_julia(-0.835, -0.2321);
	if (code == 26)
		ft_set_julia(-0.7269, 0.1889);
	if (code == 28)
		ft_set_julia(0, -0.8);
	return (1);
}

int	ft_julia(t_comp *cn)
{
	t_comp	c_cn;
	double	xr;
	double	yi;
	int		iter;
	double	xrtemp;

	c_cn.r = ft_getsettings()->c_r + ft_getsettings()->c_r_mod;
	c_cn.i = ft_getsettings()->c_i + ft_getsettings()->c_i_mod;
	xr = cn->r;
	yi = cn->i;
	iter = 0;
	while (xr * xr + yi * yi <= 4 && iter < ft_getsettings()->max_iter)
	{
		xrtemp = xr;
		xr = xrtemp * xrtemp - yi * yi + c_cn.r;
		yi = 2 * xrtemp * yi + c_cn.i;
		iter++;
	}
	return (iter);
}
