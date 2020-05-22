/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 17:09:25 by nclabaux          #+#    #+#             */
/*   Updated: 2020/05/22 17:32:26 by nclabaux         ###   ########.fr       */
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
