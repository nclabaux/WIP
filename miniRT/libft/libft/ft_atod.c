/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 14:41:29 by nclabaux          #+#    #+#             */
/*   Updated: 2020/06/11 17:49:14 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(char *s)
{
	int i;
	int j;
	double	result;

	i = 0;
	result = 0;
	while (ft_isdigit(s[i]))
	{
		result *= 10;
		result += s[i] - '0';
		i++;
	}
	if (s[i] != '.')
		return (result);
	i++;
	j = 1;
	while (ft_isdigit(s[i]))
	{
		result += (s[i] - '0') / ft_pot(j);
		i++;
		j++;
	}
	return (result);
}

double		ft_pot(int n)
{
	int x;
	int result;

	x = 0;
	result = 1;
	while (x < n)
	{
		result *= 10;
		x++;
	}
	return (result);
}
