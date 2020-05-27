/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 18:52:34 by nclabaux          #+#    #+#             */
/*   Updated: 2020/05/27 18:52:36 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	ft_rgb_to_int(int r, int g, int b)
{
	r = range_check(r);
	g = range_check(g);
	b = range_check(b);
	return (65536 * r + 256 * g + b);
}

int	ft_range_check(int a)
{
	if (a < 0)
		return (0);
	if (a > 255)
		return (255);
	return (a);
}
