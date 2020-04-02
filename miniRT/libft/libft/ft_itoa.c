/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:31:13 by nclabaux          #+#    #+#             */
/*   Updated: 2019/11/15 12:04:55 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*zero(void)
{
	char	*res;

	if (!(res = malloc(sizeof(char) * 2)))
		return (NULL);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

static void	negative(int n, int *neg)
{
	if (n < 0)
		*neg = 1;
	else
		*neg = 0;
}

static void	init(int *n, int *count, int *i, int *neg)
{
	negative(*n, neg);
	*count = 0;
	*i = 9;
}

static void	countloop(char *stock, int *i, int *n, int *count)
{
	if (*n > 0)
		stock[*i] = *n % 10 + '0';
	else
		stock[*i] = *n % 10 * -1 + '0';
	*n = *n / 10;
	(*count)++;
	(*i)--;
}

char		*ft_itoa(int n)
{
	char	stock[11];
	int		i;
	int		count;
	char	*res;
	int		neg;

	if (n == 0)
		return (zero());
	init(&n, &count, &i, &neg);
	while (n != 0)
		countloop(stock, &i, &n, &count);
	stock[10] = '\0';
	if (!(res = malloc(sizeof(char) * (count + 1 + neg))))
		return (NULL);
	i = neg;
	if (neg)
		res[0] = '-';
	while (stock[i + 10 - count - neg])
	{
		res[i] = stock[i + 10 - count - neg];
		i++;
	}
	res[i] = '\0';
	return (res);
}
