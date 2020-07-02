/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 17:09:25 by nclabaux          #+#    #+#             */
/*   Updated: 2020/07/02 18:01:29 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

double		ft_point_in_triangle(t_point p, t_triangle tr)
{
	double		area1;
	double		area2;
	double		area3;

	area1 = ft_norm(ft_cross_prod(ft_2p_to_v(p, tr.p1), ft_2p_to_v(p, tr.p2)));
	area2 = ft_norm(ft_cross_prod(ft_2p_to_v(p, tr.p1), ft_2p_to_v(p, tr.p3)));
	area3 = ft_norm(ft_cross_prod(ft_2p_to_v(p, tr.p2), ft_2p_to_v(p, tr.p3)));
	return (area1 + area2 + area3 <= tr.area_x2 + 0.000001);
}

t_intersec	ft_cy_side(t_ray ray, t_cylinder cy)
{
	double		t0;
	double		h[2];
	double		*coef;
	t_intersec	res;
	t_intersec	storage;
	t_point		slide;

	res.dist = -1;
	coef = ft_set_number(ray, cy);
	if (!(ft_solve_quadra(coef[0], coef[1], coef[2], h)) || !coef)
		return (res);
	if (h[0] >= 0 && h[0] <= cy.h && (cy.v.x + cy.v.y + cy.v.z))
	{
		ft_printf("h0\n");
		t0 = h[0] * coef[3] + coef[4];
		res.p = ft_add_v(ray.p, ray.v, t0);
		res.dist = ft_two_pts_dist(res.p, ray.p);
		slide = ft_add_v(cy.p, ft_unit_v(cy.v), h[0]);
		res.normal = ft_unit_v(ft_2p_to_v(slide, res.p));
	}
	if (h[1] >= 0 && h[1] <= cy.h && (cy.v.x + cy.v.y + cy.v.z))
	{
		ft_printf("h1\n");
		t0 = h[1] * coef[3] + coef[4];
		storage.p = ft_add_v(ray.p, ray.v, t0);
		storage.dist = ft_two_pts_dist(res.p, ray.p);
		slide = ft_add_v(cy.p, ft_unit_v(cy.v), h[1]);
		storage.normal = ft_unit_v(ft_2p_to_v(slide, res.p));
	}
	if (storage.dist < res.dist && storage.dist != -1)
		res = storage;
	free(coef);
	if (res.dist != -1)
		ft_printf("ok\n");
	return (res);
}

double		*ft_set_number(t_ray ray, t_cylinder cy)
{
	double	*coef;
	double	n[8];

	if (!(ray.v.x * cy.v.x + ray.v.y * cy.v.y + ray.v.z * cy.v.z))
		return (NULL);
	if (!(coef = malloc(sizeof(double) * 5)))
		ft_errors(12, "");
	n[0] = ft_sq(cy.v.x) + ft_sq(cy.v.y) + ft_sq(cy.v.z);
	n[0] /= (ray.v.x * cy.v.x + ray.v.y * cy.v.y + ray.v.z * cy.v.z); 
	n[1] = cy.v.x * (ray.p.x + cy.p.x) + cy.v.y * (ray.p.x + cy.p.y);
	n[1] += cy.v.z * (ray.p.z + cy.p.z);
	n[1] /= (ray.v.x * cy.v.x + ray.v.y * cy.v.y + ray.v.z * cy.v.z); 
	n[2] = ray.v.x * n[0] - cy.v.x;
	n[3] = ray.v.y * n[0] - cy.v.y;
	n[4] = ray.v.z * n[0] - cy.v.z;
	n[5] = ray.p.x + n[1] * ray.v.x - cy.p.x;
	n[6] = ray.p.y + n[1] * ray.v.y - cy.p.y;
	n[7] = ray.p.z + n[1] * ray.v.z - cy.p.z;
	coef[0] = ft_sq(n[2]) + ft_sq(n[3]) + ft_sq(n[4]);
	coef[1] = 2 * (n[2] * n[5] + n[3] * n[6] + n[4] * n[7]);
	coef[2] = ft_sq(n[5]) + ft_sq(n[6]) + ft_sq(n[7]) - ft_sq(cy.d / 2);
	coef[3] = n[0];
	coef[4] = n[1];
	return (coef);
}
