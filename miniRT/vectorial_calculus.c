/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorial_calculus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 16:01:45 by nclabaux          #+#    #+#             */
/*   Updated: 2020/05/28 18:22:35 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_vector	ft_3p_to_v(t_point a, t_point b, t_point c)
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

double		ft_scalar_prod(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vector	ft_cross_prod(t_vector a, t_vector b)
{
	t_vector	result;

	result.x = (a.y * b.z) - (a.z * b.y);
	result.y = (a.z * b.x) - (a.x * b.z);
	result.z = (a.x * b.y) - (a.y * b.x);
	return (result);
}

double		ft_norm(t_vector v)
{
	return (hypot(hypot(v.x, v.y), v.z));
}

t_vector	ft_2p_to_v(t_point a, t_point b)
{
	t_vector	result;

	result.x = b.x - a.x;
	result.y = b.y - a.y;
	result.x = b.z - a.z;
	return (result);
}
