/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 17:44:36 by nclabaux          #+#    #+#             */
/*   Updated: 2020/06/28 17:44:18 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	ft_cam_verif(t_scene *ascene)
{
	t_camera	*cam;

	cam = ascene->cam_list;
	if (!cam)
		ft_errors(1019, "");
	while (cam)
	{
		if (cam->fov < 0)
		{
			cam->fov = 0;
			ft_printf("Field of view changed to 0\n");
		}
		if (cam->fov > 180)
		{
			cam->fov = 180;
			ft_printf("Field of view changed to 180\n");
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
			ft_printf("Light brightness changed to 0\n");
		}
		if (ascene->al.intensity > 1)
		{
			ascene->al.intensity = 1;
			ft_printf("Light brightness changed to 1\n");
		}
		light = light->next;
	}
}

void	ft_object_verif(t_scene *ascene)
{
	t_obj_link	*ol;

	ol = ascene->object_list;
	while (ol)
	{
		if (ol->type == 2)
			ft_vector_verif(&(ol->object->pl.v));
		else if (ol->type == 3)
			ft_vector_verif(&(ol->object->sq.v));
		else if (ol->type == 4)
			ft_vector_verif(&(ol->object->cy.v));
		ol = ol->next;
	}
}
