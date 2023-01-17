/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:30:28 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/18 14:18:33 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	int					i;

	s = src;
	d = dest;
	i = -1;
	while (++i < (int)n)
	{
		d[i] = s[i];
		if (d[i] == (unsigned char)c)
			break ;
	}
	if (d[i] != (unsigned char)c)
		return (NULL);
	return (&dest[i + 1]);
}
