/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <nclabaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 17:00:33 by nclabaux          #+#    #+#             */
/*   Updated: 2020/07/08 19:27:42 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int			main(int argc, char **argv)
{
	void		*mlx_ptr;
	t_scene		scene;

	ft_printf("\033[01;37m\nHello and welcome in this mini Ray Tracer!\n\n");
	if (argc < 2)
		ft_errors(1000, "");
	ft_init_scene(&scene);
	ft_printf("\033[01;34mReading file...\n");
	ft_read_file(argv[1], &scene);
	mlx_ptr = mlx_init();
	ft_scene_verif(&scene, mlx_ptr);
	ft_printf("\033[01;32mFile read and compliant!\n");
	ft_printf("\033[22;37m\nRendering images... Please wait\n\n");
	ft_gen_img(&scene, mlx_ptr);
	if (argc == 3 && ft_strncmp(argv[3], ft_strdup("-save"), 5))
		(void)scene;//SAVE;
	else
		ft_put_images_to_window(mlx_ptr, &scene);
	return (0);
}

void		ft_put_images_to_window(void *mlx_ptr, t_scene *ascene)
{
	void	*p[4];
	void	*win_ptr;
	int	current;

	ft_printf("\033[22;37m\nYou can use ");
	if (ascene->cam_nbr > 1)
	{
		ft_printf("the\033[01;36m right/left arrow key ");
		ft_printf("\033[22;37mto display the next/previous image and ");
	}
	ft_printf("\033[01;31mesc \033[22;37mto quit.\n");
	win_ptr = mlx_new_window(mlx_ptr, ascene->res.x, ascene->res.y, "miniRT");
	current = 1;
	mlx_put_image_to_window(mlx_ptr, win_ptr, ascene->img_list->ip, 0, 0);
	p[0] = mlx_ptr;
	p[1] = win_ptr;
	p[2] = ascene;
	p[3] = &current;
	ft_disp_prev_img(p);
	mlx_key_hook(win_ptr, ft_key, p);
	mlx_loop(mlx_ptr);
}
