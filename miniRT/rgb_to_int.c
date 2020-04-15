/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux </var/mail/nclabaux>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 18:01:48 by nclabaux          #+#    #+#             */
/*   Updated: 2020/04/07 18:16:56 by nclabaux         ###   ########.fr       */
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
