/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 18:52:34 by nclabaux          #+#    #+#             */
/*   Updated: 2020/06/11 14:21:12 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	ft_rgb_to_int(int r, int g, int b)
{
	return (65536 * r + 256 * g + b);
}

t_color	ft_int_to_rgb(int c)
{
	t_color	res;

	res.r = c / 65536;
	c -= res.r;
	res.g = c / 256;
	c -= res.g;
	res.b = c;
	return (res);
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

	res.r = a.r / 255 * b.r / 255;
	res.g = a.g / 255 * b.g / 255;
	res.b = a.b / 255 * b.b / 255;
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
