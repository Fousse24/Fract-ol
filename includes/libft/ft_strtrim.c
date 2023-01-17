/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:20:49 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/17 13:47:24 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static size_t	ft_match(const char c, const char *set)
{
	while (*set)
	{
		if ((unsigned char)*set++ == (unsigned char)c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strim;
	size_t	start;
	size_t	end;
	size_t	i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	i = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_match(s1[start], set))
		start++;
	while (end != 0 && s1[end - 1] && ft_match(s1[end - 1], set))
		end--;
	if (end <= start)
		strim = (char *)malloc(sizeof(char) * 1);
	else
		strim = (char *)malloc(sizeof(char) * (end - start + 1));
	if (strim == NULL)
		return (NULL);
	while (start < end)
		strim[i++] = s1[start++];
	strim[i] = '\0';
	return (strim);
}
