/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:38:13 by nclabaux          #+#    #+#             */
/*   Updated: 2020/01/30 22:34:57 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*cut(char *str, int *negative)
{
	int minus;

	*negative = 1;
	minus = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\r'
		|| *str == '\f' || *str == ' ')
	{
		str++;
	}
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			(*negative) *= -1;
		str++;
	}
	return (str);
}

int		is_in_index(char c, char *base, int *index)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
		{
			*index = i;
			return (1);
		}
		i++;
	}
	return (0);
}

int		check_base(char *base, int *base_size)
{
	int size;
	int i;
	int j;

	size = 0;
	while (base[size])
	{
		if (base[size] == '+' || base[size] == '-' || base[size] < 33)
			return (0);
		size++;
	}
	if (size < 2)
		return (0);
	i = 0;
	while (i < size)
	{
		j = i++ + 1;
		while (j < size)
		{
			if (base[i - 1] == base[j++])
				return (0);
		}
	}
	*base_size = size;
	return (1);
}

int		ft_atoi_base(char *str, char *base, int *base_ok)
{
	int base_size;
	int res;
	int i;
	int index;
	int negative;

	str = cut(str, &negative);
	res = 0;
	if (check_base(base, &base_size))
	{
		*base_ok = 1;
		i = 0;
		while (str[i] != 0)
		{
			if (is_in_index(str[i], base, &index))
				res = res * base_size + index;
			else
				return (res * negative);
			i++;
		}
		return (res * negative);
	}
	*base_ok = 0;
	return (0);
}
