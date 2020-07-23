/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 19:52:53 by nclabaux          #+#    #+#             */
/*   Updated: 2020/07/23 19:29:53 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void		ft_init_scene(t_scene *ascene)
{
	ascene->res.x = 0;
	ascene->res.y = 0;
	ascene->al.intensity = 0;
	ascene->al.color.r = 0;
	ascene->al.color.g = 0;
	ascene->al.color.b = 0;
	ascene->cam_list = NULL;
	ascene->cam_nbr = 0;
	ascene->light_list = NULL;
	ascene->object_list = NULL;
	ascene->img_list = NULL;
}

t_td	ft_get_ray_v(t_scene scene, t_camera *cam, int x, int y)
{
	double		p;
	double		q;
	t_td		z;
	t_td		u;
	t_td		v;

	p = (((double)cam->fov / 2 - (double)cam->fov / scene.res.x * x) * M_PI / 180);
	q = -(double)(M_PI * cam->fov * (scene.res.y - (2 * y))) / (double)(scene.res.x * 360);
	cam->v = ft_unit_v(cam->v);
	z = (t_td) {0,0,1};
	if (cam->v.x == 0 && cam->v.y == 0)
		z = (t_td) {1,0,0};
	u = ft_multi_td(cam->v, cos(p));
	u = ft_add_td_n(u, z, (1 - cos(p)) * ft_dot(cam->v, z));
	u = ft_add_td_n(u, ft_cross(z, cam->v), sin(p));
	if (cam->v.x == 0 && cam->v.y == 0)
		u.x = 0;
	else
		u.z = 0;
	u = ft_unit_v(u);
	v = ft_get_ray_v2(q, cam->v);
	z = ft_add_td_n(u, v, 1);
	return (ft_unit_v(z));
}

t_td	ft_get_ray_v2(double q, t_td v)
{
	t_td	res;
	t_td	h;

	h = v;
	if (v.x == 0 && v.y == 0)
		h = (t_td) {0, -v.z, v.y};
	else
		h = (t_td) {-v.y, v.x, 0};
	h = ft_unit_v(h);
	res = ft_multi_td(v, cos(q));
	res = ft_add_td_n(res, h, (1 - cos(q)) * ft_dot(v, h));
	res = ft_add_td_n(res, ft_cross(h, v), sin(q));
	return (res);
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
