/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 14:11:37 by nclabaux          #+#    #+#             */
/*   Updated: 2020/06/05 18:26:20 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	ft_gen_images(t_scene scene, t_img_link **img_lst, void *mlx_ptr)
{
	int	x;
	int	y;
	t_ray	ray;
	t_camera	*cam;
	t_img_link	*new;

	cam = scene.cam_list;
	while (cam)
	{
		new =  mlx_new_image(mlx_ptr, scene.res.x, scene.res.y);
		if (!(*img_lst))
			new->next = *img_lst;
		else
			new->next = NULL;
		*img_lst = new;
		y = 0;
		ray.p = cam->p;
		while (y < scene.res.y)
		{
			x = 0;
			while (x < scene.res.x)
			{
				ray.v = ft_get_ray_v(scene, cam, x, y);
				ft_shot_ray(ray, scene);
				x++;
			}
			y++;
		}
		cam = cam->next;
	}
}
/*
void	ft_create_bmp(void *image, char *filename, t_scene scene)
{
	int fd;
	int	x;
	int	y;
	int	bpp;
	int	size_line;
	int	endian;
	
	fd = open(filename, O_CREAT);
	mlx_get_data_addr(image, &bpp, &size_line, &endian);
	ft_putstr_fd("BA", fd);
	ft_putint_fd(14 + scene.res.x * scene.res.y * bpp, fd);
	ft_putint_fd(0, fd);
	ft_putint_fd(14, fd);
	y = 0;
	while (y < scene.res.y)
	{
		x = 0;
		while (x < scene.res.x * bpp)
		{
			ft_putbyte_fd(*(*image + x + y * size_line), fd);
			x++;
		}
		y++;
	}
}*/
