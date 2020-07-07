/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <nclabaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 17:00:33 by nclabaux          #+#    #+#             */
/*   Updated: 2020/07/07 20:17:02 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int			main(int argc, char **argv)
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*p[4];
	t_scene		scene;

	if (argc < 2)
		ft_errors(1000, "");
	ft_init_scene(&scene);
	ft_printf("Reading file...\t");
	ft_read_file(argv[1], &scene);
	mlx_ptr = mlx_init();
	ft_scene_verif(&scene, mlx_ptr);
	ft_printf("File read and compliant!\nRendering images... Please wait\n");
	ft_gen_img(&scene, mlx_ptr);
	if (argc == 3 && ft_strncmp(argv[3], ft_strdup("-save"), 5))
		(void)scene;//SAVE;
	else
	{
		ft_printf("Images rendered, you can use the spacebar or the enter key ");
		ft_printf("to display the next image and esc to quit.\n");
		win_ptr = mlx_new_window(mlx_ptr, scene.res.x, scene.res.y, "miniRT");
		mlx_put_image_to_window(mlx_ptr, win_ptr, scene.img_list->ip, 0, 0);
		p[0] = mlx_ptr;
		p[1] = win_ptr;
		p[2] = scene.img_list->ip;
		p[3] = &scene;
		mlx_key_hook(win_ptr, ft_key, p);
		mlx_loop(mlx_ptr);
	}
	return (0);
}
