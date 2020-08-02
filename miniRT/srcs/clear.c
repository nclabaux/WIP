/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 16:29:50 by nclabaux          #+#    #+#             */
/*   Updated: 2020/08/02 17:37:30 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int		ft_kill(t_scene *as)
{
	if (as)
	{
		ft_terminator(as);
		ft_destroy_images(as);
	}
	exit(0);
}

void	ft_terminator(t_scene *as)
{
	void	*current;
	void	*next;

	current = as->cam_list;
	while (current)
	{
		next = ((t_camera *)current)->next;
		free(current);
		current = next;
	}
	current = as->light_list;
	while (current)
	{
		next = ((t_light *)current)->next;
		free(current);
		current = next;
	}
	current = as->object_list;
	while (current)
	{
		next = ((t_obj_link *)current)->next;
		free(((t_obj_link *)current)->object);
		free((t_obj_link *)current);
		current = next;
	}
}

void	ft_destroy_images(t_scene *as)
{
	t_img_link	*il;
	t_img_link	*next;

	il = as->img_list;
	while (il)
	{
		mlx_destroy_image(as->mlx, il->ip);
		next = il->next;
		free(il);
		il = next;
	}
}
