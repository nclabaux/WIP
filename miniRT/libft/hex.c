/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 21:32:08 by nclabaux          #+#    #+#             */
/*   Updated: 2020/02/06 22:21:58 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex(va_list *aap, t_flag *afl, int *result, char *base)
{
	long long	x;

	x = (long long)va_arg(*aap, unsigned int);
	if ((*afl).position == 1)
		ft_padding_hex(result, afl, x);
	ft_precision_hex(result, afl, x);
	if (!(*afl).prec && (*afl).modif && x == 0)
	{
		if ((*afl).pad)
			ft_putchar_cpt((*afl).filler, result);
	}
	else
	{
		ft_putstr_fd(ft_nbr_base(x, base), 1);
		(*result) += ft_dgt_nbr_hex(x);
	}
	if ((*afl).position == -1)
		ft_padding_hex(result, afl, x);
}

void	ft_padding_hex(int *result, t_flag *afl, long long x)
{
	int	j;

	j = 0;
	while (j < (*afl).pad - ft_max((*afl).prec, ft_dgt_nbr_hex(x)))
	{
		ft_putchar_cpt((*afl).filler, result);
		j++;
	}
}

void	ft_precision_hex(int *result, t_flag *afl, long long x)
{
	int	j;

	j = 0;
	while (j < (*afl).prec - ft_dgt_nbr_hex(x))
	{
		ft_putchar_cpt('0', result);
		j++;
	}
}
