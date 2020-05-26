/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 16:09:22 by nclabaux          #+#    #+#             */
/*   Updated: 2020/05/26 18:38:14 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

double	*ft_solve_quadratic(double a, double b, double c)
{
	double	delta;
	double	res[2];

	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (NULL);
	res[0] = (-b - sqrt(delta)) / (2 * a);
	res[1] = (-b + sqrt(delta)) / (2 * a);
	return (res);
}
