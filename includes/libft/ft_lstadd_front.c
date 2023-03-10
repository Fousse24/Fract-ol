/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:24:55 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/31 17:00:00 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_lstadd_front(t_list **lst, t_list *node)
{
	if (node != NULL)
	{
		node->next = *lst;
		*lst = node;
	}
}
