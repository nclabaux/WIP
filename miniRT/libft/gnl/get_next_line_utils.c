/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:33:33 by nclabaux          #+#    #+#             */
/*   Updated: 2020/03/03 21:49:41 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_realloc(char **line)
{
	char	*stock;
	int		size;

	size = ft_strlen(*line);
	if (!(stock = malloc(sizeof(char) * size + 1)))
		return (0);
	ft_strncpy(stock, *line, size);
	free(*line);
	if (!((*line) = malloc(sizeof(char) * size + 2)))
		return (0);
	ft_strncpy(*line, stock, size + 1);
	free(stock);
	return (1);
}

void	ft_strncpy(char *dst, char *src, int size)
{
	int	i;

	i = 0;
	while (src[i] && i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

size_t	ft_strlen(const char *s)
{
	int		count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}
