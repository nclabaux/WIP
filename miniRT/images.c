/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 14:11:37 by nclabaux          #+#    #+#             */
/*   Updated: 2020/06/11 14:28:56 by nclabaux         ###   ########.fr       */
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
	t_color		c;
	unsigned int	color;

	cam = scene.cam_list;
	if (!(new = malloc(sizeof(t_img_link))))
		return ;
	while (cam)
	{
		new->ip =  mlx_new_image(mlx_ptr, scene.res.x, scene.res.y);
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
				new->fp = mlx_get_data_addr(&new->ip, &new->bpp, &new->sl, &new->en);
				ray.v = ft_get_ray_v(scene, cam, x, y);
				c = ft_get_light(ft_shot_ray(ray, scene), scene);
				color = mlx_get_color_value(mlx_ptr, ft_rgb_to_int(c.r, c.g, c.b));
				ft_printf("\nbpp:%d\tcolor:%d\n", new->bpp, color);
				x++;
			}
			y++;
		}
		cam = cam->next;
	}
}

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
	ft_putstr_fd("BM", fd);
	ft_putint_fd(14 + scene.res.x * scene.res.y * bpp, fd);
	ft_putint_fd(0, fd);
	ft_putint_fd(14, fd);
	y = 0;
	while (y < scene.res.y)
	{
		x = 0;
		while (x < scene.res.x * bpp)
		{
			//ft_putbyte_fd((char)(image[x + y * size_line]), fd);
			x++;
		}
		y++;
	}
	close(fd);
}
