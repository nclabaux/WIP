/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 11:19:48 by nclabaux          #+#    #+#             */
/*   Updated: 2020/05/18 18:15:19 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_point	ft_pl_inter(t_point3 point, t_vector3 vector, t_plane pl)
{
	double	d;
	double	t0;
	double	div;
	t_point	res;

	d = -(pl.v.x * pl.p.x + pl.v.y * pl.p.y + pl.v.z * pl.p.z);
	
	div = pl.v.x * vector.x + pl.v.y * vector.y + pl.v.z * vector.z;
	if (!(div))
		NO;
	t0 = (-(pl.v.x * pl.v.x + pl.v.y * pl.v.y + pl.v.z * pl.v.z + d) / div);
	res.x = point.x + vector.x * t0;
	res.y = point.y + vector.y * t0;
	res.z = point.z + vector.z * t0;
	return (res);
}

t_point	ft_sq_inter(t_point3 point, t_vector3 vector, t_square sq)
{
	double	d;
	double	t0;
	double	div;
	t_point	res;

	d = -(sq.v.x * sq.p.x + sq.v.y * sq.p.y + sq.v.z * sq.p.z);
	
	div = sq.v.x * vector.x + sq.v.y * vector.y + sq.v.z * vector.z;
	if (!(div))
		NO;
	t0 = (-(sq.v.x * sq.v.x + sq.v.y * sq.v.y + sq.v.z * sq.v.z + d) / div);
	res.x = point.x + vector.x * t0;
	res.y = point.y + vector.y * t0;
	res.z = point.z + vector.z * t0;
	if (
	return (res);
}
