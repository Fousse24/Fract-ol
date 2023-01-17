/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:53:34 by sfournie          #+#    #+#             */
/*   Updated: 2021/06/23 19:07:11 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
#include	<stdio.h>

static int	ft_countdigit(unsigned long long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while ((n / 10) > 0 || (n % 10) != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_uitoa(unsigned long long int n)
{
	char	*num;
	int		count;

	count = ft_countdigit(n);
	num = (char *)malloc(sizeof(char) * (count + 1));
	if (num == NULL)
		return (NULL);
	num[count] = '\0';
	if (n == 0)
		num[0] = '0';
	while ((n / 10) > 0 || (n % 10) != 0)
	{
		num[--count] = (n % 10) + '0';
		n = n / 10;
	}
	return (num);
}
