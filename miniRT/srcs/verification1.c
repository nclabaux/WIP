/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 17:44:36 by nclabaux          #+#    #+#             */
/*   Updated: 2020/08/02 17:39:34 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

void	ft_cam_verif(t_scene *as)
{
	t_camera	*cam;

	cam = as->cam_list;
	if (!cam)
		ft_errors(as, 1019, "");
	while (cam)
	{
		ft_vector_verif(as, &(cam->v));
		if (cam->fov < 0 || cam->fov > 180)
			ft_errors(as, 1012, "");
		cam = cam->next;
	}
}

void	ft_light_verif(t_scene *as)
{
	t_light	*light;

	light = as->light_list;
	while (light)
	{
		if (light->brightness < 0 || light->brightness > 1)
			ft_errors(as, 1013, "");
		light = light->next;
	}
}

void	ft_object_verif(t_scene *as)
{
	t_obj_link	*ol;

	ol = as->object_list;
	if (!ol)
	{
		ft_printf("\033[01;33mNo object in scene, generated image");
		if (as->cam_nbr > 1)
			ft_printf("s");
		ft_printf(" will be completely black.\n");
	}
	while (ol)
	{
		if (ol->type == 2)
			ft_vector_verif(as, &(ol->object->pl.v));
		else if (ol->type == 3)
			ft_vector_verif(as, &(ol->object->sq.v));
		else if (ol->type == 4)
			ft_vector_verif(as, &(ol->object->cy.v));
		ol = ol->next;
	}
}
