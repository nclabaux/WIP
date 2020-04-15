/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 18:19:39 by nclabaux          #+#    #+#             */
/*   Updated: 2020/04/10 18:25:22 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

double	two_pts_dist(t_point3 a, t_point3 b)
{
	return (hypot(hypot((a.x - b.x, a.y - b.y), a.z - b.z));
}
