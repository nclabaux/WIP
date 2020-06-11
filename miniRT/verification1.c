/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 17:44:36 by nclabaux          #+#    #+#             */
/*   Updated: 2020/06/11 14:18:16 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	ft_cam_verif(t_scene *ascene)
{
	t_camera	*cam;

	cam = ascene->cam_list;
	while (cam)
	{
		if (ft_vector_verif(&(cam->v)))
			ft_printf("for camera placed in %lf, %lf, %lf\n", cam->p.x, cam->p.y, cam->p.z);
		if (cam->fov < 0)
		{
			cam->fov = 0;
			ft_printf("Field of view changed to 0 ");
			ft_printf("for camera placed in %lf, %lf, %lf\n", cam->p.x, cam->p.y, cam->p.z);
		}
		if (cam->fov > 180)
		{
			cam->fov = 180;
			ft_printf("Field of view changed to 180 ");
			ft_printf("for camera placed in %lf, %lf, %lf\n", cam->p.x, cam->p.y, cam->p.z);
		}
		cam = cam->next;
	}
}

void	ft_light_verif(t_scene *ascene)
{
	t_light	*light;

	light = ascene->light_list;
	while (light)
	{
		if (light->brightness < 0)
		{
			ascene->al.intensity = 0;
			ft_printf("Light brightness changed to 0 ");
			ft_printf("for light placed in %lf, %lf, %lf\n", light->p.x, light->p.y, light->p.z);
		}
		if (ascene->al.intensity > 1)
		{
			ascene->al.intensity = 1;
			ft_printf("Light brightness changed to 1 ");
			ft_printf("for light placed in %lf, %lf, %lf\n", light->p.x, light->p.y, light->p.z);
		}
		light = light->next;
	}
}
