/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:43:07 by nclabaux          #+#    #+#             */
/*   Updated: 2020/01/30 22:34:30 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	is_negative(long x, int *negat)
{
	*negat = 0;
	if (x < 0)
	{
		*negat = 1;
		return (-x);
	}
	return (x);
}

char	*ft_nbr_base(unsigned long nbr, char *base)
{
	int	size;
	int	i;
	int	*tab;

	if (check_base(base, &size))
	{
		if (!(tab = malloc(sizeof(char) * 34)))
			return (NULL);
		i = 0;
		if (nbr == 0)
			tab[i++] = 0;
		while (nbr > 0)
		{
			tab[i++] = nbr % size;
			nbr = nbr / size;
		}
		return (ft_nbr_base2(tab, i, base));
	}
	return (NULL);
}

char	*ft_nbr_base2(int *tab, int size, char *base)
{
	int		i;
	char	*res;
	int		x;

	i = 0;
	if (!(res = malloc(sizeof(char) * (size + 2))))
		return (NULL);
	while (i < size)
	{
		x = tab[size - i - 1];
		res[i] = base[x];
		i++;
	}
	res[i] = 0;
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*x;
	char	*fr;
	char	*to;
	int		base_ok;

	x = nbr;
	fr = base_from;
	to = base_to;
	return (ft_nbr_base(ft_atoi_base(x, fr, &base_ok), to));
}
