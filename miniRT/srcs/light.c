/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 15:05:42 by nclabaux          #+#    #+#             */
/*   Updated: 2020/08/02 17:38:41 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

t_color	ft_get_light(t_intersec i, t_scene scene)
{
	t_light		*light;
	t_ray		light_source;
	t_intersec	s;
	t_color		res;
	double		lambert;

	res = (t_color){0, 0, 0};
	if (i.dist == -1)
		return (res);
	res = ft_weight_color(scene.al.color, scene.al.intensity);
	res = ft_multiply_colors(i.color, res);
	light = scene.light_list;
	while (light)
	{
		light_source.p = i.p;
		light_source.v = ft_unit_v(ft_2p_to_v(i.p, light->p));
		s = ft_shot_ray(light_source, scene);
		lambert = ft_dot(light_source.v, i.normal);
		if ((s.dist == -1 || (s.p.x == light_source.p.x
			&& s.p.y == light_source.p.y && s.p.z == light_source.p.z)
			|| s.dist + 0.000001 > ft_2p_dist(light->p, i.p)) && lambert > 0)
			res = ft_get_light2(res, light, i, lambert);
		light = light->next;
	}
	return (res);
}

t_color	ft_get_light2(t_color res, t_light *light, t_intersec i, double lambert)
{
	t_color	c;

	c = (t_color){0, 0, 0};
	c = ft_weight_color(light->color, light->brightness);
	c = ft_multiply_colors(c, i.color);
	c = ft_weight_color(c, lambert);
	res = ft_add_colors(res, c);
	return (res);
}
