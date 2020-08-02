/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 17:05:07 by nclabaux          #+#    #+#             */
/*   Updated: 2020/08/02 17:39:40 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

void	ft_scene_verif(t_scene *as)
{
	ft_res_verif(as);
	ft_al_verif(as);
	ft_cam_verif(as);
	ft_light_verif(as);
	ft_object_verif(as);
}

void	ft_vector_verif(t_scene *as, t_td *v)
{
	if (!v->x && !v->y && !v->z)
		ft_errors(as, 1020, "");
	if (v->x > 1 || v->y > 1 || v->z > 1 || v->x < -1 || v->y < -1 || v->z < -1)
		ft_errors(as, 1021, "");
	*v = ft_unit_v(*v);
}

void	ft_res_verif(t_scene *as)
{
	int	x;
	int	y;

	if (as->res.x < 1 || as->res.y < 1)
		ft_errors(as, 1006, "");
	mlx_get_screen_size(as->mlx, &x, &y);
	if (as->res.x > x)
	{
		as->res.x = x;
		ft_printf("\033[01;33mHorizontal resolution changed to %d", x);
		ft_printf(" to fit current monitor\n");
	}
	if (as->res.y > y)
	{
		as->res.y = y;
		ft_printf("\033[01;33mVertical resolution changed to %d", y);
		ft_printf(" to fit current display\n");
	}
}

void	ft_al_verif(t_scene *as)
{
	if (as->al.intensity < 0 || as->al.intensity > 1)
		ft_errors(as, 1007, "");
	if (as->al.intensity <= 0.1)
	{
		ft_printf("\033[01;33m");
		if (as->al.intensity == 0)
			ft_printf("No ambient light");
		else
			ft_printf("Ambient light is faint");
		ft_printf(", some objects might not be visible.\n");
	}
}
