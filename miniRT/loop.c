/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:20:25 by nclabaux          #+#    #+#             */
/*   Updated: 2020/06/03 15:41:32 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int esc_key_pressed(int key, void *p)
{
	if (key == 65307)
	{
		mlx_destroy_window(mlx_ptr, win_ptr);
		DESTROY ALL IMAGES;
		exit(0);
	}
	else if (key == 65361 || key == 65364)
		NEXT IMAGE;
	else if (key == 65362 || key == 65363)
		PREVIOUS IMAGE;
}
	
