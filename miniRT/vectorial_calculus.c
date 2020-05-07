/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorial_calculus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 16:01:45 by nclabaux          #+#    #+#             */
/*   Updated: 2020/05/07 14:33:20 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_vector3	ft_vec_from_3pts(t_point3 a, t_point3 b, t_point3 c)
{
	t_vector3	result;
	double		x;
	double		y;
	double		z;
	double		max;

	x = (b.y - a.y) * (c.z - a.z) - (b.z - a.z) * (c.y - a.y);
	y = (b.z - a.z) * (c.x - a.x) - (b.x - a.x) * (c.z - a.z);
	z = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	max = max(max(x, y), z);
	result.x = x / max;
	result.y = y / max;
	result.z = z / max;
	return (result);
