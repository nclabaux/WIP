/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 17:09:25 by nclabaux          #+#    #+#             */
/*   Updated: 2020/07/29 18:12:46 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

double		ft_td_in_triangle(t_td p, t_triangle tr)
{
	double		area1;
	double		area2;
	double		area3;

	area1 = ft_norm(ft_cross(ft_2p_to_v(p, tr.p1), ft_2p_to_v(p, tr.p2)));
	area2 = ft_norm(ft_cross(ft_2p_to_v(p, tr.p1), ft_2p_to_v(p, tr.p3)));
	area3 = ft_norm(ft_cross(ft_2p_to_v(p, tr.p2), ft_2p_to_v(p, tr.p3)));
	return (area1 + area2 + area3 <= tr.area_x2 + 0.000001);
}

t_intersec	ft_cy_side(t_ray ray, t_cylinder cy)
{
	double	coef[3];
	double	root[2];
	t_intersec	res;
	t_intersec	storage;
	double	shit[6];
	t_td	u;

	res.dist = -1;
	storage.dist = -1;
	shit[0] = ray.v.y * cy.v.z - ray.v.z * cy.v.y;
	shit[1] = ray.p.y * cy.v.z - ray.p.z * cy.v.y;
	shit[2] = ray.v.z * cy.v.x - ray.v.x * cy.v.z;
	shit[3] = ray.p.z * cy.v.x - ray.p.x * cy.v.z;
	shit[4] = ray.v.x * cy.v.y - ray.v.y * cy.v.x;
	shit[5] = ray.p.x * cy.v.y - ray.p.y * cy.v.x;
	coef[0] = ft_sq(shit[0]) + ft_sq(shit[2]) + ft_sq(shit[4]);
	coef[1] = 2 * (shit[0] * shit[1] + shit[2] * shit[3] + shit[4] * shit[5]);
	coef[2] = ft_sq(shit[1]) + ft_sq(shit[3]) + ft_sq(shit[5]) - ft_sq(cy.d / 2);
	if (!(ft_solve_quadra(coef[0], coef[1], coef[2], root)))
		return (res);
	if (root[0] > 0.000001)
	{
		res.p = ft_add_td_n(ray.p, ray.v, root[0]);
		u = ft_2p_to_v(cy.p, res.p);
		if (ft_dot(cy.v, u) > 0 && ft_dot(cy.v, ft_2p_to_v(ft_add_td_n(cy.p, cy.v, cy.h), res.p)) < 0)
		{
			res.dist = root[0];
			res.normal = ft_2p_to_v(ft_multi_td(cy.v, ft_dot(u, cy.v)), u);
		}
	}
	if (root[1] > 0.000001)
	{
		storage.p = ft_add_td_n(ray.p, ray.v, root[1]);
		u = ft_2p_to_v(cy.p, storage.p);
		if (ft_dot(cy.v, u) > 0 && ft_dot(cy.v, ft_2p_to_v(ft_add_td_n(cy.p, cy.v, cy.h), res.p)) < 0)
		{
			storage.dist = root[1];
			res.normal = ft_2p_to_v(ft_multi_td(cy.v, ft_dot(u, cy.v)), u);
		}
	}
	if (res.dist == -1 || (storage.dist < res.dist && storage.dist != -1))
		res = storage;
	return (res);
}
