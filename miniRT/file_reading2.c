/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reading2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 16:40:09 by nclabaux          #+#    #+#             */
/*   Updated: 2020/06/22 15:58:21 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	ft_pl_rd(char **s, t_scene *ascene)
{
	int			i;
	t_obj_link	*new_ol;

	if (!(new_ol = malloc(sizeof(t_obj_link))))
		ft_errors(1011, "");
	if (!(new_ol->object = malloc(sizeof(t_object))))
		ft_errors(1011, "");
	new_ol->next = NULL;
	new_ol->type = 2;
	i = 2;
	while ((*s)[i] && ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(1014, "");
	i += ft_read_point(*s + i, &(new_ol->object->pl.p));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(1014, "");
	i += ft_read_vector(*s + i, &(new_ol->object->pl.v));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(1014, "");
	ft_read_color(*s + i, &(new_ol->object->pl.color));
	ft_add_object(ascene, new_ol);
}

void	ft_sp_rd(char **s, t_scene *ascene)
{
	int			i;
	t_obj_link	*new_ol;

	if (!(new_ol = malloc(sizeof(t_obj_link))))
		ft_errors(1011, "");
	if (!(new_ol->object = malloc(sizeof(t_object))))
		ft_errors(1011, "");
	new_ol->next = NULL;
	new_ol->type = 1;
	i = 2;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(1015, "");
	i += ft_read_point(*s + i, &(new_ol->object->sp.point));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(1015, "");
	new_ol->object->sp.diameter = ft_atod(*s + i);
	while (ft_isdigit((*s)[i]) || (*s)[i] == '.')
		i++;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(1015, "");
	ft_read_color(*s + i, &(new_ol->object->sp.color));
	ft_add_object(ascene, new_ol);
}

void	ft_sq_rd(char **s, t_scene *ascene)
{
	int			i;
	t_obj_link	*new_ol;

	if (!(new_ol = malloc(sizeof(t_obj_link))))
		ft_errors(1011, "");
	if (!(new_ol->object = malloc(sizeof(t_object))))
		ft_errors(1011, "");
	new_ol->next = NULL;
	new_ol->type = 3;
	i = 2;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(1016, "");
	i += ft_read_point(*s + i, &(new_ol->object->sq.p));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(1016, "");
	i += ft_read_vector(*s + i, &(new_ol->object->sq.v));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(1016, "");
	new_ol->object->sq.size = ft_atod(*s + i);
	while (ft_isdigit((*s)[i]) || (*s)[i] == '.')
		i++;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(1016, "");
	ft_read_color(*s + i, &(new_ol->object->sq.color));
	ft_set_sq_data(&(new_ol->object->sq));
	ft_set_tr_data(&(new_ol->object->sq.a));
	ft_set_tr_data(&(new_ol->object->sq.b));
	ft_add_object(ascene, new_ol);
}

void	ft_cy_rd(char **s, t_scene *ascene)
{
	int			i;
	t_obj_link	*new_ol;

	if (!(new_ol = malloc(sizeof(t_obj_link))))
		ft_errors(1011, "");
	if (!(new_ol->object = malloc(sizeof(t_object))))
		ft_errors(1011, "");
	new_ol->next = NULL;
	new_ol->type = 4;
	i = 2;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(1017, "");
	i += ft_read_point(*s + i, &(new_ol->object->cy.p));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(1017, "");
	i += ft_read_vector(*s + i, &(new_ol->object->cy.v));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(1017, "");
	new_ol->object->cy.d = ft_atod(*s + i);
	while (ft_isdigit((*s)[i]) || (*s)[i] == '.')
		i++;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(1017, "");
	new_ol->object->cy.height = ft_atod(*s + i);
	while (ft_isdigit((*s)[i]) || (*s)[i] == '.')
		i++;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(1017, "");
	ft_read_color(*s + i, &(new_ol->object->cy.color));
	ft_add_object(ascene, new_ol);
}

void	ft_tr_rd(char **s, t_scene *ascene)
{
	int			i;
	t_obj_link	*new_ol;

	if (!(new_ol = malloc(sizeof(t_obj_link))))
		ft_errors(1011, "");
	if (!(new_ol->object = malloc(sizeof(t_object))))
		ft_errors(1011, "");
	new_ol->next = NULL;
	new_ol->type = 5;
	i = 2;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(1018, "");
	i += ft_read_point(*s + i, &(new_ol->object->tr.p1));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(1018, "");
	i += ft_read_point(*s + i, &(new_ol->object->tr.p2));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(1018, "");
	i += ft_read_point(*s + i, &(new_ol->object->tr.p3));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(1018, "");
	ft_read_color(*s + i, &(new_ol->object->tr.color));
	ft_set_tr_data(&(new_ol->object->tr));
	ft_add_object(ascene, new_ol);
}
