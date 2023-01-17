/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:37:39 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/17 17:53:53 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
#include	<stdio.h>

int	ft_lstsize(t_list *lst)
{
	size_t	count;

	count = 0;
	if (lst != NULL)
	{
		count++;
		while (lst->next != NULL)
		{
			count++;
			lst = lst->next;
		}
	}
	return (count);
}
