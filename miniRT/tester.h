/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux </var/mail/nclabaux>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 17:15:55 by nclabaux          #+#    #+#             */
/*   Updated: 2020/04/16 17:14:46 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
//# include <errno.h>
# include "minilibx-linux/mlx.h"
# include <math.h>

int	rgb_to_int(int r, int g, int b);
int	range_check(int a);

#endif
