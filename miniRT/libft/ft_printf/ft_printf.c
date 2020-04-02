/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:29:48 by nclabaux          #+#    #+#             */
/*   Updated: 2020/02/06 21:44:41 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		result;

	result = 0;
	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			i++;
			result++;
		}
		if (str[i] == '%')
		{
			i = ft_flag_rd(&ap, str, i + 1, &result);
		}
	}
	va_end(ap);
	return (result);
}

int		ft_flag_rd(va_list *aap, const char *str, int i, int *result)
{
	t_flag	flags;

	ft_flag_init(&flags);
	while (str[i] && (str[i] == '-' || str[i] == '+' || str[i] == '0'))
		i = ft_begin_rd(i, &flags, str);
	if (ft_isdigit(str[i]))
	{
		flags.pad = ft_atoi(str + i);
		i += ft_digit_nbr(flags.pad);
	}
	else if (str[i] == '*')
	{
		flags.pad = va_arg(*aap, int);
		if (flags.pad < 0)
		{
			flags.pad *= -1;
			flags.position = -1;
			flags.filler = ' ';
		}
		i++;
	}
	if (str[i] == '.')
		i = ft_prec_rd(aap, &flags, i + 1, str);
	return (i + ft_arg_rd(aap, (char *)str + i, &flags, result));
}

int		ft_arg_rd(va_list *aap, char *str_i, t_flag *afl, int *result)
{
	if (*str_i == 'c')
		ft_character(aap, afl, result);
	else if (*str_i == 's')
		ft_string(aap, afl, result);
	else if (*str_i == 'd' || *str_i == 'i')
		ft_integer(aap, afl, result);
	else if (*str_i == 'u')
		ft_unsigned_int(aap, afl, result);
	else if (*str_i == 'p')
		ft_pointeur(aap, afl, result);
	else if (*str_i == 'x')
		ft_hex(aap, afl, result, "0123456789abcdef");
	else if (*str_i == 'X')
		ft_hex(aap, afl, result, "0123456789ABCDEF");
	else if (*str_i == '%')
		ft_percent(afl, result);
	else
		return (0);
	return (1);
}

void	ft_flag_init(t_flag *afl)
{
	(*afl).pad = 0;
	(*afl).prec = 0;
	(*afl).position = 1;
	(*afl).modif = 0;
	(*afl).filler = ' ';
}

int		ft_prec_rd(va_list *aap, t_flag *afl, int i, const char *str)
{
	(*afl).modif = 1;
	while (str[i] == '0')
		i++;
	if (ft_isdigit(str[i]))
	{
		(*afl).prec = ft_atoi(str + i);
		i += ft_digit_nbr((*afl).prec);
	}
	else if (str[i] == '*')
	{
		(*afl).prec = va_arg(*aap, int);
		i++;
	}
	if ((*afl).prec < 0)
		(*afl).modif = 0;
	else if (str[i] == '%')
		return (i);
	else
		(*afl).filler = ' ';
	return (i);
}
