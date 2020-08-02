/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 14:11:37 by nclabaux          #+#    #+#             */
/*   Updated: 2020/08/02 17:38:23 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

void		ft_gen_img(t_scene *as)
{
	t_pixel		px;
	t_ray		ray;
	t_camera	*cam;
	t_img_link	*new;
	int			nbr;

	cam = as->cam_list;
	nbr = as->cam_nbr;
	while (cam)
	{
		ft_printf("\033[01;37m\n\tImage %3d / %d ", nbr, as->cam_nbr);
		new = ft_set_image(*as, &nbr);
		px.y = -1;
		ray.p = cam->p;
		while (++px.y < as->res.y)
		{
			px.cam = cam;
			ft_img_loop(px, as, ray, new);
		}
		ft_add_img_link(as, new);
		ft_printf("\033[01;32mrendered!");
		cam = cam->next;
	}
}

void		ft_img_loop(t_pixel px, t_scene *as, t_ray ray, t_img_link *new)
{
	px.x = -1;
	while (++px.x < as->res.x)
	{
		ray.v = ft_get_ray_v(*as, px.cam, px.x, px.y);
		px.color = ft_get_color(ray, as->mlx, *as);
		ft_add_pixel(new, px);
	}
}

t_img_link	*ft_set_image(t_scene scene, int *nbr)
{
	t_img_link	*r;

	if (!(r = malloc(sizeof(t_img_link))))
		ft_errors(&scene, 1011, "");
	r->ip = mlx_new_image(scene.mlx, scene.res.x, scene.res.y);
	r->fp = (unsigned int *)mlx_get_data_addr(r->ip, &r->bpp, &r->sl, &r->en);
	r->total = scene.cam_nbr;
	r->nbr = *nbr;
	(*nbr)--;
	r->next = NULL;
	return (r);
}

void		ft_add_pixel(t_img_link *il, t_pixel px)
{
	*((il->fp) + (px.x + px.y * il->sl / 4)) = px.color;
}
