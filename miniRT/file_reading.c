/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 19:04:29 by nclabaux          #+#    #+#             */
/*   Updated: 2020/05/07 15:39:07 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	ft_read_file(char *file, t_scene *ascene)
{
	char	buffer[2147483647];
	int	fd;
	int	end;
	char	**line;

	end = 0;
	if(!(fd = open(file, O_RDONLY)))
		ft_errors(1001, file);
	while (!end)
	{
		status = get_next_line(fd, lines);
		if (!status)
			end = 1;
		if (status == -1)
			ft_errors(1002, NULL);	
		ft_translate_line(line, ascene);
	}
}

void	ft_translate_line(char **line, t_scene *ascene)
{
	int	r;
	int	a;

	r = 0;
	a = 0;
	if (*line[0] == 'R')
	{
		if (r)
			ft_errors(1003, NULL);
		r++;
		ft_res_rd(line, ascene);
	}
	else if (*line[0] == 'A')
	{
		if (a)
			ft_errors(1004, NULL);
		a++;
		ft_al_rd(line, ascene);
	}
	else if (*line[0] == 'c')
		ft_cam_rd(line, ascene);
	else if (*line[0] == 'l')
		ft_light_rd(line, ascene);
	else if (*line[0] == 'p' && *line[1] == 'l')
		ft_pl_rd(line, ascene);
	else if (*line[0] == 's' && *line[1] == 'p')
		ft__rd(line, ascene);
	else if (*line[0] == 's' && *line[1] == 'q')
		ft__rd(line, ascene);
	else if (*line[0] == 'c' && *line[1] == 'y')
		ft__rd(line, ascene);
	else if (*line[0] == 't' && *line[1] == 'r')
		ft__rd(line, ascene);
	else
		ft_errors(1005, *line);
}

int		ft_read_color(char *s, t_color *color_storage)
{
	int	i;

	while (ft_isspace(s[i]))
		i++;
	if (ft_isdigit(s[i]))
		color_storage->r = ft_atoi(*(s + i));
	else
		ft_errors(1008, NULL);
	if (s[++i] == ',')
		i++;
	else
		ft_errors(1008, NULL);
	if (ft_isdigit(s[i]))
		color_storage->g = ft_atoi(*(s + i));
	else
		ft_errors(1008, NULL);
	if (s[++i] == ',')
		i++;
	else
		ft_errors(1008, NULL);
	if (ft_isdigit(s[i]))
		color_storage->b = ft_atoi(*(s + i));
	else
		ft_errors(1008, NULL);
	return (i);
}

int		ft_read_double(char *s, double *coor)
{
	int	i;

	if (ft_isdigit(s[i]))
		*coor = ft_atod(*(s + i));
	else
		ft_errors(1009, NULL);
	while (ft_isdigit(s[i]))
		i++;
	if (s[++i] == '.')
		i++;
	else
		ft_errors(1009, NULL);
	while (ft_isdigit(s[i]))
		i++;
	return (i);
}

int	ft_read_point(char *s, t_point3 *point)
{
	int	i;

	while (ft_isspace(s[i]))
		i++;
	i += ft_read_double(s + i, &point->x);
	if (s[++i] == ',')
		i++;
	else
		ft_errors(1009, NULL);
	i += ft_read_double(s + i, &point->y);
	if (s[++i] == ',')
		i++;
	else
		ft_errors(1009, NULL);
	i += ft_read_double(s + i, &point->z);
	return (i);
}
