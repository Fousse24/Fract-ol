/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:07:56 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/17 13:42:34 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		modulo;
	long	number;

	number = n;
	if (number < 0)
	{
		number = number * -1;
		ft_putchar_fd('-', fd);
	}
	modulo = number % 10;
	if (number >= 10)
	{
		number = (number - modulo) / 10;
		ft_putnbr_fd(number, fd);
	}
	ft_putchar_fd((modulo + '0'), fd);
}
