/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:56:57 by nclabaux          #+#    #+#             */
/*   Updated: 2020/02/18 00:36:14 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_minint(t_flag *afl, int *result)
{
	if ((*afl).position == 1 && (*afl).filler == ' ')
		ft_padding_int(result, afl, -2147483647, 1);
	ft_putchar_cpt('-', result);
	if ((*afl).position == 1 && (*afl).filler == '0')
		ft_padding_int(result, afl, -2147483647, 1);
	ft_precision_int(result, afl, -2147483647);
	ft_putstr_fd("2147483648", 1);
	(*result) += 10;
	if ((*afl).position == -1)
		ft_padding_int(result, afl, -2147483647, 1);
}

void	ft_integer(va_list *aap, t_flag *afl, int *result)
{
	long	x;
	int		neg;

	x = va_arg(*aap, int);
	if (x == -2147483648)
		return (ft_minint(afl, result));
	neg = 0;
	if (x < 0)
	{
		x = -x;
		neg = 1;
	}
	if ((*afl).position == 1 && (*afl).filler == ' ')
		ft_padding_int(result, afl, x, neg);
	if (neg && (x != 2147483648))
		ft_putchar_cpt('-', result);
	if (x > 2147483647)
		(*result)++;
	if ((*afl).position == 1 && (*afl).filler == '0')
		ft_padding_int(result, afl, x, neg);
	ft_precision_int(result, afl, x);
	ft_int_wr(afl, result, x);
	if ((*afl).position == -1)
		ft_padding_int(result, afl, x, neg);
}

void	ft_padding_int(int *result, t_flag *afl, int x, int n)
{
	int	j;

	j = 0;
	while (j < (*afl).pad - n - ft_max((*afl).prec, ft_digit_nbr(x)))
	{
		ft_putchar_cpt((*afl).filler, result);
		j++;
	}
}

void	ft_precision_int(int *result, t_flag *afl, int x)
{
	int j;

	j = 0;
	while (j < (*afl).prec - ft_digit_nbr(x))
	{
		ft_putchar_cpt('0', result);
		j++;
	}
}

void	ft_int_wr(t_flag *afl, int *result, long x)
{
	if (!(*afl).prec && (*afl).modif && x == 0)
	{
		if ((*afl).pad)
			ft_putchar_cpt((*afl).filler, result);
	}
	else
	{
		ft_putnbr_fd(x, 1);
		(*result) += ft_digit_nbr(x);
	}
}
