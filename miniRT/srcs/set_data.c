/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 12:06:55 by nclabaux          #+#    #+#             */
/*   Updated: 2020/08/02 17:39:09 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

void	ft_set_cam_data(t_camera *cam)
{
	cam->l.x = -cam->v.y;
	cam->l.y = cam->v.x;
	cam->l.z = 0;
	if (ft_norm(cam->l) == 0)
		cam->l.y = -1;
	cam->v = ft_unit_v(cam->v);
	cam->l = ft_unit_v(cam->l);
	cam->m = ft_cross(cam->v, cam->l);
	cam->m = ft_unit_v(cam->m);
}

void	ft_set_tr_data(t_triangle *tr)
{
	t_td u;

	u = ft_cross(ft_2p_to_v(tr->p1, tr->p2), ft_2p_to_v(tr->p1, tr->p3));
	tr->area_x2 = ft_norm(u);
}

void	ft_set_sq_data(t_square *sq, t_scene *as)
{
	t_td	s;
	t_td	t;

	sq->v = ft_unit_v(sq->v);
	s.x = sq->v.z;
	s.y = 0;
	s.z = -sq->v.x;
	if (!sq->v.y && !sq->v.z)
		s = (t_td) {0, 1, 0};
	if (!sq->v.x && !sq->v.z)
		s.z = 1;
	s = ft_unit_v(s);
	t = ft_cross(ft_unit_v(sq->v), s);
	sq->a.p1 = sq->p;
	sq->a.p2 = ft_add_td_n(sq->p, s, sq->size);
	sq->a.p3 = ft_add_td_n(sq->p, t, sq->size);
	sq->b.p1 = sq->a.p2;
	sq->b.p2 = sq->a.p3;
	sq->b.p3 = ft_add_td_n(sq->a.p2, t, sq->size);
	sq->a.color = sq->color;
	sq->b.color = sq->color;
	ft_create_4tr_sq(sq, as);
}

void	ft_create_4tr_sq(t_square *sq, t_scene *as)
{
	ft_alloc_tr(sq->a, as);
	ft_alloc_tr(sq->b, as);
}

void	ft_alloc_tr(t_triangle tr, t_scene *as)
{
	t_obj_link	*ol;
	t_obj_link	*ol_bis;

	if (!(ol = malloc(sizeof(t_obj_link))))
		ft_errors(as, 1011, "");
	if (!(ol->object = malloc(sizeof(t_object))))
		ft_errors(as, 1011, "");
	if (!(ol_bis = malloc(sizeof(t_obj_link))))
		ft_errors(as, 1011, "");
	if (!(ol_bis->object = malloc(sizeof(t_object))))
		ft_errors(as, 1011, "");
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
	ft_add_object(as, ol);
	ft_set_tr_data(&(ol_bis->object->tr));
	ft_add_object(as, ol_bis);
}
