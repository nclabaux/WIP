/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorial_calculus1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:45:15 by nclabaux          #+#    #+#             */
/*   Updated: 2020/06/08 16:39:45 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_point	ft_add_v(t_point p, t_vector v, double	coef)
{
	t_point	res;

	res.x = p.x + v.x * coef;
	res.y = p.y + v.y * coef;
	res.z = p.z + v.z * coef;
	return (res);
}

t_vector	ft_unit_v(t_vector v)
{
	double	norm;
	t_vector	res;

	norm = ft_norm(v);
	res.x = v.x / norm; 
	res.y = v.y / norm; 
	res.z = v.z / norm; 
	return (res);
}
