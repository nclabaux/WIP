/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 11:19:48 by nclabaux          #+#    #+#             */
/*   Updated: 2020/08/02 18:41:20 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

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
	if (t0 <= 0.000001)
		return (res);
	res.p = ft_add_td_n(ray.p, ray.v, t0);
	res.dist = ft_2p_dist(ray.p, res.p);
	res.normal = ft_unit_v(pl.v);
	if (ft_dot(res.normal, ft_unit_v(ft_2p_to_v(res.p, ray.p))) < 0)
		res.normal = ft_inverse(res.normal);
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
		if (!(ft_td_in_triangle(res.p, tr)))
			res.dist = -1;
	}
	res.color = tr.color;
	return (res);
}

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

t_intersec	ft_sp_inter(t_ray ray, t_sphere sp)
{
	double		coef[3];
	double		roots[2];
	t_intersec	res;
	t_td		m;

	res.dist = -1;
	m = ft_2p_to_v(sp.p, ray.p);
	coef[0] = ft_dot(ray.v, ray.v);
	coef[1] = 2 * ft_dot(ray.v, m);
	coef[2] = ft_dot(m, m) - ft_sq(sp.diam / 2);
	if (!(ft_solve_quadra(coef[0], coef[1], coef[2], roots)))
		return (res);
	res = ft_sp_inter2(ray, roots);
	if (res.dist == -1)
		return (res);
	res.color = sp.color;
	res.normal = ft_unit_v(ft_2p_to_v(sp.p, res.p));
	if (ft_2p_dist(ray.p, sp.p) < sp.diam / 2)
		res.normal = ft_inverse(res.normal);
	return (res);
}

t_intersec	ft_sp_inter2(t_ray ray, double r[2])
{
	t_intersec	res;
	t_intersec	storage;

	if (r[0] > 0.000001)
	{
		res.p = ft_add_td_n(ray.p, ray.v, r[0]);
		res.dist = r[0];
	}
	else
		res.dist = -1;
	if (r[1] > 0.000001)
	{
		storage.p = ft_add_td_n(ray.p, ray.v, r[1]);
		storage.dist = r[1];
	}
	else
		storage.dist = -1;
	if (res.dist == -1 || (storage.dist < res.dist && storage.dist != -1))
		res = storage;
	return (res);
}
