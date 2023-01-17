/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:53:54 by sfournie          #+#    #+#             */
/*   Updated: 2021/07/29 14:40:10 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	if (num == 0 || size == 0)
	{
		num = 1;
		size = 1;
	}
	ptr = (void *)malloc(size * num);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, num * size);
	return (ptr);
}
