/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:39:44 by nclabaux          #+#    #+#             */
/*   Updated: 2019/11/15 12:21:57 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*except(char const *s1, char const *set)
{
	char	*res;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == 0)
	{
		if (!(res = malloc(sizeof(char))))
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	else
		return (NULL);
}

static int	is_in(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	init(unsigned long *size, unsigned int *end, unsigned int *start)
{
	*end = *size;
	*start = -1;
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t			size;
	unsigned int	start;
	unsigned int	end;
	char			*res;

	if (!s1 || !set || s1[0] == 0)
		return (except(s1, set));
	size = ft_strlen(s1);
	init(&size, &end, &start);
	while (is_in(s1[++start], set) && size)
		size--;
	while (is_in(s1[--end], set) && size)
		size--;
	if (!(res = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	size = 0;
	while (start <= end)
		res[size++] = s1[start++];
	res[size] = 0;
	return (res);
}
