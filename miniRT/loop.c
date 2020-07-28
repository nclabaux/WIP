/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:20:25 by nclabaux          #+#    #+#             */
/*   Updated: 2020/07/28 16:21:01 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		ft_key(int key, void *p[3])
{
	t_scene	*ascene;

	ascene = p[1];
	if (key == 65307)
	{
		mlx_destroy_window(ascene->mlx, p[0]);
		ft_close_program(ascene);
	}
	else if (key == 65363)
		ft_disp_next_img(p);
	else if (key == 65361)
		ft_disp_prev_img(p);
	return (0);
}

void	ft_disp_next_img(void *p[3])
{
	t_scene		*ascene;
	t_img_link	*il;
	int			*current;
	int			to_be_displayed;

	ascene = p[1];
	il = ascene->img_list;
	current = p[2];
	to_be_displayed = *current + 1;
	if (to_be_displayed > ascene->cam_nbr)
		to_be_displayed = 1;
	*current = to_be_displayed;
	while (il->nbr != to_be_displayed)
		il = il->next;
	mlx_put_image_to_window(ascene->mlx, p[0], il->ip, 0, 0);
}

void	ft_disp_prev_img(void *p[3])
{
	t_scene		*ascene;
	t_img_link	*il;
	int			*current;
	int			to_be_displayed;

	ascene = p[1];
	il = ascene->img_list;
	current = p[2];
	to_be_displayed = *current - 1;
	if (to_be_displayed < 1)
		to_be_displayed = ascene->cam_nbr;
	*current = to_be_displayed;
	while (il->nbr != to_be_displayed)
		il = il->next;
	mlx_put_image_to_window(ascene->mlx, p[0], il->ip, 0, 0);
}

void	ft_terminator(t_scene *ascene)
{
	void	*current;
	void	*next;

	current = ascene->cam_list;
	while (current)
	{
		next = ((t_camera *)current)->next;
		free(current);
		current = next;
	}
	current = ascene->light_list;
	while (current)
	{
		next = ((t_light *)current)->next;
		free(current);
		current = next;
	}
	current = ascene->object_list;
	while (current)
	{
		next = ((t_obj_link *)current)->next;
		free(((t_obj_link *)current)->object);
		free((t_obj_link *)current);
		current = next;
	}
}

void	ft_destroy_images(t_scene *ascene)
{
	t_img_link	*il;
	t_img_link	*next;

	il = ascene->img_list;
	while (il->nbr < ascene->cam_nbr)
	{
		mlx_destroy_image(ascene->mlx, il->ip);
		next = il->next;
		free(il);
		il = next;
	}
}

int		ft_close_program(t_scene *ascene)
{
	ft_terminator(ascene);
	ft_destroy_images(ascene);
	exit(0);
}
