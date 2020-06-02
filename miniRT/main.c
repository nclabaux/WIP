/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <nclabaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 17:00:33 by nclabaux          #+#    #+#             */
/*   Updated: 2020/06/02 17:07:02 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		main(int argc, char **argv)
{
	t_scene	scene;
	int		x;
	int		y;
	t_ray	ray;
	t_camera	*cam;

	if (argc < 2)
		ft_errors(1000, "");
	ft_init_scene(&scene);
	ft_read_file(argv[1], &scene);
	VERIFY RESOLUTION;
	cam = scene.cam_list;
	while (cam)
	{
		ALLOCATE IMAGE MEMORY;
		y = 0;
		ray.p = cam->p;
		while (y < scene.res.y)
		{
			x = 0;
			while (x < scene.res.x)
			{
				ray.v = ft_get_ray_v(scene, cam, x, y);
				ft_shot_ray(ray, scene);
				x++;
			}
			y++;
		}
		cam = cam->next;
	}
}

void	ft_init_scene(t_scene *ascene)
{
	ascene->res.x = 0;
	ascene->res.y = 0;
	ascene->al.intensity = 0;
	ascene->al.color.r = 0;
	ascene->al.color.g = 0;
	ascene->al.color.b = 0;
	ascene->cam_list = NULL;
	ascene->light_list = NULL;
	ascene->object_list = NULL;
}

t_vector	ft_get_ray(t_scene scene, t_camera *cam, int x, int y)
{
	t_vector	v;
	t_vector	l;
	t_vector	m;
	int			p;
	int			q;

	l.x = cam->v.y;
	l.y = - cam->v.x;
	l.z = 0;
	if (l.x == 0 && l.y == 0)
		l.x = 1;
	m = ft_cross_product(cam->v, l);
	p = cam->fov / 2 * x / scene.res.x;
	q = cam->fov / 2 * y / scene.res.y;
	if ((x - scene.res.x / 2) * (scene.res.y / 2 - y) < 0)
	{
		v.x = 2 * (cam->p.x + cos(p) * cam->v.x) - sin(p) * sin(q) * l.x * m.x;
		v.y = 2 * (cam->p.y + cos(p) * cam->v.y) - sin(p) * sin(q) * l.y * m.y;
		v.z = 2 * (cam->p.z + cos(p) * cam->v.z) - sin(p) * sin(q) * l.z * m.z;
	}
	else
	{
		v.x = 2 * (cam->p.x + cos(p) * cam->v.x) + sin(p) * sin(q) * l.x * m.x;
		v.y = 2 * (cam->p.y + cos(p) * cam->v.y) + sin(p) * sin(q) * l.y * m.y;
		v.z = 2 * (cam->p.z + cos(p) * cam->v.z) + sin(p) * sin(q) * l.z * m.z;
	}
	return (v);
}

ft_shot_ray(t_ray ray, t_scene scene)
{
	t_obj_link	*obj;
	t_intersec	res;
	t_intersec	storage;

	obj = scene.object_list;
	res.dist = -1;
	while (obj)
	{
		if (obj->type == 1)
			storage = ft_sp_inter(ray, obj->*object);
		else if (obj->type == 2)
			storage = ft_pl_inter(ray, obj->*object);
		else if (obj->type == 3)
			storage = ft_sq_inter(ray, obj->*object);
		else if (obj->type == 4)
			storage = ft_cy_inter(ray, obj->*object);
		else if (obj->type == 5)
			storage = ft_pl_inter(ray, obj->*object);
		else
			storage.dist = -1;
		if (res.dist > 0 && storage.dist < res.dist)
			res = storage;
		obj = obj->next;
	}
	ft_get_light(res, scene);
}
