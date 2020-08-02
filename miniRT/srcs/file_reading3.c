/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reading3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:16:50 by nclabaux          #+#    #+#             */
/*   Updated: 2020/08/02 17:38:11 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

void	ft_cy_rd(char **s, t_scene *as)
{
	int			i;
	t_obj_link	*new_ol;

	if (!(new_ol = malloc(sizeof(t_obj_link))))
		ft_errors(as, 1011, "");
	if (!(new_ol->object = malloc(sizeof(t_object))))
		ft_errors(as, 1011, "");
	new_ol->type = 4;
	i = 2;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(as, 1017, "");
	i += ft_read_td(as, *s + i, &(new_ol->object->cy.p));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(as, 1017, "");
	i += ft_read_td(as, *s + i, &(new_ol->object->cy.v));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(as, 1017, "");
	new_ol->object->cy.d = ft_atod(*s + i);
	ft_cy_rd2(s, as, new_ol, i);
}

void	ft_cy_rd2(char **s, t_scene *as, t_obj_link *new_ol, int i)
{
	while (ft_isdigit((*s)[i]) || (*s)[i] == '.')
		i++;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(as, 1017, "");
	new_ol->object->cy.h = ft_atod(*s + i);
	while (ft_isdigit((*s)[i]) || (*s)[i] == '.')
		i++;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(as, 1017, "");
	ft_read_color(as, *s + i, &(new_ol->object->cy.color));
	new_ol->object->cy.v = ft_unit_v(new_ol->object->cy.v);
	ft_add_object(as, new_ol);
}
