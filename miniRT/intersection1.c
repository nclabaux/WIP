/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 17:09:25 by nclabaux          #+#    #+#             */
/*   Updated: 2020/07/27 19:27:40 by nclabaux         ###   ########.fr       */
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
	t_td	u;
	t_td	v;
	double	coef[3];
	double	root[2];
	t_intersec	res;
	t_intersec	storage;
	double	d1;
	double	d2;

	res.dist = -1;
	v = ft_multi_td(cy.v, ft_dot(ray.v, cy.v));
	v = ft_add_td_n(ray.v, v, -1);
	u = ft_multi_td(cy.v, ft_dot(ft_add_td_n(ray.p, cy.p, -1), cy.v));
	u = ft_add_td_n(ft_add_td_n(ray.p, cy.p, -1), u, -1);
	coef[0] = ft_dot(v, v);
	coef[1] = 2 * ft_dot(v, u);
	coef[2] = ft_dot(u, u) - ft_sq(cy.d / 2);
	if (!(ft_solve_quadra(coef[0], coef[1], coef[2], root)))
		return res;
	d1 = ft_dot(cy.v, ft_2p_to_v(cy.p, ft_add_td_n(ray.p, ray.v, root[0])));
	d2 = ft_dot(cy.v, ft_add_td_n(ft_add_td_n(ray.p, ray.v, root[1]), cy.p, -1));
	if (!((d1 > 0.000001 && d1 < cy.h + 0.000001 && root[0] > 0.000001) || (d2 > 0.000001 && d2 < cy.h + 0.000001 && root[1] > 0.000001)))
		return (res);
	res.p = ft_2p_to_v(cy.p, ft_add_td_n(ray.p, ray.v, root[0]));
	res.dist = ft_2p_dist(ray.p, res.p);
	res.normal = ft_unit_v(ft_add_td_n(ft_add_td_n(ft_multi_td(ray.v, root[0]), ft_multi_td(cy.v, d1), -1), ft_add_td_n(cy.p, ray.p, -1), -1));
	storage.p = ft_2p_to_v(cy.p, ft_add_td_n(ray.p, ray.v, root[1]));
	storage.dist = ft_2p_dist(ray.p, storage.p);
	storage.normal = ft_unit_v(ft_add_td_n(ft_add_td_n(ft_multi_td(ray.v, root[1]), ft_multi_td(cy.v, d2), -1), ft_add_td_n(cy.p, ray.p, -1), -1));
	if (res.dist == -1 || (storage.dist < res.dist && storage.dist != -1))
		res = storage;
	return (res);
}
