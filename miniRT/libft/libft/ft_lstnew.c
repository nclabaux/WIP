/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:52:07 by nclabaux          #+#    #+#             */
/*   Updated: 2019/10/25 17:52:12 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newlink;

	if (!(newlink = malloc(sizeof(t_list))))
		return (NULL);
	newlink->content = content;
	newlink->next = NULL;
	return (newlink);
}
