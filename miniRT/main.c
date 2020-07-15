/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <nclabaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 17:00:33 by nclabaux          #+#    #+#             */
/*   Updated: 2020/07/15 19:11:09 by nclabaux         ###   ########.fr       */
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
	ft_printf("\033[22;37m\nRendering images... Please wait\n");
	if (scene.cam_nbr > 1)
		ft_printf("(images are rendered from last to first camera)\n");
	ft_gen_img(&scene, mlx_ptr);
	ft_printf("\n");
	if (argc == 3 && !ft_strncmp(argv[3], ft_strdup("-save"), 5))
		ft_save_images_to_bmp(&scene);
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
	mlx_key_hook(win_ptr, ft_key, p);
	mlx_hook(win_ptr, DestroyNotify, StructureNotifyMask, ft_close_program, ascene);
	mlx_hook(win_ptr, FocusIn, FocusChangeMask, ft_disp_curr_img, p);
	mlx_loop(mlx_ptr);
}

void		ft_save_images_to_bmp(t_scene *ascene)
{
	t_img_link	*il;

	il = ascene->img_list;
	while (il)
	{
		ft_save_img(il, ascene);
		il = il->next;
	}
	ft_printf("\n\033[22;32mThe image");
	if (ascene->cam_nbr == 1)
		ft_printf(" has ");
	else
		ft_printf("s have "); 	
	ft_printf("succesfully been saved in ");
	ft_printf("\033[01;36msaves/ \033[22;32mdirectory\n\033[22;37m");
}
