/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 17:09:25 by nclabaux          #+#    #+#             */
/*   Updated: 2020/06/22 12:16:49 by nclabaux         ###   ########.fr       */
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
	return (area1 + area2 + area3 <= tr.area_x2 + 0.000004);
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
	if (!(ft_solve_quadratic(coef[0], coef[1], coef[2], h)))
		return (res);
	if (h[0] >= 0 && h[0] <= cy.height)
	{
		t0 = (h[0] * coef[3] + coef[4]) / coef[5];
		res.p.x = ray.p.x + t0 * ray.v.x;
		res.p.y = ray.p.y + t0 * ray.v.y;
		res.p.z = ray.p.z + t0 * ray.v.z;
		res.dist = ft_two_pts_dist(res.p, ray.p);
		slide.x = cy.p.x + h[0] * cy.v.x / ft_norm(cy.v);
		slide.y = cy.p.y + h[0] * cy.v.y / ft_norm(cy.v);
		slide.x = cy.p.z + h[0] * cy.v.z / ft_norm(cy.v);
		res.normal = ft_2p_to_v(slide, res.p);
	}
	if (h[1] >= 0 && h[1] <= cy.height)
	{
		t0 = (h[0] * coef[3] + coef[4]) / coef[5];
		storage.p.x = ray.p.x + t0 * ray.v.x;
		storage.p.y = ray.p.y + t0 * ray.v.y;
		storage.p.z = ray.p.z + t0 * ray.v.z;
		storage.dist = ft_two_pts_dist(res.p, ray.p);
		slide.x = cy.p.x + h[0] * cy.v.x / ft_norm(cy.v);
		slide.y = cy.p.y + h[0] * cy.v.y / ft_norm(cy.v);
		slide.x = cy.p.z + h[0] * cy.v.z / ft_norm(cy.v);
		storage.normal = ft_2p_to_v(slide, res.p);
	}
	if (storage.dist < res.dist && storage.dist != -1)
		res = storage;
	free(coef);
	return (res);
}

double		*ft_set_number(t_ray ray, t_cylinder cy)
{
	double	*coef;
	double	n[8];

	if (!(coef = malloc(sizeof(double) * 6)))
		return (NULL);
	n[0] = cy.p.x - ray.p.x;
	n[1] = cy.p.y - ray.p.y;
	n[2] = cy.p.z - ray.p.z;
	n[3] = cy.v.x * ray.v.x + cy.v.y * ray.v.y + cy.v.z * ray.v.z;
	n[4] = cy.v.x * cy.v.x + cy.v.y * cy.v.y + cy.v.z * cy.v.z;
	n[5] = ray.v.x * ray.v.x + ray.v.y * ray.v.y + ray.v.z * ray.v.z;
	n[6] = cy.v.x * n[0] + cy.v.y * n[1] + cy.v.z * n[2];
	n[7] = ray.v.x * -n[0] + ray.v.y * -n[1] + ray.v.z * -n[2];
	coef[0] = n[4] * n[4] * n[5] / (n[3] * n[3]) + 3 * n[4];
	coef[1] = 2 * (2 * n[6] + (n[4] / n[3]) * (n[5] * n[6] / n[3] + n[7]));
	coef[2] = (n[6] / n[3]) * (2 * n[7] + n[4] * n[6] / n[3] + n[0] * n[0] + n[1] * n[1] + n[2] * n[2]) - (cy.d / 2) * (cy.d / 2);
	coef[3] = n[4];
	coef[4] = n[6];
	coef[5] = n[3];
	return (coef);
}
