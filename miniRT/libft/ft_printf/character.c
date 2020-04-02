/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:58:11 by nclabaux          #+#    #+#             */
/*   Updated: 2020/02/06 22:21:32 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_character(va_list *aap, t_flag *afl, int *result)
{
	unsigned char	c;

	c = (unsigned char)va_arg(*aap, int);
	if ((*afl).position == 1)
		ft_padding_char(result, afl);
	ft_putchar_cpt(c, result);
	if ((*afl).position == -1)
		ft_padding_char(result, afl);
}

void	ft_padding_char(int *result, t_flag *afl)
{
	int j;

	j = 0;
	while (j < (*afl).pad - 1)
	{
		ft_putchar_cpt((*afl).filler, result);
		j++;
	}
}
