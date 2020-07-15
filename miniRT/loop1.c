/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 18:08:08 by nclabaux          #+#    #+#             */
/*   Updated: 2020/07/15 19:12:23 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	ft_disp_curr_img(void *p[4])
{
	t_scene		*ascene;
	t_img_link	*il;
	int		*in;
	int		img_nbr;
	
	ascene = p[2];
	il = ascene->img_list;
	in = p[3];
	img_nbr = *in;
	while (img_nbr != il->nbr)
		il = il->next;
	mlx_put_image_to_window(p[0], p[1], il->ip, 0, 0);
	return (0);
}
