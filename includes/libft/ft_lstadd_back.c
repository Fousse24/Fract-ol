/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:24:55 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/30 16:34:53 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *node)
{
	if (node != NULL)
	{
		if (*lst == NULL)
			*lst = node;
		else
			ft_lstlast(*lst)->next = node;
	}
}
