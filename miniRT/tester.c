/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux </var/mail/nclabaux>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 17:29:08 by nclabaux          #+#    #+#             */
/*   Updated: 2020/06/09 16:54:41 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	X = 256*6;
int	Y = 512;
void	*mlx_ptr;
void	*win_ptr;
int	errno;

int	key_esc(int key, void *p)
{
	if (key == 65307)
	{
		mlx_destroy_window(mlx_ptr, win_ptr);
		exit (0);
	}
	else if (key == 178)
	{
		errno = 13;
		perror("Error 13: Testing perror()");
	}
	else if (key == 65289)
	{
		printf("Error 10: %s\n", strerror(10));
	}
	else
		printf("number of key pressed : %d\n", key);
	return (0);
}

int	mousetrack(int button, int x, int y, void *p)
{
	printf("x : %d, y : %d\n", x ,y);
}

int	main()
{
	int	x;
	int	y;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, X, Y, "test window");
	for (x = 0; x < X; x++)
	{
		for (y = 0; y < Y; y++)
		{
			if (x < 256)
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, ft_rgb_to_int(255, x, 0));
			else if (x < 512)
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, ft_rgb_to_int(512 - x, 255, 0));
			else if (x < 768)
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, ft_rgb_to_int(0, 255, x-512));
			else if (x < 1024)
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, ft_rgb_to_int(0, 1024 - x, 255));
			else if (x < 1280)
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, ft_rgb_to_int(x - 1024, 0, 255));
			else if (x < 1536)
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, ft_rgb_to_int(255, 0, 1536-x));
		}		
	}
	mlx_key_hook(win_ptr, &key_esc, 0);
	mlx_mouse_hook(win_ptr, &mousetrack, 0);
/*	mlx_loop(mlx_ptr);
	for (x = 0; x < 135; x++)
		printf("Error %3d : %s\n", x, strerror(x));*/
	int	*image;
	t_scene	scene;
	image = mlx_new_image(mlx_ptr, 2, 2);

	ft_init_scene(&scene);
	scene.res.x = 2;
	scene.res.y = 2;
	ft_create_bmp(image, "test.bmp", scene);
	mlx_loop(mlx_ptr);
	return (0);
}
