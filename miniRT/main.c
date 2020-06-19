/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <nclabaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 17:00:33 by nclabaux          #+#    #+#             */
/*   Updated: 2020/06/19 17:39:14 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		main(int argc, char **argv)
{
	void	*mlx_ptr;
	t_scene	scene;
	t_img_link	*img_list;

	if (argc < 2)
		ft_errors(1000, "");
	ft_init_scene(&scene);
	ft_read_file(argv[1], &scene);
	mlx_ptr = mlx_init();
	ft_scene_verif(&scene, mlx_ptr);
	img_list = NULL;
	ft_gen_images(scene, &img_list, mlx_ptr);
	//AFFICHER LA PREMIERE CAM;
	//MAYBE STHG;
	ft_printf("done\n");
	mlx_loop(mlx_ptr);
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

t_vector	ft_get_ray_v(t_scene scene, t_camera *cam, int x, int y)
{
	t_vector	v;
	double			p;
	double			q;

	p = ((double)cam->fov / 2 - (double)cam->fov / scene.res.x * x) * M_PI / 180;
	q = ((double)cam->fov / 2 * (double)scene.res.y / scene.res.x - (double)cam->fov / scene.res.x * y) * M_PI / 180;
	v.x = (cam->v.x * cos(p) + cam->l.x * sin(p)) * cos(q) + cam->m.x * sin(q);
	v.y = (cam->v.y * cos(p) + cam->l.y * sin(p)) * cos(q) + cam->m.y * sin(q);
	v.z = (cam->v.z * cos(p) + cam->l.z * sin(p)) * cos(q) + cam->m.z * sin(q);
	return (v);
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
		else if (obj->type == 3)
			storage = ft_sq_inter(ray, obj->object->sq);
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
