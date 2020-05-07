/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reading2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 16:40:09 by nclabaux          #+#    #+#             */
/*   Updated: 2020/05/07 17:35:17 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	ft_pl_rd(char **s, t_scene *ascene)
{
	int	i;
	t_obj_link	*new_ol;

	if(!(new_ol->object = malloc(sizeof(t_object))))
		ERROR;
	new_ol->next = NULL;
	i = 2;
	while (ft_isspace(*s + i))
		i++;
	if (!(ft_isdigit(*s + i)))
		ERROR;
	i += ft_read_point(*s + i, &(new_ol->object.pl.point));
	while (ft_isspace(*s + i))
		i++;
	if (!(ft_isdigit(*s + i)))
		ERROR;
	i += ft_read_vector(*s + i, &(new_ol->object.pl.orientation));
	while (ft_isspace(*s + i))
		i++;
	if (!(ft_isdigit(*s + i)))
		ERROR;
	ft_read_color(*s + i, &(new_ol->object.pl.color));
	ft_add_object(ascene, new_ol);
}

void	ft_sp_rd(char **s, t_scene *ascene)
{
	int	i;
	t_obj_link	*new_ol;

	if(!(new_ol->object = malloc(sizeof(t_object))))
		ERROR;
	new_ol->next = NULL;
	i = 2;
	while (ft_isspace(*s + i))
		i++;
	if (!(ft_isdigit(*s + i)))
		ERROR;
	i += ft_read_point(*s + i, &(new_ol->object.sp.point));
	while (ft_isspace(*s + i))
		i++;
	if (!(ft_isdigit(*s + i)))
		ERROR;
	new_ol->object.sp.diameter = ft_atod(*s + i);
	while (ft_isdigit(*s + i) || *s[i] == '.')
		i++;
	if (!(ft_isdigit(*s + i)))
		ERROR;
	ft_read_color(*s + i, &(new_ol->object.sp.color));
	ft_add_object(ascene, new_ol);
}	

void	ft_sq_rd(char **s, t_scene *ascene)
{
	int	i;
	t_obj_link	*new_ol;

	if(!(new_ol->object = malloc(sizeof(t_object))))
		ERROR;
	new_ol->next = NULL;
	i = 2;
	while (ft_isspace(*s + i))
		i++;
	if (!(ft_isdigit(*s + i)))
		ERROR;
	i += ft_read_point(*s + i, &(new_ol->object.sq.point));
	while (ft_isspace(*s + i))
		i++;
	if (!(ft_isdigit(*s + i)))
		ERROR;
	i += ft_read_vector(*s + i, &(new_ol->object.sq.orientation));
	while (ft_isspace(*s + i))
		i++;
	if (!(ft_isdigit(*s + i)))
		ERROR;
	new_ol->object.sq.size = ft_atod(*s + i);
	while (ft_isdigit(*s + i) || *s[i] == '.')
		i++;
	if (!(ft_isdigit(*s + i)))
		ERROR;
	ft_read_color(*s + i, &(new_ol->object.sq.color));
	ft_add_object(ascene, new_ol);
}	

void	ft_cy_rd(char **s, t_scene *ascene)
{
	int	i;
	t_obj_link	*new_ol;

	if(!(new_ol->object = malloc(sizeof(t_object))))
		ERROR;
	new_ol->next = NULL;
	i = 2;
	while (ft_isspace(*s + i))
		i++;
	if (!(ft_isdigit(*s + i)))
		ERROR;
	i += ft_read_point(*s + i, &(new_ol->object.cy.point));
	while (ft_isspace(*s + i))
		i++;
	if (!(ft_isdigit(*s + i)))
		ERROR;
	i += ft_read_vector(*s + i, &(new_ol->object.cy.orientation));
	while (ft_isspace(*s + i))
		i++;
	if (!(ft_isdigit(*s + i)))
		ERROR;
	new_ol->object.sq.diameter = ft_atod(*s + i);
	while (ft_isdigit(*s + i) || *s[i] == '.')
		i++;
	if (!(ft_isdigit(*s + i)))
		ERROR;
	new_ol->object.sq.height = ft_atod(*s + i);
	while (ft_isdigit(*s + i) || *s[i] == '.')
		i++;
	if (!(ft_isdigit(*s + i)))
		ERROR;
	ft_read_color(*s + i, &(new_ol->object.cy.color));
	ft_add_object(ascene, new_ol);
}	

void	ft_tr_rd(char **s, t_scene *ascene)
{
	int	i;
	t_obj_link	*new_ol;

	if(!(new_ol->object = malloc(sizeof(t_object))))
		ERROR;
	new_ol->next = NULL;
	i = 2;
	while (ft_isspace(*s + i))
		i++;
	if (!(ft_isdigit(*s + i)))
		ERROR;
	i += ft_read_point(*s + i, &(new_ol->object.tr.p1));
	while (ft_isspace(*s + i))
		i++;
	if (!(ft_isdigit(*s + i)))
		ERROR;
	i += ft_read_point(*s + i, &(new_ol->object.tr.p2));
	while (ft_isspace(*s + i))
		i++;
	if (!(ft_isdigit(*s + i)))
		ERROR;
	i += ft_read_point(*s + i, &(new_ol->object.tr.p3));
	while (ft_isspace(*s + i))
		i++;
	if (!(ft_isdigit(*s + i)))
		ERROR;
	ft_read_color(*s + i, &(new_ol->object.cy.color));
	ft_add_object(ascene, new_ol);
}
