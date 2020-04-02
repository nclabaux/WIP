/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:57:31 by nclabaux          #+#    #+#             */
/*   Updated: 2019/11/15 12:43:30 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*link;

	if (!f || !del)
		return (NULL);
	result = NULL;
	while (lst)
	{
		if (!(link = ft_lstnew((*f)(lst->content))))
		{
			while (result)
			{
				link = result->next;
				(*del)(result->content);
				free(result);
				result = link;
			}
		}
		ft_lstadd_back(&result, link);
		lst = lst->next;
	}
	return (result);
}
