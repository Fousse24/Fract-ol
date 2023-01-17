/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:22:45 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/11 14:26:16 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	size_t			s2size;

	if (!*s2)
		return ((char *)s1);
	i = 0;
	j = 0;
	s2size = ft_strlen(s2);
	while (s1[i] && i < len)
	{
		while (s1[i + j] == s2[j] && (i + j) < len)
		{
			if (j == (s2size - 1))
				return ((char *)&s1[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
