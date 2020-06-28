/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 11:19:48 by nclabaux          #+#    #+#             */
/*   Updated: 2020/06/28 19:03:53 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_intersec	ft_pl_inter(t_ray ray, t_plane pl)
{
	double		d;
	double		t0;
	double		div;
	t_intersec	res;

	res.dist = -1;
	d = (pl.v.x * pl.p.x + pl.v.y * pl.p.y + pl.v.z * pl.p.z);
	if (!(ray.p.x * pl.v.x + ray.p.y * pl.v.y + ray.p.z * pl.v.z - d))
		return (res);
	div = pl.v.x * ray.v.x + pl.v.y * ray.v.y + pl.v.z * ray.v.z;
	if (!(div))
		return (res);
	t0 = (d - pl.v.x * ray.p.x - pl.v.y * ray.p.y - pl.v.z * ray.p.z) / div;
	if (t0 <= 0)
		return (res);
	res.p = ft_add_v(ray.p, ray.v, t0);
	res.dist = ft_two_pts_dist(ray.p, res.p);
	res.normal = ft_unit_v(pl.v);
	if (ft_scalar_prod(res.normal, ft_unit_v(ft_2p_to_v(res.p, ray.p))) < 0)
		res.normal = ft_inverse_v(res.normal);
	res.color = pl.color;
	return (res);
}

t_intersec	ft_tr_inter(t_ray ray, t_triangle tr)
{
	t_plane		pl;
	t_intersec	res;

	pl.p = tr.p1;
	pl.v = ft_3p_to_v(tr.p1, tr.p2, tr.p3);
	res = ft_pl_inter(ray, pl);
	if (res.dist != -1)
	{
		if (!(ft_point_in_triangle(res.p, tr)))
			res.dist = -1;
	}
	res.color = tr.color;
	return (res);
}

t_intersec	ft_sq_inter(t_ray ray, t_square sq)
{
	t_intersec	res;
	t_intersec	storage;

	res = ft_tr_inter(ray, sq.b);
	storage = ft_tr_inter(ray, sq.a);
	if (storage.dist != -1)
		res = storage;
	return (res);
}

t_intersec	ft_sp_inter(t_ray ray, t_sphere sp)
{
	double		t0;
	double		coef[3];
	double		roots[2];
	t_intersec	res;
	t_intersec	storage;

	res.dist = -1;
	coef[0] = ft_sq(ray.v.x) + ft_sq(ray.v.y) + ft_sq(ray.v.z);
	coef[1] = 2 * (ray.v.x * (ray.p.x - sp.p.x) + ray.v.y * (ray.p.y - sp.p.y) + ray.v.z * (ray.p.z - sp.p.z));
	coef[2] = -(ft_sq(sp.diam / 2)) + ft_sq(ray.p.x) + ft_sq(ray.p.y) + ft_sq(ray.p.z) - 2 * (ray.p.x * sp.p.x + ray.p.y * sp.p.y + ray.p.z * sp.p.z);
	if (!(ft_solve_quadra(coef[0], coef[1], coef[2], roots)))
		return (res);
	if (roots[0] > 0)
	{
		t0 = roots[0];
		res.p = ft_add_v(ray.p, ray.v, t0);
		res.dist = ft_two_pts_dist(res.p, ray.p);
	}
	if (roots[1] > 0)
	{
		t0 = roots[1];
		storage.p = ft_add_v(ray.p, ray.v, t0);
		storage.dist = ft_two_pts_dist(storage.p, ray.p);
	}
	if (storage.dist < res.dist && storage.dist != -1)
		res = storage;
	res.color = sp.color;
	res.normal = ft_unit_v(ft_2p_to_v(sp.p, res.p));
	return (res);
}

t_intersec	ft_cy_inter(t_ray ray, t_cylinder cy)
{
	t_intersec	res;
	t_intersec	storage;
	t_plane		base_disc;
	t_plane		upper_disc;

	base_disc.p = cy.p;
	base_disc.v = cy.v;
	upper_disc.p = ft_add_v(cy.p, ft_unit_v(cy.v), cy.h);
	upper_disc.v = cy.v;
	res.dist = -1;
	res = ft_pl_inter(ray, base_disc);
	if (res.dist > 0)
	{
		if (ft_two_pts_dist(res.p, cy.p) <= ft_sq(cy.d / 2))
		{
			res.dist = ft_two_pts_dist(ray.p, res.p);
			res.normal = ft_unit_v(ft_inverse_v(cy.v));
		}
		else
			res.dist = -1;
	}
	storage = ft_pl_inter(ray, upper_disc);
	if (storage.dist > 0)
	{
		if (ft_two_pts_dist(storage.p, upper_disc.p) <= ft_sq(cy.d / 2))
		{
			storage.dist = ft_two_pts_dist(ray.p, storage.p);
			storage.normal = ft_unit_v(cy.v);
		}
		else
			storage.dist = -1;
		if (res.dist < 0 || (storage.dist < res.dist && storage.dist > 0))
			res = storage;
	}
	storage = ft_cy_side(ray, cy);
	if (res.dist == -1 || (storage.dist < res.dist && storage.dist != -1))
		res = storage;
	res.color = cy.color;
	return (res);
}
