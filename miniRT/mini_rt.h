/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 17:02:28 by nclabaux          #+#    #+#             */
/*   Updated: 2020/05/11 15:47:15 by nclabaux         ###   ########.fr       */
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

/*
**	distances.c
*/
double	ft_two_pts_dist(t_point3 a, t_point3 b);

/*
**	errors.c
*/
void	ft_ptr_err(char *s, int i, int x);
void	ft_errors(int i, char *s);

/*
**	file_reading.c
*/
void	ft_read_file(char *file, t_scene *ascene);
void	ft_translate_line(char **line, t_scene *ascene);
void	ft_read_color(char *s, t_color *color_storage);
int		ft_read_double(char *s, double *coor);
int		ft_read_point(char*s, t_point3 *point);

/*
**	file_reading1.c
*/
int		ft_read_vector(char *s, t_vector3 *vector);
void	ft_res_rd(char **line, t_scene *ascene);
void	ft_al_rd(char **line, t_scene *ascene);
void	ft_cam_rd(char **line, t_scene *ascene);
void	ft_light_rd(char **line, t_scene *ascene);

/*
**	file_reading2.c
*/
void	ft_pl_rd(char **line, t_scene *ascene);
void	ft_sp_rd(char **line, t_scene *ascene);
void	ft_sq_rd(char **line, t_scene *ascene);
void	ft_cy_rd(char **line, t_scene *ascene);
void	ft_tr_rd(char **line, t_scene *ascene);

/*
**	list_handling.c
*/
void	ft_add_cam(t_scene *ascene, t_camera *new_cam);
void	ft_add_light(t_scene *ascene, t_light *new_light);
void	ft_add_object(t_scene *ascene, t_obj_link *new_ol);

/*
**	main.c
*/
int	main(int argc, char **argv);
void	ft_init_scene(t_scene *ascene);

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
	struct s_camera	*next;
}		t_camera;

typedef struct	s_light
{
	t_point3	point;
	double		brightness;
	t_color3	color;
	struct s_light		*next;
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
