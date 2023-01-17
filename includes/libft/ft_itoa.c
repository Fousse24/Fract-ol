/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:53:34 by sfournie          #+#    #+#             */
/*   Updated: 2021/07/29 14:25:05 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_itoa(int n)
{
	char	*num;
	int		count;
	long	nl;

	nl = n;
	count = ft_countdigits(nl);
	num = (char *)malloc(sizeof(char) * (count + 1));
	if (num == NULL)
		return (NULL);
	if (nl < 0)
	{
		nl *= -1;
		num[0] = '-';
	}
	num[count] = '\0';
	if (n == 0)
		num[0] = '0';
	while ((nl / 10) != 0 || (nl % 10) != 0)
	{
		num[--count] = (nl % 10) + '0';
		nl = nl / 10;
	}
	return (num);
}
