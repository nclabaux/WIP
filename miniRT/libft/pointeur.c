/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointeur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:40:02 by nclabaux          #+#    #+#             */
/*   Updated: 2020/02/11 00:57:41 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointeur(va_list *aap, t_flag *afl, int *result)
{
	long long	x;

	x = va_arg(*aap, long long);
	if ((*afl).position == 1)
		ft_padding_pnt(result, afl, x);
	ft_putstr_fd("0x", 1);
	(*result) += 2;
	ft_precision_pnt(result, afl, x);
	if (!(*afl).prec && (*afl).modif && (x == 0 || (void*)x == NULL))
	{
		if ((*afl).pad && x)
			ft_putchar_cpt((*afl).filler, result);
	}
	else
	{
		ft_putstr_fd(ft_nbr_base(x, "0123456789abcdef"), 1);
		(*result) += ft_dgt_nbr_hex(x);
	}
	if ((*afl).position == -1)
		ft_padding_pnt(result, afl, x);
}

void	ft_padding_pnt(int *result, t_flag *afl, long long x)
{
	int	j;
	int	zero;
	int	size;

	j = 0;
	zero = 0;
	if (!x && (*afl).modif)
		zero = 1;
	size = ft_dgt_nbr_hex(x) - zero;
	while (j < (*afl).pad - ft_max(size, (*afl).prec) - 2)
	{
		ft_putchar_cpt((*afl).filler, result);
		j++;
	}
}

void	ft_precision_pnt(int *result, t_flag *afl, long long x)
{
	int j;

	j = 0;
	while (j < (*afl).prec - ft_dgt_nbr_hex(x))
	{
		ft_putchar_cpt('0', result);
		j++;
	}
}
