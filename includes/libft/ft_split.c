/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:40:51 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/27 17:45:12 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static void	*ft_freesplit(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
		free(s[i++]);
	free(s);
	return (NULL);
}

static size_t	ft_countwords(char const *s, char delimiter)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[++i])
	{
		if (s[i] && s[i] == delimiter && s[i - 1] != delimiter)
			count++;
	}
	if (i != 0 && s[i - 1] != delimiter)
		count++;
	return (count);
}

static size_t	ft_countchar(char const *s, size_t pos, char delimiter)
{
	size_t	count;

	count = 0;
	while (s[pos] && s[pos] != delimiter)
	{
		count++;
		pos++;
	}
	return (count);
}

static	char	*ft_moveword(char const *s, size_t *pos, char delimiter)
{
	char	*str;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_countchar(s, *pos, delimiter);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		str[i++] = s[*pos];
		*pos = *pos + 1;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	index;
	size_t	pos;
	size_t	words;

	if (s == NULL)
		return (NULL);
	pos = -1;
	index = 0;
	words = ft_countwords(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (split == NULL)
		return (NULL);
	while (words != 0 && s[++pos] && pos < ft_strlen(s))
	{
		if (s[pos] != c)
		{
			split[index] = ft_moveword(s, &pos, c);
			if (split[index++] == NULL)
				return (ft_freesplit(split));
		}
	}
	split[index] = NULL;
	return (split);
}
