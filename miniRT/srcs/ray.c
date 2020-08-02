/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 19:52:53 by nclabaux          #+#    #+#             */
/*   Updated: 2020/08/02 17:39:04 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

t_td		ft_get_ray_v(t_scene scene, t_camera *cam, int x, int y)
{
	double		p;
	double		q;
	t_td		res;

	p = (double)cam->fov / 2 - (double)cam->fov / scene.res.x * x;
	p *= M_PI / 180;
	q = (double)(M_PI * cam->fov * (scene.res.y - (2 * y)));
	q /= (double)(scene.res.x * 360);
	res = ft_multi_td(cam->v, cos(p) + cos(q));
	res = ft_add_td_n(res, cam->l, sin(p));
	res = ft_add_td_n(res, cam->m, sin(q));
	return (ft_unit_v(res));
}

t_intersec	ft_shot_ray(t_ray ray, t_scene scene)
{
	t_obj_link	*obj;
	t_intersec	res;
	t_intersec	storage;

	obj = scene.object_list;
	res.dist = -1;
	while (obj)
	{
		storage.dist = -1;
		if (obj->type == 1)
			storage = ft_sp_inter(ray, obj->object->sp);
		else if (obj->type == 2)
			storage = ft_pl_inter(ray, obj->object->pl);
		else if (obj->type == 4)
			storage = ft_cy_inter(ray, obj->object->cy);
		else if (obj->type == 5)
			storage = ft_tr_inter(ray, obj->object->tr);
		else
			storage.dist = -1;
		if (res.dist == -1 || (storage.dist > 0 && storage.dist < res.dist))
			res = storage;
		obj = obj->next;
	}
	return (res);
}
