/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 11:19:48 by nclabaux          #+#    #+#             */
/*   Updated: 2020/05/27 17:58:24 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_intersec	ft_pl_inter(t_ray ray, t_plane pl)
{
	double	d;
	double	t0;
	double	div;
	t_intersec	res;

	res = NULL;
	d = -(pl.v.x * pl.p.x + pl.v.y * pl.p.y + pl.v.z * pl.p.z);
	
	div = pl.v.x * ray.v.x + pl.v.y * ray.v.y + pl.v.z * ray.v.z;
	if (!(div))
		return (res); 
	t0 = (-(pl.v.x * pl.v.x + pl.v.y * pl.v.y + pl.v.z * pl.v.z + d) / div);
	*res.p.x = ray.p.x + ray.v.x * t0;
	*res.p.y = ray.p.y + ray.v.y * t0;
	*res.p.z = ray.p.z + ray.v.z * t0;
	*res.dist_2_cam = ft_two_pts_distance(ray.p, *res.p);
	*res.normal = pl.v;
	*res.color = pl.color;
	return (res);
}

t_intersec	ft_tr_inter(t_ray ray, t_triangle tr)
{
	t_vector	v;
	t_plane		pl;
	t_intersec	res;

	v = ft_vec_from_3pts(tr.p1, tr.p2, tr.p3);
	pl.p = tr.p1;
	pl.v = v;
	res = ft_pl_inter(ray, pl);
	res.color = tr.color;
	if (!(ft_point_in_triangle(intersect, tr)))
		res = NULL;
	return (res);
}
	
/*
t_point	ft_sq_inter(t_ray ray, t_square sq)
{
	double	d;
	double	t0;
	double	div;
	t_ray.p	res;

	d = -(sq.v.x * sq.p.x + sq.v.y * sq.p.y + sq.v.z * sq.p.z);
	
	div = sq.v.x * ray.v.x + sq.v.y * ray.v.y + sq.v.z * ray.v.z;
	if (!(div))
		NO;
	t0 = (-(sq.v.x * sq.v.x + sq.v.y * sq.v.y + sq.v.z * sq.v.z + d) / div);
	res.x = ray.p.x + ray.v.x * t0;
	res.y = ray.p.y + ray.v.y * t0;
	res.z = ray.p.z + ray.v.z * t0;
	if ()
	return (res);
}
*/

t_intersec	ft_sp_inter(t_ray ray, t_sphere sp)
{
	double	t0;
	double	coef[3];
	double	roots[2];
	t_intersec	res;
	t_point		storage;

	res = NULL;
	coef[0] = ray.v.x * ray.v.x + ray.v.y * ray.v.y + ray.v.z * ray.v.z;
	coef[1] = 2 * (ray.v.x * (ray.p.x - sp.point.x) + ray.v.y * (ray.p.y - sp.point.y) + + ray.v.y * (ray.p.y - sp.point.y));
	coef[2] = -((sp.diamater / 2) * (sp.diamater / 2) + ray.p.x * ray.p.x + ray.p.y * ray.p.y + ray.p.z * ray.p.z - 2 * (ray.p.x * sp.point.x + ray.p.y * sp.point.y + ray.p.z * sp.point.z));
	if (!(roots = ft_solve_quadratic(coef[0], coef[1], coef[2])))
		return (res);
	t0 = roots[0];
	res.p.x = ray.p.x + t0 * ray.v.x;
	res.p.y = ray.p.y + t0 * ray.v.y;
	res.p.z = ray.p.z + t0 * ray.v.z;
	res.dist_2_cam = ft_two_pts_dist(res.p, ray.p);
	t0 = roots[1];
	storage.p.x = ray.p.x + t0 * ray.v.x;
	storage.p.y = ray.p.y + t0 * ray.v.y;
	storage.p.z = ray.p.z + t0 * ray.v.z;
	if (ft_two_pts_dist(res.p, ray.p) < res.dist_2_cam)
	{
		res.p = storage;
		res.dist_2_cam = ft_two_pts_dist(res.p, ray.p);
	}
	res.color = sp.color;
	res.normal = ft_vec_from_2pts(sp.p, res.p);
	return (res);
}

t_intersec	ft_cy_inter(t_ray ray, t_cylinder cy)
{
	t_intersec	res;
	t_intersec	storage;
	t_plane base_disc;
	t_plane upper_disc;

	base_disc.p = cy.point;
	base_disc.v = cy.orientation;
	upper_disc.p.x = cy.p.x + cy.height * cy.orientation.x / ft_norm(cy.orientation);
	upper_disc.p.y = cy.p.y + cy.height * cy.orientation.y / ft_norm(cy.orientation);
	upper_disc.p.z = cy.p.z + cy.height * cy.orientation.z / ft_norm(cy.orientation);
	upper_disc.v = cy.orientation;
	if (res = ft_pl_inter(ray, base_disc))
	{
		if (ft_two_pts_dist(res.p, cy.p) <= ft_sq(cy.diameter / 2))
		{
			res.dist_2_cam = (ray.p, res.p);
			res.normal = cy.v;
		}
		else
			res = NULL;
	}
	if (storage = ft_pl_inter(ray, upper_disc))
	{
		if (ft_two_pts_dist(storage.p, upper_disc.p) <= ft_sq(cy.diameter / 2))
		{
			storage.dist = (ray.p, storage.p);
			storage.normal = cy.v;
		}
		else
			storage = NULL;
		if (storage.dist < res.dist)
			res = storage;
	}
	if (storage = ft_cy_side(ray, cy))
	{
		if (storage.dist < res.dist)
			res = storage;
	}
	return (res);
}
