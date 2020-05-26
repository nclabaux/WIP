/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 17:09:25 by nclabaux          #+#    #+#             */
/*   Updated: 2020/05/26 19:32:33 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

double	ft_point_in_triangle(t_point p, t_triangle tr)
{
	double	area_tr;
	double	area1;
	double	area2;
	double	area3;

	area_tr = ft_norm(ft_cross_product(ft_2p2v(tr.p1, tr.p2),ft_2p2v(tr.p1, tr.p3)));
	area_1 = ft_norm(ft_cross_product(ft_2p2v(p, tr.p1),ft_2p2v(p, tr.p2)));
	area_2 = ft_norm(ft_cross_product(ft_2p2v(p, tr.p1),ft_2p2v(p, tr.p3)));
	area_3 = ft_norm(ft_cross_product(ft_2p2v(p, tr.p2),ft_2p2v(p, tr.p3)));
	return (area1 + area2 + area3 - area_tr);
}

t_intersec	ft_cy_side(t_ray ray, t_cylinder cy)
{
	double	t0;
	double	h[2];
	double	coef[3];
	double	num[8];
	t_intersec	res;

	ft_set_number(&num, ray, cy);
	coef[0] = num[4] * num[4] * num[5] / (num[3] * num[3]) + 3 * num[4];
	coef[1] = 2 * (2 * num[6] + (num[4] / num[3]) * (num[5] * num[6] / num[3] + num[7];
	coef[2] = (num[6] / num[3]) * (2 * num[7] + num[4] * num[6] / num[3] + num[0] * num[0] + num[1] * num[1] + num[2] * num[2]) - (cy.d / 2) * (cy.d / 2);
	if (!(h = ft_solve_quadratic(coef[0], coef[1], coef[2])))
		ABORT;
	CHECK VALUE OF H;
	t0 = ;// w/ h1
	DISTANCE;
	t0 = ;// w/ h2
	DISTANCE;
	return (PLUS PORCHE);
}

double	ft_set_number(double **an, t_ray ray, t_cylinder cy)
{
	(*an)[0] = cy.p.x - ray.p.x;
	(*an)[1] = cy.p.y - ray.p.y;
	(*an)[2] = cy.p.z - ray.p.z;
	(*an)[3] = cy.v.x * ray.v.x + cy.v.y * ray.v.y + cy.v.z * ray.v.z;
	(*an)[4] = cy.v.x * cy.v.x + cy.v.y * cy.v.y + cy.v.z * cy.v.z;
	(*an)[5] = ray.v.x * ray.v.x + ray.v.y * ray.v.y + ray.v.z * ray.v.z;
	(*an)[6] = cy.v.x * (*an)[0] + cy.v.y * (*an)[1] + cy.v.z * (*an)[2];
	(*an)[7] = ray.v.x * -(*an)[0] + ray.v.y * -(*an)[1] + ray.v.z * -(*an)[2];
}

