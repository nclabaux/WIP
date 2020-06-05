/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 17:05:07 by nclabaux          #+#    #+#             */
/*   Updated: 2020/06/05 18:30:52 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	ft_scene_verif(t_scene *ascene, void *mlx_ptr)
{
	ft_res_verif(ascene, mlx_ptr);
	ft_al_verif(ascene);
	ft_cam_verif(ascene);
	ft_light_verif(ascene);
}

int	ft_color_verif(t_color *acolor)
{
	res = 0;
	if (acolor->r < 0)
	{
		acolor->r = 0;
		res = 1;
		ft_printf("Red color setting changed to 0 (min value) ");
	}
	if (acolor->r > 255)
	{
		acolor->r = 255;
		res = 1;
		ft_printf("Red color setting changed to 255 (max value) ");
	}
	if (acolor->g < 0)
	{
		acolor->g = 0;
		res = 1;
		ft_printf("Green color setting changed to 0 (min value) ");
	}
	if (acolor->g > 255)
	{
		acolor->g = 255;
		res = 1;
		ft_printf("Green color setting to 255 (max value) ");
	}
	if (acolor->b < 0)
	{
		acolor->b = 0;
		res = 1;
		ft_printf("Blue color setting changed to 0 (min value) ");
	}
	if (acolor->b > 255)
	{
		acolor->b = 255;
		res = 1;
		ft_printf("Blue color setting changed to 255 (max value) ");
	}
	return (res);
}

int		ft_vector_verif(t_vector *v)
{
	int	res;
	double	max;
	res = 0;
	if (v->x > 1 || v->y > 1 || v->z > 1)
	{
		max = ft_max_double(ft_max_double(v->x, v->y), v->z);
		v->x = v->x / max;
		v->y = v->y / max;
		v->z = v->z / max;
		ft_printf("Vector coord. divided by %lf to fit [-1;1] range ", max);
	}
	if (v->x < -1 || v->y < -1 || v->z < -1)
	{
		max = ft_max_double(ft_max_double(-v->x, -v->y), -v->z);
		v->x = v->x / max;
		v->y = v->y / max;
		v->z = v->z / max;
		ft_printf("Vector coord. divided by %lf to fit [-1;1] range ", max);
	}
}

void	ft_res_verif(t_scene *ascene, void *mlx_ptr)
{
	int	x;
	int	y;
	
	mlx_get_screen_size(mlx_ptr, &x, &y);
	if (ascene->res.x > x)
	{
		scene->res.x = x;
		ft_printf("Horizontal resolution changed to %d to fit current display\n", x);
	}
	if (ascene->res.y > y)
	{
		scene->res.y = y;
		ft_printf("Vertical resolution changed to %d to fit current display\n", y);
	}
}

void	ft_al_verif(t_scene *ascene)
{
	if (ascene->al.intensity < 0)
	{
		ascene->al.intensity = 0;
		ft_printf("Ambient light ratio has been change to 0 (min value)\n");
	}
	if (ascene->al.intensity > 1)
	{
		ascene->al.intensity = 1;
		ft_printf("Ambient light ratio has been change to 1 (max value)\n");
	}
	if (ft_color_verif(&(ascene->al.color)))
		ft_printf("in ambient light\n");
}


