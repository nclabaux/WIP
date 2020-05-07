/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reading1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:12:54 by nclabaux          #+#    #+#             */
/*   Updated: 2020/05/07 16:30:11 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		ft_read_vector(char *s, t_vector3 *vector)
{
	int 	i;

	while (ft_isspace(s[i]))
		i++;
	i += ft_read_double(s + i, &vector->x);
	if(s[++i] == ',')
		i++;
	else
		ERROR;
	i += ft_read_double(s + i, &vector->y);
	if (s[++i] == ',')
		i++;
	else
		ERROR;
	i += ft_read_double(s + i, &vector->z);
	return (i);
}

void	ft_res_rd(char **line, t_scene *ascene)
{
	int	i;

	i = 1;
	while (ft_isspace(*line[i]))
		i++;
	if (ft_isdigit(line[i]))
		ascene->res.x = ft_atoi(*(line + i));
	else
		ft_errors(1006, NULL);
	while (ft_isspace(*line[i]))
		i++;
	if (ft_isdigit(*line[i]))
		ascene->res.y = ft_atoi(*(line + i));
	else
		ft_errors(1006, NULL);
}	

void	ft_al_rd(char **line, t_scene *ascene)
{
	int	i;
	
	i = 1;
	while (ft_isspace(*line[i]))
		i++;
	if (ft_isdigit(*line[i]))
		ascene->al.intensity = *line[i] - '0';
	else
		ft_errors(1007, NULL);
	if (*line[++i] == '.')
		i++;
	else
		ERROR;
	if (ft_isdigit(*line[i]))
		ascene->al.intensity += (*line[i] - '0') / 10;
	else
		ft_errors(1007, NULL);
	i++;
	ft_read_color(*line + i, &(ascene->al.color));
}

void	ft_cam_rd(char **line, t_scene *ascene)
{
	int	i;
	t_camera	*new_cam;

	if (!(new_cam = malloc(sizeof(t_camera))))
		ERROR;
	i = 1;
	while (ft_isspace(*s + i))
		i++;
	if (!(ft_isdigit(*s + i)));
		ERROR;
	i += ft_read_point(*s + i, &new_cam->point);
	while (ft_isspace(*s + i))
		i++;
	if (!(ft_isdigit(*s + i)));
		ERROR;
	i += ft_read_vector(*s + i, &new_cam->vector)
	while (ft_isspace(*s + i))
		i++;
	if (!(ft_isdigit(*s + i)));
		ERROR;
	ft_read_color(*s + i, &new_cam->color);
	new_cam->next = NULL;
	ft_add_cam(ascene, new_cam);
}

void	ft_light_rd(char **s, t_scene *ascene)
{
	int	i;
	t_light	*new_light;

	if (!(new_light = malloc(sizeof(t_light))))
		ERROR;
	i = 1;
	while (ft_isspace(*s + i))
		i++;
	if (!(ft_isdigit(*s + i)))
		ERROR;
	i += ft_read_point(*s + i, &new_light->point);
	while (ft_isspace(*s + i))
		i++;
	if (!(ft_isdigit(*s + i)))
		ERROR;
	new_light->brightness = ft_atod(*s + i);
	while (ft_isdigit(*s[i] || *s[i] == '.'))
		i++;
	if(!(ft_isdigit(*s[i])))
		ERROR;
	ft_read_color(*s + i, &new_light->color);
	new_light->next = NULL;
	ft_add_light(ascene, new_light);
}
