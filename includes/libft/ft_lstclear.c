/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:18:57 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/18 17:47:22 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static void	ft_clearall(t_list *lst, void (*del)(void *))
{
	if (lst->next != NULL)
		ft_clearall(lst->next, *del);
	ft_lstdelone(lst, del);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	if (*lst != NULL)
		ft_clearall(*lst, (*del));
	*lst = NULL;
}
