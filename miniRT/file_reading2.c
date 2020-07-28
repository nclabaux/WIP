/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reading2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 16:40:09 by nclabaux          #+#    #+#             */
/*   Updated: 2020/07/28 14:52:14 by nclabaux         ###   ########.fr       */
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

void	ft_sp_rd(char **s, t_scene *ascene)
{
	int			i;
	t_obj_link	*new_ol;

	if (!(new_ol = malloc(sizeof(t_obj_link))))
		ft_errors(1011, "");
	if (!(new_ol->object = malloc(sizeof(t_object))))
		ft_errors(1011, "");
	new_ol->type = 1;
	i = 2;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(1015, "");
	i += ft_read_td(*s + i, &(new_ol->object->sp.p));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(1015, "");
	new_ol->object->sp.diam = ft_atod(*s + i);
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
	t_square	sq;

	i = 2;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(1016, "");
	i += ft_read_td(*s + i, &(sq.p));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(1016, "");
	i += ft_read_td(*s + i, &(sq.v));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(1016, "");
	sq.size = ft_atod(*s + i);
	while (ft_isdigit((*s)[i]) || (*s)[i] == '.')
		i++;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(1016, "");
	ft_read_color(*s + i, &(sq.color));
	ft_set_sq_data(&sq, ascene);
}

void	ft_cy_rd(char **s, t_scene *ascene)
{
	int			i;
	t_obj_link	*new_ol;

	if (!(new_ol = malloc(sizeof(t_obj_link))))
		ft_errors(1011, "");
	if (!(new_ol->object = malloc(sizeof(t_object))))
		ft_errors(1011, "");
	new_ol->type = 4;
	i = 2;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(1017, "");
	i += ft_read_td(*s + i, &(new_ol->object->cy.p));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(1017, "");
	i += ft_read_td(*s + i, &(new_ol->object->cy.v));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(1017, "");
	new_ol->object->cy.d = ft_atod(*s + i);
	ft_cy_rd2(s, ascene, new_ol, i);
}

void	ft_tr_rd(char **s, t_scene *ascene)
{
	int			i;
	t_triangle	tr;

	i = 2;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(1018, "");
	i += ft_read_td(*s + i, &(tr.p1));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(1018, "");
	i += ft_read_td(*s + i, &(tr.p2));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(1018, "");
	i += ft_read_td(*s + i, &(tr.p3));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(1018, "");
	ft_read_color(*s + i, &(tr.color));
	ft_alloc_tr(tr, ascene);
}
