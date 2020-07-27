/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reading1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:12:54 by nclabaux          #+#    #+#             */
/*   Updated: 2020/07/27 18:56:52 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	ft_res_rd(char **s, t_scene *ascene)
{
	int	i;

	if (ascene->res.x || ascene->res.y)
		ft_errors(1003, "");
	i = 1;
	while ((*s)[i] && ft_isspace((*s)[i]))
		i++;
	if (ft_isdigit((*s)[i]))
		ascene->res.x = ft_atoi(*s + i);
	else
		ft_errors(1006, NULL);
	while ((*s)[i] && ft_isdigit((*s)[i]))
		i++;
	while ((*s)[i] && ft_isspace((*s)[i]))
		i++;
	if (ft_isdigit((*s)[i]))
		ascene->res.y = ft_atoi(*s + i);
	else
		ft_errors(1006, NULL);
}

void	ft_al_rd(char **s, t_scene *ascene)
{
	int	i;

	if (ascene->al.intensity || ascene->al.color.r
			|| ascene->al.color.g || ascene->al.color.b)
		ft_errors(1004, "");
	i = 1;
	while (ft_isspace((*s)[i]))
		i++;
	if (ft_isdigit((*s)[i]))
		ft_read_double(*s + i, &(ascene->al.intensity));
	else
		ft_errors(1007, NULL);
	while (ft_isdigit((*s)[i]) || (*s)[i] == '.')
		i++;
	ft_read_color(*s + i, &(ascene->al.color));
}

void	ft_cam_rd(char **s, t_scene *ascene)
{
	int			i;
	t_camera	*new_cam;

	if (!(new_cam = malloc(sizeof(t_camera))))
		ft_errors(1011, "");
	i = 1;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(1012, "");
	i += ft_read_td((*s) + i, &new_cam->p);
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(1012, "");
	i += ft_read_td(*s + i, &new_cam->v);
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(1012, "");
	new_cam->fov = ft_atod(*s + i);
	new_cam->next = NULL;
	new_cam->v = ft_unit_v(new_cam->v);
	new_cam->l.x = -new_cam->v.y;
	new_cam->l.y = new_cam->v.x;
	new_cam->l.z = 0;
	if (!new_cam->l.x && !new_cam->l.y)
		new_cam->l.y = -1;
	new_cam->m = ft_cross(new_cam->v, new_cam->l);
	ft_add_cam(ascene, new_cam);
	ascene->cam_nbr++;
}

void	ft_light_rd(char **s, t_scene *ascene)
{
	int		i;
	t_light	*new_light;

	if (!(new_light = malloc(sizeof(t_light))))
		ft_errors(1011, "");
	i = 1;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(1013, "");
	i += ft_read_td(*s + i, &new_light->p);
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(1013, "");
	new_light->brightness = ft_atod(*s + i);
	while (ft_isdigit((*s)[i]) || (*s)[i] == '.')
		i++;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(1013, "");
	ft_read_color(*s + i, &new_light->color);
	new_light->next = NULL;
	ft_add_light(ascene, new_light);
}
