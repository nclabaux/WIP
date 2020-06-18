/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 15:05:42 by nclabaux          #+#    #+#             */
/*   Updated: 2020/06/18 14:30:37 by nclabaux         ###   ########.fr       */
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
//		ft_printf("in while\n");
		light_source.p = i.p;
		light_source.v = ft_2p_to_v(i.p, light->p);
		storage = ft_shot_ray(light_source, scene);
//		printf("obstacle : %lf\tangle : %lf\n", storage.dist, ft_scalar_prod(light_source.v, i.normal));
		if ((storage.dist == -1 || storage.dist > ft_two_pts_dist(light->p, i.p)) && (ft_scalar_prod(light_source.v, i.normal) > 0 || (i.normal.x == 0 && i.normal.y == 0 && i.normal.z == 0)))
		{
			c.r = 0;
			c.g = 0;
			c.b = 0;
			c = ft_weight_color(light->color, light->brightness);
			c = ft_multiply_colors(c, i.color);
			c = ft_weight_color(c, ft_scalar_prod(light_source.v, i.normal));
			res = ft_add_colors(res, c);
//			ft_printf("get light: %d\t%d\t%d\n", c.r, c.g, c.b);
//			ft_printf("get light: %d\t%d\t%d\n", res.r, res.g, res.b);
		}
		light = light->next;
	}
//	ft_printf("final light:   %d\t%d\t%d\n", res.r, res.g, res.b);
	return (res);
}
