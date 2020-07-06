/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <nclabaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 17:00:33 by nclabaux          #+#    #+#             */
/*   Updated: 2020/07/06 14:25:07 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int			main(int argc, char **argv)
{
	void		*mlx_ptr;
	t_scene		scene;

	if (argc < 2)
		ft_errors(1000, "");
//	if (argc == 3 && ft_strcmp(argv[3], ft_strdup("-save")))
		//SAVE;
	ft_init_scene(&scene);
	ft_read_file(argv[1], &scene);
	mlx_ptr = mlx_init();
	ft_scene_verif(&scene, mlx_ptr);
	ft_gen_img(&scene, mlx_ptr);
	//AFFICHER LA PREMIERE CAM;
	//MAYBE STHG;
	ft_printf("done\n");
	mlx_loop(mlx_ptr);
}
