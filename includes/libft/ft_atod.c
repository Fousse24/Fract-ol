/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 13:58:51 by sfournie          #+#    #+#             */
/*   Updated: 2021/07/30 22:18:28 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static void	ft_decimal(const char *str, long double *num)
{
	long double	decimal;
	double		dec_multi;
	int			count;

	decimal = ft_atoi(str);
	count = ft_countdigits(decimal);
	dec_multi = 1;
	while (count-- > 0)
		dec_multi *= 10;
	*num += decimal / dec_multi;
}

double	ft_atod(const char *str)
{
	long double	num;
	int			count;
	int			neg;

	neg = 1;
	if (str == NULL || *str == '\0')
		return (0);
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	num = ft_atoi(str);
	count = ft_countdigits(num);
	str = str + count;
	if (*str && *str == '.')
		ft_decimal(++str, &num);
	return (num * neg);
}
