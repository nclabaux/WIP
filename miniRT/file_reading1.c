/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reading1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:12:54 by nclabaux          #+#    #+#             */
/*   Updated: 2020/05/04 17:04:39 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
