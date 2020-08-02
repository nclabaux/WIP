/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorial_calculus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 16:01:45 by nclabaux          #+#    #+#             */
/*   Updated: 2020/08/02 17:39:28 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

t_td	ft_3p_to_v(t_td a, t_td b, t_td c)
{
	t_td		res;

	res.x = (b.y - a.y) * (c.z - a.z) - (b.z - a.z) * (c.y - a.y);
	res.y = (b.z - a.z) * (c.x - a.x) - (b.x - a.x) * (c.z - a.z);
	res.z = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	return (ft_unit_v(res));
}

double	ft_dot(t_td a, t_td b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_td	ft_cross(t_td a, t_td b)
{
	t_td	result;

	result.x = (a.y * b.z) - (a.z * b.y);
	result.y = (a.z * b.x) - (a.x * b.z);
	result.z = (a.x * b.y) - (a.y * b.x);
	return (result);
}

double	ft_norm(t_td v)
{
	return (hypot(hypot(v.x, v.y), v.z));
}

t_td	ft_2p_to_v(t_td a, t_td b)
{
	t_td	result;

	result.x = b.x - a.x;
	result.y = b.y - a.y;
	result.z = b.z - a.z;
	return (result);
}
