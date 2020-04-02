/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:29:17 by nclabaux          #+#    #+#             */
/*   Updated: 2019/11/09 15:21:10 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned long	count;
	char			*c;

	if (!s)
		return ;
	c = s;
	count = 0;
	while (count < n)
	{
		c[count] = 0;
		count++;
	}
}
