/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 12:06:55 by nclabaux          #+#    #+#             */
/*   Updated: 2020/06/22 16:14:32 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	ft_set_tr_data(t_triangle *tr)
{
	tr->area_x2 = ft_norm(ft_cross_prod(ft_2p_to_v(tr->p1, tr->p2), ft_2p_to_v(tr->p1, tr->p3)));
}

void	ft_set_sq_data(t_square *sq)
{
	t_vector	s;
	t_vector	t;

	s.x = 0;
	s.y = -sq->v.z;
	s.z = sq->v.y;
	if (!sq->v.y && !sq->v.z)
	{
		s.x = sq->v.z;
		s.y = -sq->v.x;
		s.z = 0;
	}
	s = ft_unit_v(s);
	t = ft_cross_prod(ft_unit_v(sq->v), s);
	sq->a.p1 = sq->p;
	sq->a.p2 = ft_add_v(sq->p, s, sq->size);
	sq->a.p3 = ft_add_v(sq->p, t, sq->size);
	sq->b.p1 = sq->a.p2;
	sq->b.p2 = sq->a.p3;
	sq->b.p3 = ft_add_v(sq->a.p2, t, sq->size);
	printf("%lf %lf %lf\n%lf %lf %lf\n%lf %lf %lf\n", sq->a.p1.x, sq->a.p1.y, sq->a.p1.z, sq->a.p2.x, sq->a.p2.y, sq->a.p2.z, sq->a.p3.x, sq->a.p3.y, sq->a.p3.z);
	printf("%lf %lf %lf\n%lf %lf %lf\n%lf %lf %lf\n", sq->b.p1.x, sq->b.p1.y, sq->b.p1.z, sq->b.p2.x, sq->b.p2.y, sq->b.p2.z, sq->b.p3.x, sq->b.p3.y, sq->b.p3.z);
	sq->a.color = sq->color;
	sq->b.color = sq->color;
}
