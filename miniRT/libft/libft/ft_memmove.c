/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:30:48 by nclabaux          #+#    #+#             */
/*   Updated: 2019/10/30 12:11:01 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	unsigned char	*d;
	unsigned char	*s;

	if (!dst || !src)
		return (NULL);
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (dst > src)
	{
		i = (int)len;
		while (--i >= 0)
			d[i] = s[i];
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
