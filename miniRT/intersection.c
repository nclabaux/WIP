/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 11:19:48 by nclabaux          #+#    #+#             */
/*   Updated: 2020/06/19 17:13:09 by nclabaux         ###   ########.fr       */
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
	res.p.x = ray.p.x + ray.v.x * t0;
	res.p.y = ray.p.y + ray.v.y * t0;
	res.p.z = ray.p.z + ray.v.z * t0;
	res.dist = ft_two_pts_dist(ray.p, res.p);
	res.normal = pl.v;
	res.color = pl.color;
	return (res);
}

t_intersec	ft_tr_inter(t_ray ray, t_triangle tr)
{
	t_vector	v;
	t_plane		pl;
	t_intersec	res;

	v = ft_3p_to_v(tr.p1, tr.p2, tr.p3);
	pl.p = tr.p1;
	pl.v = v;
	res = ft_pl_inter(ray, pl);
	res.color = tr.color;
	if (res.dist != -1)
	{
		if (!(ft_point_in_triangle(res.p, tr)))
			res.dist = -1;
	}
	return (res);
}


t_intersec	ft_sq_inter(t_ray ray, t_square sq)
{
	t_triangle	a;
	t_triangle	b;
	t_vector	s;
	t_vector	t;
	t_intersec	res;
	t_intersec	storage;

	a.p1 = sq.p;
	s.x = 0;
	s.y = -sq.v.z;
	s.z = sq.v.y;
	if (!sq.v.y && !sq.v.z)
	{
		s.x = sq.v.y;
		s.y = -sq.v.x;
		s.z = 0;
	}
	s = ft_unit_v(s);
	a.p2 = ft_add_v(sq.p, s, sq.size);
	t = ft_cross_prod(ft_unit_v(sq.v), s);
	a.p3 = ft_add_v(sq.p, t, sq.size);
	b.p1 = ft_add_v(ft_add_v(sq.p, s, sq.size), t, sq.size);
	b.p2 = a.p2;
	b.p3 = a.p3;
	res = ft_tr_inter(ray, a);
       	storage = ft_tr_inter(ray, b);
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
	coef[1] = 2 * (ray.v.x * (ray.p.x - sp.point.x) + ray.v.y * (ray.p.y - sp.point.y) + ray.v.z * (ray.p.z - sp.point.z));
	coef[2] = -(ft_sq(sp.diameter / 2) + ft_sq(ray.p.x) + ft_sq(ray.p.y) + ft_sq(ray.p.z) - 2 * (ray.p.x * sp.point.x + ray.p.y * sp.point.y + ray.p.z * sp.point.z));
	if (!(ft_solve_quadratic(coef[0], coef[1], coef[2], roots)))
		return (res);
	t0 = roots[0];
	res.p.x = ray.p.x + t0 * ray.v.x;
	res.p.y = ray.p.y + t0 * ray.v.y;
	res.p.z = ray.p.z + t0 * ray.v.z;
	res.dist = ft_two_pts_dist(res.p, ray.p);
	t0 = roots[1];
	storage.p.x = ray.p.x + t0 * ray.v.x;
	storage.p.y = ray.p.y + t0 * ray.v.y;
	storage.p.z = ray.p.z + t0 * ray.v.z;
	storage.dist = ft_two_pts_dist(storage.p, ray.p);
	if (storage.dist < res.dist && storage.dist != -1)
		res = storage;
	res.color = sp.color;
	res.normal = ft_2p_to_v(sp.point, res.p);
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
	upper_disc.p.x = cy.p.x + cy.height * cy.v.x / ft_norm(cy.v);
	upper_disc.p.y = cy.p.y + cy.height * cy.v.y / ft_norm(cy.v);
	upper_disc.p.z = cy.p.z + cy.height * cy.v.z / ft_norm(cy.v);
	upper_disc.v = cy.v;
	res.dist = -1;
	res = ft_pl_inter(ray, base_disc);
	if (res.dist > 0)
	{
		if (ft_two_pts_dist(res.p, cy.p) <= ft_sq(cy.d / 2))
		{
			res.dist = ft_two_pts_dist(ray.p, res.p);
			res.normal = cy.v;
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
			storage.normal = cy.v;
		}
		else
			storage.dist = -1;
		if (res.dist < 0 || (storage.dist < res.dist && storage.dist > 0))
			res = storage;
	}
	storage = ft_cy_side(ray, cy);
	if (res.dist < 0 || (storage.dist < res.dist && storage.dist > 0))
		res = storage;
	return (res);
}
