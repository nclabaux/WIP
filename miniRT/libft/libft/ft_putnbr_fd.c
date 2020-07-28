/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:12:35 by nclabaux          #+#    #+#             */
/*   Updated: 2020/07/28 14:00:09 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	zero(int fd)
{
	write(fd, "0", 1);
}

static void	size(long x, size_t *len)
{
	*len = 0;
	while (x)
	{
		x = x / 10;
		(*len)++;
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	long	x;
	size_t	i;
	size_t	len;
	char	stock[11];

	if (n == 0)
		return (zero(fd));
	x = n;
	if (x < 0)
		x = -x;
	size(x, &len);
	i = 0;
	while (x)
	{
		stock[i++] = x % 10 + '0';
		x = x / 10;
	}
	if (n < 0)
	{
		stock[i] = '-';
		len++;
	}
	while (len)
		write(fd, &stock[--len], 1);
}
