/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:50:55 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/20 15:49:03 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*iter;

	if (lst == NULL)
		return (NULL);
	iter = ft_lstnew(f(lst->content));
	if (iter == NULL)
		return (NULL);
	if (lst->next != NULL)
	{
		iter->next = ft_lstmap(lst->next, f, del);
		if (iter->next == NULL)
		{
			del(iter->content);
			free(iter);
			return (NULL);
		}
	}
	else
		iter->next = NULL;
	return (iter);
}
