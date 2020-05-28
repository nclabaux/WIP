/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 18:52:34 by nclabaux          #+#    #+#             */
/*   Updated: 2020/05/28 15:07:33 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	ft_rgb_to_int(int r, int g, int b)
{
	r = ft_range_check(r);
	g = ft_range_check(g);
	b = ft_range_check(b);
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
