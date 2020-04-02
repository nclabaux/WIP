/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:31:43 by nclabaux          #+#    #+#             */
/*   Updated: 2019/11/15 12:12:50 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	unsigned char	x;
	unsigned long	i;

	s2 = (unsigned char*)s;
	x = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s2[i] == x)
			return ((void*)(s + i));
		i++;
	}
	return (NULL);
}
