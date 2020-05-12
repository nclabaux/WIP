/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 15:34:32 by nclabaux          #+#    #+#             */
/*   Updated: 2020/05/12 17:37:20 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	ft_add_cam(t_scene *ascene, t_camera *new_cam)
{
	new_cam->next = ascene->cam_list;
	ascene->cam_list = new_cam;
}

void	ft_add_light(t_scene *ascene, t_light *new_light)
{
	new_light->next = ascene->light_list;
	ascene->light_list = new_light;
}

void	ft_add_object(t_scene *ascene, t_obj_link *new_ol)
{
	new_ol->next = ascene->object_list;
	ascene->object_list = new_ol;
}
