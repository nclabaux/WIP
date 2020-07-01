/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 12:06:55 by nclabaux          #+#    #+#             */
/*   Updated: 2020/07/01 18:01:26 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	ft_set_tr_data(t_triangle *tr)
{
	tr->area_x2 = ft_norm(ft_cross_prod(ft_2p_to_v(tr->p1, tr->p2), ft_2p_to_v(tr->p1, tr->p3)));
}

void	ft_set_sq_data(t_square *sq, t_scene *ascene)
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
	sq->a.color = sq->color;
	sq->b.color = sq->color;
	ft_create_4tr_sq(sq, ascene);
}

void	ft_create_4tr_sq(t_square *sq, t_scene *ascene)
{
	ft_alloc_tr(sq->a, ascene);
	ft_alloc_tr(sq->b, ascene);
}

void	ft_alloc_tr(t_triangle tr, t_scene *ascene)
{
	t_obj_link	*ol;
	t_obj_link	*ol_bis;

	if (!(ol = malloc(sizeof(t_obj_link))))
		ft_errors(1011, "");
	if (!(ol->object = malloc(sizeof(t_object))))
		ft_errors(1011, "");
	if (!(ol_bis = malloc(sizeof(t_obj_link))))
		ft_errors(1011, "");
	if (!(ol_bis->object = malloc(sizeof(t_object))))
		ft_errors(1011, "");
	ol->type = 5;
	ol->next = NULL;
	ol_bis->type = 5;
	ol_bis->next = NULL;
	ol->object->tr = tr;
	ol_bis->object->tr.p1 = ol->object->tr.p1;
	ol_bis->object->tr.p2 = ol->object->tr.p3;
	ol_bis->object->tr.p3 = ol->object->tr.p2;
	ol->object->tr.color = tr.color;
	ol_bis->object->tr.color = tr.color;
	ft_set_tr_data(&(ol->object->tr));
	ft_add_object(ascene, ol);
	ft_set_tr_data(&(ol_bis->object->tr));
	ft_add_object(ascene, ol_bis);
}
