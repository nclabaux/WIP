/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:48:01 by nclabaux          #+#    #+#             */
/*   Updated: 2020/02/06 21:28:32 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_percent(t_flag *afl, int *result)
{
	if ((*afl).position == 1)
		ft_padding_pct(result, afl);
	ft_putchar_cpt('%', result);
	if ((*afl).position == -1)
		ft_padding_pct(result, afl);
	ft_flag_init(afl);
}

void	ft_padding_pct(int *result, t_flag *afl)
{
	int	j;

	j = 0;
	while (j < (*afl).pad - 1)
	{
		ft_putchar_cpt((*afl).filler, result);
		j++;
	}
}
