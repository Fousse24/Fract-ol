/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:55:38 by sfournie          #+#    #+#             */
/*   Updated: 2021/05/17 17:35:04 by sfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		return (ft_lstlast(lst->next));
	}
	return (NULL);
}
