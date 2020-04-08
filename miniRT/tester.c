/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux </var/mail/nclabaux>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 17:29:08 by nclabaux          #+#    #+#             */
/*   Updated: 2020/04/07 18:00:29 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdio.h>

int main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	printf("here we go");
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		printf("shit arrive");
	win_ptr = mlx_new_window(mlx_ptr, 100, 100, "test window");
	mlx_pixel_put(mlx_ptr, win_ptr, 10, 10, 0xFF0000);
	mlx_string_put(mlx_ptr, win_ptr, 20, 10, 255, "<- red pixel ?");
}
