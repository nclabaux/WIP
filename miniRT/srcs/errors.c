/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 18:22:33 by nclabaux          #+#    #+#             */
/*   Updated: 2020/08/02 17:37:50 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

void	ft_prt_err(t_scene *as, char *s, int i, int x)
{
	if (!x)
		ft_printf("\033[01;31mError %d: %s\n", i - 1000, s);
	else
		ft_printf("\033[01;31mError %d: %s\n%s\n", i - 1000, s, strerror(x));
	ft_printf("\033[22;31mAborting...\n\n\033[22;37m");
	ft_kill(as);
}

void	ft_errors(t_scene *as, int i, char *s)
{
	if (i < 1000 || i > 1100)
		ft_prt_err(as, "Unknown error  ¯\\_(ツ)_/¯", i, 0);
	if (i == 1000)
		ft_prt_err(as, "No file given\n./miniRT <file.rt> [-save]", i, 0);
	if (i == 1001)
		ft_prt_err(as, s, i, 22);
	if (i == 1002)
		ft_prt_err(as, "Unable to read from file", i, 0);
	if (i == 1003)
		ft_prt_err(as, "Multiple resolution setting", i, 22);
	if (i == 1004)
		ft_prt_err(as, "Multiple ambient light setting", i, 22);
	if (i == 1005)
		ft_prt_err(as, s, i, 22);
	if (i == 1006)
		ft_prt_err(as, "Bad resolution setting given", i, 22);
	if (i == 1007)
		ft_prt_err(as, "Bad ambient light setting given", i, 22);
	if (i == 1008)
		ft_prt_err(as, "Bad color given", i, 22);
	if (i == 1009)
		ft_prt_err(as, "Bad coordinates given", i, 22);
	ft_errors1(as, i, s);
}

void	ft_errors1(t_scene *as, int i, char *s)
{
	if (i == 1010)
		ft_prt_err(as, "Bad orientation vector given", i, 22);
	if (i == 1011)
		ft_prt_err(as, "Error during memory allocation", i, 12);
	if (i == 1012)
		ft_prt_err(as, "Bad camera setting given", i, 22);
	if (i == 1013)
		ft_prt_err(as, "Bad light setting given", i, 22);
	if (i == 1014)
		ft_prt_err(as, "Bad plane setting given", i, 22);
	if (i == 1015)
		ft_prt_err(as, "Bad sphere setting given", i, 22);
	if (i == 1016)
		ft_prt_err(as, "Bad square setting given", i, 22);
	if (i == 1017)
		ft_prt_err(as, "Bad cylinder setting given", i, 22);
	if (i == 1018)
		ft_prt_err(as, "Bad triangle setting given", i, 22);
	if (i == 1019)
		ft_prt_err(as, "No camera", i, 22);
	ft_errors2(as, i, s);
}

void	ft_errors2(t_scene *as, int i, char *s)
{
	if (i == 1020)
		ft_prt_err(as, "Zero vector detected", i, 22);
	if (i == 1021)
		ft_prt_err(as, "Vector coordinates out of [-1, 1] range", i, 33);
	if (i == 1022)
		ft_prt_err(as, "Unable to create bmp file", i, 0);
	if (i == 1023)
		ft_prt_err(as, "Unable to write bmp file", i, 0);
	if (i == 1024)
		ft_prt_err(as, s, i, 22);
	if (i == 1025)
		ft_prt_err(as, "Too many arguments\n./miniRT <file.rt> [-save]", i, 0);
	(void)s;
}
