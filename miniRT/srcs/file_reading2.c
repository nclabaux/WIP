/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reading2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 16:40:09 by nclabaux          #+#    #+#             */
/*   Updated: 2020/08/02 17:38:04 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

void	ft_sp_rd(char **s, t_scene *as)
{
	int			i;
	t_obj_link	*new_ol;

	if (!(new_ol = malloc(sizeof(t_obj_link))))
		ft_errors(as, 1011, "");
	if (!(new_ol->object = malloc(sizeof(t_object))))
		ft_errors(as, 1011, "");
	new_ol->type = 1;
	i = 2;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(as, 1015, "");
	i += ft_read_td(as, *s + i, &(new_ol->object->sp.p));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(as, 1015, "");
	new_ol->object->sp.diam = ft_atod(*s + i);
	while (ft_isdigit((*s)[i]) || (*s)[i] == '.')
		i++;
	while (ft_isspace((*s)[i]))
		i++;
	ft_sp_rd2(s, as, new_ol, i);
}

void	ft_sp_rd2(char **s, t_scene *as, t_obj_link *new_ol, int i)
{
	if (!(ft_isdigit((*s)[i])))
		ft_errors(as, 1015, "");
	ft_read_color(as, *s + i, &(new_ol->object->sp.color));
	ft_add_object(as, new_ol);
}

void	ft_sq_rd(char **s, t_scene *as)
{
	int			i;
	t_square	sq;

	i = 2;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(as, 1016, "");
	i += ft_read_td(as, *s + i, &(sq.p));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(as, 1016, "");
	i += ft_read_td(as, *s + i, &(sq.v));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(as, 1016, "");
	sq.size = ft_atod(*s + i);
	while (ft_isdigit((*s)[i]) || (*s)[i] == '.')
		i++;
	while (ft_isspace((*s)[i]))
		i++;
	ft_sq_rd2(s, as, sq, i);
}

void	ft_sq_rd2(char **s, t_scene *as, t_square sq, int i)
{
	if (!(ft_isdigit((*s)[i])))
		ft_errors(as, 1016, "");
	ft_read_color(as, *s + i, &(sq.color));
	sq.v = ft_unit_v(sq.v);
	ft_set_sq_data(&sq, as);
}

void	ft_tr_rd(char **s, t_scene *as)
{
	int			i;
	t_triangle	tr;

	i = 2;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(as, 1018, "");
	i += ft_read_td(as, *s + i, &(tr.p1));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(as, 1018, "");
	i += ft_read_td(as, *s + i, &(tr.p2));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(as, 1018, "");
	i += ft_read_td(as, *s + i, &(tr.p3));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(as, 1018, "");
	ft_read_color(as, *s + i, &(tr.color));
	ft_alloc_tr(tr, as);
}
