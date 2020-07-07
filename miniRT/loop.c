/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:20:25 by nclabaux          #+#    #+#             */
/*   Updated: 2020/07/07 20:58:32 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		ft_key(int key, void *p[4])
{
	if (key == 65307)
	{
		mlx_destroy_window(p[0], p[1]);
		ft_terminator(p[3]);
		exit(0);
	}
	else if (key == 65421 || key == 65293 || key == 32)
		ft_disp_next_img((t_img_link **)&p[2], p[0], p[1]);
	return (0);
}

void	ft_disp_next_img(t_img_link **img, void *mlx_ptr, void *win_ptr)
{
	//	*img = (*img)->next;
		mlx_clear_window(mlx_ptr, win_ptr);
	//	mlx_put_image_to_window(mlx_ptr, win_ptr, (*img)->ip, 0, 0);
		(void)img;
}

void	ft_terminator(t_scene *ascene)
{
	t_camera	*cam;
	t_light		*light;
	t_obj_link	*obj;
	t_img_link	*img;
	void		*next;

	cam = ascene->cam_list;
	light = ascene->light_list;
	obj = ascene->object_list;
	img = ascene->img_list;
	while (cam)
	{
		next = cam->next;
		free(cam);
		cam = next;
	}
	while (light)
	{
		next = light->next;
		free(light);
		light = next;
	}
	while (obj)
	{
		next = obj->next;
		free(obj->object);
		free(obj);
		obj = next;
	}
	while (img)
	{
		if (img->next)
		{
			next = img->next;
			img->next = NULL;
			free(img->ip);
			free(img->fp);
			free(img);
			img = next;
		}
	}
}
