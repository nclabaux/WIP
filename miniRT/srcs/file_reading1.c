/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reading1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:12:54 by nclabaux          #+#    #+#             */
/*   Updated: 2020/08/02 17:37:57 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

void	ft_res_rd(char **s, t_scene *as)
{
	int	i;

	if (as->res.x || as->res.y)
		ft_errors(as, 1003, "");
	i = 1;
	while ((*s)[i] && ft_isspace((*s)[i]))
		i++;
	if (ft_isdigit((*s)[i]))
		as->res.x = ft_atoi(*s + i);
	else
		ft_errors(as, 1006, NULL);
	while ((*s)[i] && ft_isdigit((*s)[i]))
		i++;
	while ((*s)[i] && ft_isspace((*s)[i]))
		i++;
	if (ft_isdigit((*s)[i]))
		as->res.y = ft_atoi(*s + i);
	else
		ft_errors(as, 1006, NULL);
}

void	ft_al_rd(char **s, t_scene *as)
{
	int	i;

	if (as->al.intensity || as->al.color.r
			|| as->al.color.g || as->al.color.b)
		ft_errors(as, 1004, "");
	i = 1;
	while (ft_isspace((*s)[i]))
		i++;
	if (ft_isdigit((*s)[i]))
		ft_read_double(as, *s + i, &(as->al.intensity));
	else
		ft_errors(as, 1007, NULL);
	while (ft_isdigit((*s)[i]) || (*s)[i] == '.')
		i++;
	ft_read_color(as, *s + i, &(as->al.color));
}

void	ft_cam_rd(char **s, t_scene *as)
{
	int			i;
	t_camera	*new_cam;

	if (!(new_cam = malloc(sizeof(t_camera))))
		ft_errors(as, 1011, "");
	i = 1;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(as, 1012, "");
	i += ft_read_td(as, (*s) + i, &new_cam->p);
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(as, 1012, "");
	i += ft_read_td(as, *s + i, &new_cam->v);
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(as, 1012, "");
	new_cam->fov = ft_atod(*s + i);
	new_cam->next = NULL;
	ft_set_cam_data(new_cam);
	ft_add_cam(as, new_cam);
	as->cam_nbr++;
}

void	ft_light_rd(char **s, t_scene *as)
{
	int		i;
	t_light	*new_light;

	if (!(new_light = malloc(sizeof(t_light))))
		ft_errors(as, 1011, "");
	i = 1;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(as, 1013, "");
	i += ft_read_td(as, *s + i, &new_light->p);
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(as, 1013, "");
	new_light->brightness = ft_atod(*s + i);
	while (ft_isdigit((*s)[i]) || (*s)[i] == '.')
		i++;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(as, 1013, "");
	ft_read_color(as, *s + i, &new_light->color);
	new_light->next = NULL;
	ft_add_light(as, new_light);
}

void	ft_pl_rd(char **s, t_scene *as)
{
	int			i;
	t_obj_link	*new_ol;

	if (!(new_ol = malloc(sizeof(t_obj_link))))
		ft_errors(as, 1011, "");
	if (!(new_ol->object = malloc(sizeof(t_object))))
		ft_errors(as, 1011, "");
	new_ol->type = 2;
	i = 2;
	while ((*s)[i] && ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(as, 1014, "");
	i += ft_read_td(as, *s + i, &(new_ol->object->pl.p));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(as, 1014, "");
	i += ft_read_td(as, *s + i, &(new_ol->object->pl.v));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(as, 1014, "");
	ft_read_color(as, *s + i, &(new_ol->object->pl.color));
	ft_add_object(as, new_ol);
}
