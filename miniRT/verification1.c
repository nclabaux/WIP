/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 17:44:36 by nclabaux          #+#    #+#             */
/*   Updated: 2020/07/03 12:18:40 by nclabaux         ###   ########.fr       */
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
		ft_td_verif(&(cam->v));
		if (cam->fov < 0 || cam->fov > 180)
			ft_errors(1012, "");
		cam = cam->next;
	}
}

void	ft_light_verif(t_scene *ascene)
{
	t_light	*light;

	light = ascene->light_list;
	while (light)
	{
		if (light->brightness < 0 || light->brightness > 1)
			ft_errors(1013,"");
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
			ft_td_verif(&(ol->object->pl.v));
		else if (ol->type == 3)
			ft_td_verif(&(ol->object->sq.v));
		else if (ol->type == 4)
			ft_td_verif(&(ol->object->cy.v));
		ol = ol->next;
	}
}
