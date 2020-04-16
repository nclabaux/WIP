/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux </var/mail/nclabaux>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 17:29:08 by nclabaux          #+#    #+#             */
/*   Updated: 2020/04/16 17:15:16 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	X = 1536;
int	Y = 256;
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
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, rgb_to_int(255, x, 0));
			else if (x < 512)
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, rgb_to_int(512 - x, 255, 0));
			else if (x < 768)
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, rgb_to_int(0, 255, x-512));
			else if (x < 1024)
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, rgb_to_int(0, 1024 - x, 255));
			else if (x < 1280)
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, rgb_to_int(x - 1024, 0, 255));
			else if (x < 1536)
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, rgb_to_int(255, 0, 1536-x));
		}		
	}
	mlx_key_hook(win_ptr, &key_esc, 0);
	//mlx_loop(mlx_ptr);
	for (x = 0; x < 200; x++)
		printf("Error %3d : %s\n", x, strerror(x));
	return (0);
}
