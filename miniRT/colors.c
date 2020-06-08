/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 18:52:34 by nclabaux          #+#    #+#             */
/*   Updated: 2020/06/08 19:36:37 by nclabaux         ###   ########.fr       */
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

	res.r = a.r + b.r;
	res.g = a.g + b.g;
	res.b = a.b + b.b;
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
