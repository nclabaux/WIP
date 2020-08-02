/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:20:25 by nclabaux          #+#    #+#             */
/*   Updated: 2020/08/02 17:38:53 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

int		ft_key(int key, void *p[3])
{
	t_scene	*ascene;

	ascene = p[1];
	if (key == 65307)
	{
		mlx_destroy_window(ascene->mlx, p[0]);
		ft_kill(ascene);
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

int		ft_disp_curr_img(void *p[3])
{
	t_scene		*ascene;
	t_img_link	*il;
	int			*in;
	int			img_nbr;

	ascene = p[1];
	il = ascene->img_list;
	in = p[2];
	img_nbr = *in;
	while (img_nbr != il->nbr)
		il = il->next;
	mlx_put_image_to_window(ascene->mlx, p[0], il->ip, 0, 0);
	return (0);
}
