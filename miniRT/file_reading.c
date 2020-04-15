/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 19:04:29 by nclabaux          #+#    #+#             */
/*   Updated: 2020/04/15 16:20:48 by nclabaux         ###   ########.fr       */
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
	fd = open(file, O_RDONLY);
	while (!end)
	{
		status = get_next_line(fd, lines);
		if (!status)
			end = 1;
		if (status == -1)
	
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
		{
			errno = 22;
			perror("Error 22: Multiple resolution setting");
			exit(0);
		}
		r++;
		ft_res_rd(line, ascene);
	}
	else if (*line[0] == 'A')
	{
		if (r)
		{
			errno = 22;
			perror("Error 22: Multiple ambient light setting");
			exit(0);
		}
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
	{
		errno = 22;
		perror("Error 22: %s", *line);
	}
}

void	ft_res_rd(char **line, t_scene *ascene)
{
	int	i;

	i = 1;
	while (ft_isspace(line[i]))
		i++;
	if (ft_isdigit(line[i]))
		ascene->res.x = ft_atoi(*(line + i));
	else
	{
		errno = 22;
	       	perror("Error 22: Non-compliant resolution declaration");
	}
	while (ft_isspace(line[i]))
		i++;
	if (ft_isdigit(line[i]))
		ascene->res.y = ft_atoi(*(line + i));
	else
	{
		errno = 22;
	       	perror("Error 22: Non-compliant resolution declaration");
	}
}	

void	ft_al_rd(char **line, t_scene *ascene)
{
}	

