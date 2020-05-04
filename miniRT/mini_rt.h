/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 17:02:28 by nclabaux          #+#    #+#             */
/*   Updated: 2020/05/04 15:58:41 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include "libft/libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/gnl/get_next_line.h"

typedef struct	s_point3
{
	double	x;
	double	y;
	double	z;
}		t_point3;

typedef	struct	s_vector3
{
	double	x;
	double	y;
	double	z;
}		t_vector3;

typedef struct	s_color3
{
	int	r;
	int	g;
	int	b;
}		t_color3;

typedef struct	s_resolution
{
	int	x;
	int	y;
}		t_resolution;

typedef struct	s_amb_light
{
	double		intensity;
	t_color3	color;
}		t_amb_light;

typedef struct	s_camera
{
	t_point3	point;
	t_vector3	orientation;
	int	fov;
	t_camera	*next;
}		t_camera;

typedef struct	s_light
{
	t_point3	point;
	double		brightness;
	t_color3	color;
	t_light		*next;
}		t_light;

typedef struct	s_sphere
{
	t_point3	point;
	double		diameter;
	t_color3	color;
}		t_sphere;

typedef struct	s_plane
{	
	t_point3	point;
	t_vector3	orientation;
	t_color3	color;
}		t_plane;

typedef struct	s_square
{
	t_point3	point;
	t_vector3	orientation;
	double	size;
	t_color3	color;
}		t_square;

typedef struct	s_cylinder
{
	t_point3	point;
	t_vector3	orientation;
	double	diamater;
	double	height;
	t_color3	color;	
}		t_cylinder;

typedef struct	s_triangle
{
	t_point3	p1;
	t_point3	p2;
	t_point3	p3;
	t_color3	color;	
}		t_triangle;

typedef	union	u_object
{
	t_sphere	sp;
	t_plane		pl;
	t_square	sq;
	t_cylinder	cy;
	t_triangle	tr;
}		t_object;

typedef	struct	s_obj_link
{
	t_object	object;
	t_object	*next;
}		t_obj_link;

typedef struct	s_scene
{
	t_resolution	res;
	t_amb_light	al;
	t_camera	*cam_list;
	t_light		*light_list;
	t_obj_link	*object_list;
}		t_scene;



#endif
