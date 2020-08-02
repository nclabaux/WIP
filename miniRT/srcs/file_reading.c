/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 19:04:29 by nclabaux          #+#    #+#             */
/*   Updated: 2020/08/02 17:38:18 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

void	ft_read_file(char *file, t_scene *as)
{
	int		fd;
	int		end;
	char	*line;
	int		status;

	end = 0;
	line = NULL;
	if (!(fd = open(file, O_RDONLY)))
		ft_errors(as, 1001, file);
	while (!end)
	{
		status = get_next_line(fd, &line);
		if (!status)
			end = 1;
		if (status == -1)
		{
			close(fd);
			free(line);
			ft_errors(as, 1002, NULL);
		}
		ft_translate_line(&line, as);
	}
	close(fd);
	free(line);
}

void	ft_translate_line(char **line, t_scene *as)
{
	if ((*line)[0] == 'R')
		ft_res_rd(line, as);
	else if ((*line)[0] == 'A')
		ft_al_rd(line, as);
	else if ((*line)[0] == 'c' && ft_isspace((*line)[1]))
		ft_cam_rd(line, as);
	else if ((*line)[0] == 'l')
		ft_light_rd(line, as);
	else if ((*line)[0] == 'p' && (*line)[1] == 'l')
		ft_pl_rd(line, as);
	else if ((*line)[0] == 's' && (*line)[1] == 'p')
		ft_sp_rd(line, as);
	else if ((*line)[0] == 's' && (*line)[1] == 'q')
		ft_sq_rd(line, as);
	else if ((*line)[0] == 'c' && (*line)[1] == 'y')
		ft_cy_rd(line, as);
	else if ((*line)[0] == 't' && (*line)[1] == 'r')
		ft_tr_rd(line, as);
	else if ((*line)[0] != 0)
	{
		ft_errors(as, 1005, *line);
		free(line);
	}
}

int		ft_read_color(t_scene *as, char *s, t_color *color_storage)
{
	int	i;

	i = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	if (!(ft_isdigit(s[i])))
		ft_errors(as, 1008, NULL);
	color_storage->r = ft_atoi(s + i);
	while (ft_isdigit(s[i]))
		i++;
	if (!(s[i++] == ','))
		ft_errors(as, 1008, NULL);
	if (!(ft_isdigit(s[i])))
		ft_errors(as, 1008, NULL);
	color_storage->g = ft_atoi(s + i);
	while (ft_isdigit(s[i]))
		i++;
	if (!(s[i++] == ','))
		ft_errors(as, 1008, NULL);
	if (!(ft_isdigit(s[i])))
		ft_errors(as, 1008, NULL);
	color_storage->b = ft_atoi(s + i);
	return (i);
}

int		ft_read_double(t_scene *as, char *s, double *coor)
{
	int	i;
	int	neg;

	i = 0;
	neg = 1;
	if (s[i] == '-')
	{
		neg = -1;
		i++;
	}
	if (ft_isdigit(s[i]))
		*coor = neg * ft_atod(s + i);
	else
		ft_errors(as, 1009, NULL);
	while (ft_isdigit(s[i]) || s[i] == '.')
		i++;
	return (i);
}

int		ft_read_td(t_scene *as, char *s, t_td *atd)
{
	int	i;

	i = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	i += ft_read_double(as, s + i, &atd->x);
	if (s[i] == ',')
		i++;
	else
		ft_errors(as, 1009, NULL);
	i += ft_read_double(as, s + i, &atd->y);
	if (s[i] == ',')
		i++;
	else
		ft_errors(as, 1009, NULL);
	i += ft_read_double(as, s + i, &atd->z);
	return (i);
}
