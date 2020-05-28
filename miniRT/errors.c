/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 18:22:33 by nclabaux          #+#    #+#             */
/*   Updated: 2020/05/28 15:08:20 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	ft_prt_err(char *s, int i, int x)
{
	if (!x)
	{
		ft_printf("Error %d: %s\n", i, s);
		exit(0);
	}
	ft_printf("Error %d: %s\t%s\n", i - 1000, s, strerror(x));
	exit(0);
}

void	ft_errors(int i, char *s)
{
	if (i < 1000 || i > 1100)
		ft_prt_err("Unknown error  ¯\\_(ツ)_/¯", i, 0);
	if (i == 1000)
		ft_prt_err("To few arguments", i, 0);
	if (i == 1001)
		ft_prt_err(s, i, 22);
	if (i == 1002)
		ft_prt_err("Unable to read from file", i, 0);
	if (i == 1003)
		ft_prt_err("Multiple resolution setting", i, 22);
	if (i == 1004)
		ft_prt_err("Multiple ambient light setting", i, 22);
	if (i == 1005)
		ft_prt_err(s, i, 22);
	if (i == 1006)
		ft_prt_err("Bad resolution setting given", i, 22);
	if (i == 1007)
		ft_prt_err("Bad ambient light setting given", i, 22);
	if (i == 1008)
		ft_prt_err("Bad color given", i, 22);
	if (i == 1009)
		ft_prt_err("Bad coordinates given", i, 22);
	else
		ft_errors1(i, s);
}

void	ft_errors1(int i, char *s)
{
	if (i == 1010)
		ft_prt_err("Bad orientation vector given", i, 22);
	if (i == 1011)
		ft_prt_err("Error during memory allocation", i, 12);
	if (i == 1012)
		ft_prt_err("Bad camera setting given", i, 22);
	if (i == 1013)
		ft_prt_err("Bad light setting given", i, 22);
	if (i == 1014)
		ft_prt_err("Bad plane setting given", i, 22);
	if (i == 1015)
		ft_prt_err("Bad sphere setting given", i, 22);
	if (i == 1016)
		ft_prt_err("Bad square setting given", i, 22);
	if (i == 1017)
		ft_prt_err("Bad cylinder setting given", i, 22);
	if (i == 1018)
		ft_prt_err("Bad triangle setting given", i, 22);
	(void)s;
}
