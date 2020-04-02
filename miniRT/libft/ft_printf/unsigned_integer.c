/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:47:44 by nclabaux          #+#    #+#             */
/*   Updated: 2020/02/06 22:22:30 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned_int(va_list *aap, t_flag *afl, int *result)
{
	long	x;
	char	*res;
	int		len;

	x = va_arg(*aap, unsigned int);
	res = ft_nbr_base(x, "0123456789");
	len = ft_strlen(res);
	if ((*afl).position == 1)
		ft_padding_ui(result, afl, len);
	ft_precision_ui(result, afl, len);
	if (!(*afl).prec && (*afl).modif && x == 0)
	{
		if ((*afl).pad)
			ft_putchar_cpt((*afl).filler, result);
	}
	else
	{
		ft_putstr_fd(res, 1);
		(*result) += len;
	}
	if ((*afl).position == -1)
		ft_padding_ui(result, afl, len);
}

void	ft_padding_ui(int *result, t_flag *afl, int len)
{
	int	j;

	j = 0;
	while (j < (*afl).pad - ft_max(len, (*afl).prec))
	{
		ft_putchar_cpt((*afl).filler, result);
		j++;
	}
}

void	ft_precision_ui(int *result, t_flag *afl, int len)
{
	int	j;

	j = 0;
	while (j < (*afl).prec - len)
	{
		ft_putchar_cpt('0', result);
		j++;
	}
}
