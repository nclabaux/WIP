/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorial_calculus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 16:01:45 by nclabaux          #+#    #+#             */
/*   Updated: 2020/05/12 17:46:33 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_vector	ft_vec_from_3pts(t_point a, t_point b, t_point c)
{
	t_vector	result;
	double		x;
	double		y;
	double		z;
	double		max;

	x = (b.y - a.y) * (c.z - a.z) - (b.z - a.z) * (c.y - a.y);
	y = (b.z - a.z) * (c.x - a.x) - (b.x - a.x) * (c.z - a.z);
	z = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	max = ft_max_double(ft_max_double(x, y), z);
	result.x = x / max;
	result.y = y / max;
	result.z = z / max;
	return (result);
}

double	ft_max_double(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}
