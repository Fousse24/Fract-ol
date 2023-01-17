/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 10:19:03 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/13 16:18:30 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	void				*ptr;
	int					i;

	str = s;
	i = -1;
	while (++i < (int)n)
	{
		if (str[i] == (unsigned char)c)
		{
			ptr = (void *)&str[i];
			return (ptr);
		}
	}
	return (NULL);
}
