/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reading1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:12:54 by nclabaux          #+#    #+#             */
/*   Updated: 2020/05/15 17:39:51 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		ft_read_vector(char *s, t_vector *vector)
{
	int 	i;

	i = 0;
	while (ft_isspace(s[i]))
		i++;
	i += ft_read_double(s + i, &vector->x);
	if (s[i] == ',')
		i++;
	else
		ft_errors(1010, "");
	i += ft_read_double(s + i, &vector->y);
	if (s[i] == ',')
		i++;
	else
		ft_errors(1010, "");
	i += ft_read_double(s + i, &vector->z);
	return (i);
}

void	ft_res_rd(char **s, t_scene *ascene)
{
	int	i;

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

	i = 1;
	while (ft_isspace((*s)[i]))
		i++;
	if (ft_isdigit((*s)[i]))
		ascene->al.intensity = (*s)[i] - '0';
	else
		ft_errors(1007, NULL);
	if ((*s)[++i] == '.')
		i++;
	else
		ft_errors(1007, NULL);
	if (ft_isdigit((*s)[i]))
		ascene->al.intensity += ((*s)[i] - '0') / 10;
	else
		ft_errors(1007, NULL);
	i++;
	ft_read_color(*s + i, &(ascene->al.color));
}

void	ft_cam_rd(char **s, t_scene *ascene)
{
	int	i;
	t_camera	*new_cam;

	if (!(new_cam = malloc(sizeof(t_camera))))
		ft_errors(1011, "");
	i = 1;
	ft_printf("a %s\n", *s + i);
	while (ft_isspace((*s)[i]))
		i++;
	ft_printf("b %s\n", *s + i);
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
	{
		ft_printf("c %s\n", *s + i);
		ft_errors(1012, "");
	}
	i += ft_read_point((*s) + i, &new_cam->point);
	ft_printf("d %s\n", *s + i);
	while (ft_isspace((*s)[i]))
		i++;
	ft_printf("e %s\n", *s + i);
	if (!(ft_isdigit((*s)[i])))
	{
		ft_printf("f %s\n", *s + i);
		ft_errors(1012, "");
	}
	i += ft_read_vector(*s + i, &new_cam->orientation);
	ft_printf("g %s\n", *s + i);
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
	{
		ft_printf("h %s\n", *s + i);
		ft_errors(1012, "");
	}
	ft_printf("i %s\n", *s + i);
	new_cam->fov=ft_atod(*s + i);
	new_cam->next = NULL;
	ft_add_cam(ascene, new_cam);
}

void	ft_light_rd(char **s, t_scene *ascene)
{
	int	i;
	t_light	*new_light;

	if (!(new_light = malloc(sizeof(t_light))))
		ft_errors(1011, "");
	i = 1;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(1013, "");
	i += ft_read_point(*s + i, &new_light->point);
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
