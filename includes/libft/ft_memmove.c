/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:30:28 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/14 16:12:16 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	s = src;
	d = dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		s = s + (n - 1);
		d = d + (n - 1);
		while (n--)
			*d-- = *s--;
	}
	return (dest);
}
