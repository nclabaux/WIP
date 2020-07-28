/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 18:08:08 by nclabaux          #+#    #+#             */
/*   Updated: 2020/07/28 15:49:27 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	ft_disp_curr_img(void *p[3])
{
	t_scene		*ascene;
	t_img_link	*il;
	int		*in;
	int		img_nbr;
	
	ascene = p[1];
	il = ascene->img_list;
	in = p[2];
	img_nbr = *in;
	while (img_nbr != il->nbr)
		il = il->next;
	mlx_put_image_to_window(ascene->mlx, p[0], il->ip, 0, 0);
	return (0);
}
