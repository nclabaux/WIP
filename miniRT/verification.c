/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 17:05:07 by nclabaux          #+#    #+#             */
/*   Updated: 2020/07/28 15:41:24 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	ft_scene_verif(t_scene *ascene)
{
	ft_res_verif(ascene);
	ft_al_verif(ascene);
	ft_cam_verif(ascene);
	ft_light_verif(ascene);
	ft_object_verif(ascene);
}

void	ft_td_verif(t_td *v)
{
	if (!v->x && !v->y && !v->z)
		ft_errors(1020, "");
	if (v->x > 1 || v->y > 1 || v->z > 1 || v->x < -1 || v->y < -1 || v->z < -1)
		ft_errors(1021, "");
}

void	ft_res_verif(t_scene *ascene)
{
	int	x;
	int	y;

	if (ascene->res.x < 1 || ascene->res.y < 1)
		ft_errors(1006, "");
	mlx_get_screen_size(ascene->mlx, &x, &y);
	if (ascene->res.x > x)
	{
		ascene->res.x = x;
		ft_printf("\033[01;33mHorizontal resolution changed to %d", x);
		ft_printf(" to fit current monitor\n");
	}
	if (ascene->res.y > y)
	{
		ascene->res.y = y;
		ft_printf("\033[01;33mVertical resolution changed to %d", y);
		ft_printf(" to fit current display\n");
	}
}

void	ft_al_verif(t_scene *ascene)
{
	if (ascene->al.intensity < 0 || ascene->al.intensity > 1)
		ft_errors(1007, "");
	if (ascene->al.intensity <= 0.1)
	{
		ft_printf("\033[01;33m");
		if (ascene->al.intensity == 0)
			ft_printf("No ambient light");
		else
			ft_printf("Ambient light is faint");
		ft_printf(", some objects might not be visible.\n");
	}
}
