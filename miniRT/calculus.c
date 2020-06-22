/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 16:09:22 by nclabaux          #+#    #+#             */
/*   Updated: 2020/06/22 12:11:47 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		ft_solve_quadratic(double a, double b, double c, double root[2])
{
	double	delta;

	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (0);
	root[0] = (-b - sqrt(delta)) / (2 * a);
	root[1] = (-b + sqrt(delta)) / (2 * a);
	return (1);
}

double	ft_sq(double x)
{
	return (x * x);
}

double	ft_max_double(double a, double b)
{
	if (a < b)
		return (b);
	return (a);
}

double	ft_min_double(double a, double b)
{
	if (a > b)
		return (b);
	return (a);
}
