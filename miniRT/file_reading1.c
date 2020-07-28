/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reading1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:12:54 by nclabaux          #+#    #+#             */
/*   Updated: 2020/07/28 15:17:53 by nclabaux         ###   ########.fr       */
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
	ft_set_cam_data(new_cam);
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

void	ft_pl_rd(char **s, t_scene *ascene)
{
	int			i;
	t_obj_link	*new_ol;

	if (!(new_ol = malloc(sizeof(t_obj_link))))
		ft_errors(1011, "");
	if (!(new_ol->object = malloc(sizeof(t_object))))
		ft_errors(1011, "");
	new_ol->type = 2;
	i = 2;
	while ((*s)[i] && ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(1014, "");
	i += ft_read_td(*s + i, &(new_ol->object->pl.p));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(1014, "");
	i += ft_read_td(*s + i, &(new_ol->object->pl.v));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(1014, "");
	ft_read_color(*s + i, &(new_ol->object->pl.color));
	ft_add_object(ascene, new_ol);
}
