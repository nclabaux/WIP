/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorial_calculus1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:45:15 by nclabaux          #+#    #+#             */
/*   Updated: 2020/08/02 17:39:20 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

t_td	ft_add_td_n(t_td p, t_td v, double n)
{
	t_td	res;

	res.x = p.x + v.x * n;
	res.y = p.y + v.y * n;
	res.z = p.z + v.z * n;
	return (res);
}

t_td	ft_unit_v(t_td v)
{
	double	norm;
	t_td	res;

	norm = ft_norm(v);
	res.x = v.x / norm;
	res.y = v.y / norm;
	res.z = v.z / norm;
	return (res);
}

t_td	ft_inverse(t_td v)
{
	t_td	res;

	res.x = -v.x;
	res.y = -v.y;
	res.z = -v.z;
	return (res);
}

t_td	ft_multi_td(t_td v, double n)
{
	t_td	origin;

	origin = (t_td){0, 0, 0};
	return (ft_add_td_n(origin, v, n));
}
