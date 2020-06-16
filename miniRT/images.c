/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 14:11:37 by nclabaux          #+#    #+#             */
/*   Updated: 2020/06/15 16:29:26 by nclabaux         ###   ########.fr       */
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
	unsigned int	color;
	void	*win_ptr;

	cam = scene.cam_list;
	if (!(new = malloc(sizeof(t_img_link))))
		return ;
	while (cam)
	{
		//ft_set_image(&new, mlx_ptr, scene);
		win_ptr = mlx_new_window(mlx_ptr, scene.res.x, scene.res.y, "one");
		if (*img_lst)
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
				color = ft_get_color(ray, mlx_ptr, scene);	
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
//				ft_printf("%d\n", color);
				(void)color;
				x++;
			}
			y++;
		}
		cam = cam->next;
	}
}

void	ft_set_image(t_img_link **il, void *mlx_ptr, t_scene scene)
{
	ft_printf("%p\n%p\n%d\t%d\n", *il, mlx_ptr, scene.res.x, scene.res.y);
	(*il)->ip = mlx_new_image(mlx_ptr, scene.res.x, scene.res.y);
	(*il)->fp = mlx_get_data_addr(&((*il)->ip), &((*il)->bpp), &((*il)->sl), &((*il)->en));
	ft_printf("\nip:%p\tfp:%p\tbpp:%d\tsl:%d\tendian:%d\n", (*il)->ip, (*il)->fp, (*il)->bpp, (*il)->sl, (*il)->en);
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
