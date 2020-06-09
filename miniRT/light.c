/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 15:05:42 by nclabaux          #+#    #+#             */
/*   Updated: 2020/06/09 16:27:00 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_color	ft_get_light(t_intersec i, t_scene scene)
{
	t_light	*light;
	t_ray	light_source;
	t_intersec	storage;
	t_color		c;
	t_color	res;

	if (i.dist == -1)
	{
		res.r = 0;
		res.g = 0;
		res.b = 0;
		return (res);
	}
	c = ft_weight_color(scene.al.color, scene.al.intensity);
	res = ft_multiply_colors(i.color, c);
	light = scene.light_list;
	while (light)
	{
		light_source.p = i.p;
		light_source.v = ft_2p_to_v(i.p, light->p);
		storage = ft_shot_ray(light_source, scene);
		if (storage.dist == -1 && ft_scalar_prod(light_source.v, i.normal) > 0)
		{
			c.r = 0;
			c.g = 0;
			c.b = 0;
			c = ft_multiply_colors(light->color, i.color);
			c = ft_weight_color(c, ft_scalar_prod(light_source.v, i.normal));
			res = ft_add_colors(res, c);
			ft_color_verif(&res);
		}
		light = light->next;
	}
	return (res);
}
