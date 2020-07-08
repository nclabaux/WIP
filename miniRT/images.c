/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 14:11:37 by nclabaux          #+#    #+#             */
/*   Updated: 2020/07/08 19:16:38 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	ft_gen_img(t_scene *ascene, void *mlx_ptr)
{
	t_pixel	px;
	t_ray			ray;
	t_camera		*cam;
	t_img_link		*new;
	int				nbr;

	cam = ascene->cam_list;
	if (!(new = malloc(sizeof(t_img_link))))
		ft_errors(1011, "");
	nbr = 1;
	while (cam)
	{
		ft_printf("\033[01;37m\tImage %d / %d ", nbr, ascene->cam_nbr);
		new = ft_set_image(mlx_ptr, *ascene);
		new->next = NULL;
		px.y = 0;
		ray.p = cam->p;
		while (px.y < ascene->res.y)
		{
			px.x = 0;
			while (px.x < ascene->res.x)
			{
				ray.v = ft_get_ray_v(*ascene, cam, px.x, px.y);
				px.color = ft_get_color(ray, mlx_ptr, *ascene);
				ft_add_pixel(new, px);
				px.x++;
			}
			px.y++;
		}
		new->total = ascene->cam_nbr;
		new->nbr = nbr++;
		ft_add_img_link(ascene, new);
		ft_printf("\033[01;32mrendered!\n");
		cam = cam->next;
	}
}

t_img_link	*ft_set_image(void *mlx_ptr, t_scene scene)
{
	t_img_link	*res;
	
	if (!(res = malloc(sizeof(t_img_link))))
		ft_errors(1011, "");
	res->ip = mlx_new_image(mlx_ptr, scene.res.x, scene.res.y);
	res->fp = (unsigned int *)mlx_get_data_addr(res->ip, &res->bpp, &res->sl, &res->en);
	return (res);
}

void	ft_add_pixel(t_img_link *il, t_pixel px)
{
	*((il->fp) + (px.x + px.y * il->sl / 4)) = px.color;
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
