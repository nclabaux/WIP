/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:56:08 by nclabaux          #+#    #+#             */
/*   Updated: 2019/11/15 12:34:16 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*link;
	t_list	*memstock;

	if (!lst || !*lst || !del)
		return ;
	link = *lst;
	while (link)
	{
		memstock = link->next;
		ft_lstdelone(link, del);
		link = memstock;
	}
	*lst = NULL;
}
