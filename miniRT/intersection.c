/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 11:19:48 by nclabaux          #+#    #+#             */
/*   Updated: 2020/05/22 17:34:02 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_point	ft_pl_inter(t_ray ray, t_plane pl)
{
	double	d;
	double	t0;
	double	div;
	t_ray.p	res;

	d = -(pl.v.x * pl.p.x + pl.v.y * pl.p.y + pl.v.z * pl.p.z);
	
	div = pl.v.x * ray.v.x + pl.v.y * ray.v.y + pl.v.z * ray.v.z;
	if (!(div))
		NO;
	t0 = (-(pl.v.x * pl.v.x + pl.v.y * pl.v.y + pl.v.z * pl.v.z + d) / div);
	res.x = ray.p.x + ray.v.x * t0;
	res.y = ray.p.y + ray.v.y * t0;
	res.z = ray.p.z + ray.v.z * t0;
	return (res);
}

void	ft_tr_inter(t_ray ray, t_triangle tr)
{
	t_vector	v;
	t_plane		pl;
	t_point		intersect;

	v = ft_vec_from_3pts(tr.p1, tr.p2, tr.p3);
	pl.p = tr.p1;
	pl.v = v;
	intersect = ft_pl_inter(ray, pl);
	VERIF;
	ft_point_in_triangle(intersect, tr);
	RETURN;
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
void	ft_sp_inter(t_ray ray, t_sphere sp)
{
	double	t0;
	double	delta;
	double	a;
	double	b;
	double	c;

	a = ray.v.x * ray.v.x + ray.v.y * ray.v.y + ray.v.z * ray.v.z;
	b = 2 * (ray.v.x * (ray.p.x - sp.point.x) + ray.v.y * (ray.p.y - sp.point.y) + + ray.v.y * (ray.p.y - sp.point.y));
	c = -((sp.diamater / 2) * (sp.diamater / 2) + ray.p.x * ray.p.x + ray.p.y * ray.p.y + ray.p.z * ray.p.z - 2 * (ray.p.x * sp.point.x + ray.p.y * sp.point.y + ray.p.z * sp.point.z));
	delta = b * b - 4 * a * c;
	if (delta < 0)
		PAS DE CROISEMENT;
	else if (delta == 0)
		ON TOUCHE LE BORD;
	else
	{
		Y A DEUX INTERSECTIONS;
		t0 = (- b - sqrt(delta)) / (2 * a);
		t0 = (- b + sqrt(delta)) / (2 * a);
	}
}
