/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 18:52:34 by nclabaux          #+#    #+#             */
/*   Updated: 2020/06/16 17:13:52 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	ft_rgb_to_int(t_color c)
{
	return (65536 * c.r + 256 * c.g + c.b);
}

t_color	ft_add_colors(t_color a, t_color b)
{
	t_color res;
	int	x;
	
	x = a.r + b.r;
	if (x > 255)
		res.r = 255;
	else
		res.r = x;
	x = a.g + b.g;
	if (x > 255)
		res.g = 255;
	else
		res.g = x;
	x = a.b + b.b;
	if (x > 255)
		res.b = 255;
	else
		res.b = x;
	return (res);
}

t_color	ft_multiply_colors(t_color a, t_color b)
{
	t_color res;
	
	res.r = a.r * b.r / 255;
	res.g = a.g * b.g / 255;
	res.b = a.b * b.b / 255;
	return (res);
}

t_color	ft_weight_color(t_color	c, double intensity)
{
	t_color	res;

	res.r = c.r * intensity;
	res.g = c.g * intensity;
	res.b = c.b * intensity;
	return (res);
}

unsigned int	ft_get_color(t_ray ray, void *mlx_ptr, t_scene scene)
{
	unsigned int	res;
	t_color		color;

	color = ft_get_light(ft_shot_ray(ray, scene), scene);
	res = /*mlx_get_color_value(mlx_ptr,*/ ft_rgb_to_int(color)/*)*/;
//	printf("%d\t%d\t%d\t%u\n", color.r, color.g, color.b, res);
	(void)mlx_ptr;
	return (res);
}
