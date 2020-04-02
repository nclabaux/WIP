/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:48:31 by nclabaux          #+#    #+#             */
/*   Updated: 2020/02/06 22:22:24 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_string(va_list *aap, t_flag *afl, int *result)
{
	char	*s;
	int		len;

	s = va_arg(*aap, char *);
	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if ((*afl).modif)
		len = ft_min(len, (*afl).prec);
	if ((*afl).position == 1)
		ft_padding_str(result, afl, len);
	ft_putstr_nb_cpt(s, len, result);
	if ((*afl).position == -1)
		ft_padding_str(result, afl, len);
}

void	ft_padding_str(int *result, t_flag *afl, int len)
{
	int	j;

	j = 0;
	while (j < (*afl).pad - len)
	{
		ft_putchar_cpt((*afl).filler, result);
		j++;
	}
}

void	ft_putstr_nb_cpt(char *s, int len, int *result)
{
	int	j;

	j = 0;
	while (j < len && s[j])
	{
		ft_putchar_cpt(s[j], result);
		j++;
	}
}
