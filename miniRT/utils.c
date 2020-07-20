/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 20:56:07 by nclabaux          #+#    #+#             */
/*   Updated: 2020/07/20 21:16:58 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

char	*ft_cut_filename(char *filename)
{
	int		last_dir;
	int		last_point;
	int		i;
	int		j;
	char	*res;

	i = 0;
	last_dir = 0;
	last_point = ft_strlen(filename);
	while (filename[i])
	{
		if (filename[i] == '/')
			last_dir = i;
		if (filename[i] == '.')
			last_point = i;
		i++;
	}
	if (!(res = malloc(sizeof(char) * (last_point - last_dir))))
		ft_errors(1011, "");
	i = last_dir + 1;
	j = 0;
	while (i < last_point)
	{
		res[j] = filename[i];
		i++;
		j++;
	}
	res[j] = 0;
	return (res);
}
