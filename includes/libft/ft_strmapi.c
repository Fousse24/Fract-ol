/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:51:04 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/17 13:44:41 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*newstr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (newstr == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		newstr[i] = (*f)(i, s[i]);
	newstr[i] = '\0';
	return (newstr);
}
