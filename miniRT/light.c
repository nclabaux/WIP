/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 15:05:42 by nclabaux          #+#    #+#             */
/*   Updated: 2020/06/23 18:00:46 by nclabaux         ###   ########.fr       */
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
	double	lambert;

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
	i.normal = ft_unit_v(i.normal);
	while (light)
	{
		light_source.p = i.p;
		light_source.v = ft_unit_v(ft_2p_to_v(i.p, light->p));
		storage = ft_shot_ray(light_source, scene);
		lambert = (ft_scalar_prod(light_source.v, i.normal));
		if ((storage.dist == -1
			|| (storage.p.x == light_source.p.x
				&& storage.p.y == light_source.p.y
				&& storage.p.z == light_source.p.z)
			|| storage.dist > ft_two_pts_dist(light->p, i.p))
				&& (lambert > 0 
			|| (i.normal.x == 0 && i.normal.y == 0 && i.normal.z == 0)))
		{
			c.r = 0;
			c.g = 0;
			c.b = 0;
			c = ft_weight_color(light->color, light->brightness);
			c = ft_multiply_colors(c, i.color);
			c = ft_weight_color(c, lambert);
			res = ft_add_colors(res, c);
		}
		light = light->next;
	}
	return (res);
}
