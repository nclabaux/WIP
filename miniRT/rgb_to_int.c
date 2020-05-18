/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 15:40:22 by nclabaux          #+#    #+#             */
/*   Updated: 2020/05/18 15:40:25 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	rgb_to_int(int r, int g, int b)
{
	r = range_check(r);
	g = range_check(g);
	b = range_check(b);
	return (65536 * r + 256 * g + b);
}

int	range_check(int a)
{
	if (a < 0)
		return (0);
	if (a > 255)
		return (255);
	return (a);
}
