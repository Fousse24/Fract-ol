/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:25:09 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/27 13:24:28 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!*s && c)
		return (0);
	i = 0;
	while (i <= (int)ft_strlen(s))
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
