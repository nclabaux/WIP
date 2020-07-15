/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:20:25 by nclabaux          #+#    #+#             */
/*   Updated: 2020/07/15 17:15:17 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		ft_key(int key, void *p[4])
{
	if (key == 65307)
	{
		mlx_destroy_window(p[0], p[1]);
		ft_terminator(p[2]);
		exit(0);
	}
	else if (key == 65363)
		ft_disp_next_img(p);
	else if (key == 65361)
		ft_disp_prev_img(p);
	return (0);
}

void	ft_disp_next_img(void *p[4])
{
	t_scene		*ascene;
	t_img_link	*il;
	int		*current;
	int		to_be_displayed;

	ascene = p[2];
	il = ascene->img_list;
	current = p[3];
	to_be_displayed = *current + 1;
	if (to_be_displayed > ascene->cam_nbr)
		to_be_displayed = 1;
	*current = to_be_displayed;
	while (il->nbr != to_be_displayed)
		il = il->next;
	mlx_put_image_to_window(p[0], p[1], il->ip, 0, 0);
}

void	ft_disp_prev_img(void *p[4])
{
	t_scene		*ascene;
	t_img_link	*il;
	int		*current;
	int		to_be_displayed;

	ascene = p[2];
	il = ascene->img_list;
	current = p[3];
	to_be_displayed = *current - 1;
	if (to_be_displayed < 1)
		to_be_displayed = ascene->cam_nbr;
	*current = to_be_displayed;
	while (il->nbr != to_be_displayed)
		il = il->next;
	mlx_put_image_to_window(p[0], p[1], il->ip, 0, 0);
}

void	ft_terminator(t_scene *ascene)
{
	void	*current;
	void	*next;
	int	i;

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
		current= next;
	}
	current = ascene->img_list;
	i = 0;
	while (i < ascene->cam_nbr)
	{
		next = ((t_img_link *)current)->next;
		free(((t_img_link *)current)->ip);
		free((t_img_link *)current);
		current = next;
		i++;
	}
}

int	ft_close_program(t_scene *ascene)
{
	ft_terminator(ascene);
	exit(0);
}
