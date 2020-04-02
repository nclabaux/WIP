/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_begin_rd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 22:38:36 by nclabaux          #+#    #+#             */
/*   Updated: 2020/01/30 22:38:39 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_begin_rd(int i, t_flag *afl, const char *str)
{
	if (str[i] == '-')
	{
		(*afl).position = -1;
		(*afl).filler = ' ';
	}
	if (str[i] == '0' && (*afl).position == 1)
		(*afl).filler = '0';
	i++;
	return (i);
}
