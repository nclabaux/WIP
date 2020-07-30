/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_cy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 17:09:25 by nclabaux          #+#    #+#             */
/*   Updated: 2020/07/30 22:33:38 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"


t_intersec	ft_cy_inter(t_ray ray, t_cylinder cy)
{
	t_intersec	res;
	t_intersec	storage;
	t_plane		base_disc;
	t_plane		upper_disc;

	base_disc.p = cy.p;
	base_disc.v = cy.v;
	upper_disc.p = ft_add_td_n(cy.p, ft_unit_v(cy.v), cy.h);
	upper_disc.v = cy.v;
	res.dist = -1;
	res = ft_cy_side(ray, cy);
	storage = ft_pl_inter(ray, base_disc);
	if (storage.dist > 0)
	{
		if (ft_2p_dist(storage.p, cy.p) < cy.d / 2)
			storage.dist = ft_2p_dist(ray.p, storage.p);
		else
			storage.dist = -1;
	}
	if (res.dist == -1 || (storage.dist < res.dist && storage.dist != -1))
	{
		res = storage;
		res.normal = ft_inverse(cy.v);
	}
	storage = ft_pl_inter(ray, upper_disc);
	if (storage.dist > 0)
	{
		if (ft_2p_dist(storage.p, upper_disc.p) < cy.d / 2)
			storage.dist = ft_2p_dist(ray.p, storage.p);
		else
			storage.dist = -1;
	}
	if (res.dist == -1 || (storage.dist < res.dist && storage.dist != -1))
	{
		res = storage;
		res.normal = cy.v;
	}
	res.color = cy.color;
	if (ft_p_line_dist(ray.p, cy.p, cy.v) < cy.d / 2
			&& ft_dot(ft_2p_to_v(cy.p, ray.p), cy.v) > 0
			&& ft_dot(ft_2p_to_v(upper_disc.p, ray.p), ft_inverse(cy.v)) > 0)
		res.normal = ft_inverse(res.normal);
	return (res);
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
			res.normal = ft_unit_v(res.normal);
		}
	}
	if (root[1] > 0.000001)
	{
		storage.p = ft_add_td_n(ray.p, ray.v, root[1]);
		u = ft_2p_to_v(cy.p, storage.p);
		if (ft_dot(cy.v, u) > 0 && ft_dot(cy.v, ft_2p_to_v(ft_add_td_n(cy.p, cy.v, cy.h), res.p)) < 0)
		{
			storage.dist = root[1];
			storage.normal = ft_2p_to_v(ft_multi_td(cy.v, ft_dot(u, cy.v)), u);
			storage.normal = ft_unit_v(storage.normal);
		}
	}
	if (res.dist == -1 || (storage.dist < res.dist && storage.dist != -1))
		res = storage;
	return (res);
}
