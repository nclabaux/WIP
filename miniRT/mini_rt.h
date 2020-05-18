/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 17:02:28 by nclabaux          #+#    #+#             */
/*   Updated: 2020/05/18 17:09:40 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include <mlx.h>
# include <math.h>
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


typedef struct	s_point
{
	double	x;
	double	y;
	double	z;
}		t_point;

typedef	struct	s_vector
{
	double	x;
	double	y;
	double	z;
}		t_vector;

typedef struct	s_color
{
	int	r;
	int	g;
	int	b;
}		t_color;

typedef struct	s_resolution
{
	int	x;
	int	y;
}		t_resolution;

typedef struct	s_amb_light
{
	double		intensity;
	t_color	color;
}		t_amb_light;

typedef struct	s_camera
{
	t_point	point;
	t_vector	orientation;
	int	fov;
	struct s_camera	*next;
}		t_camera;

typedef struct	s_light
{
	t_point	point;
	double		brightness;
	t_color	color;
	struct s_light		*next;
}		t_light;

typedef struct	s_sphere
{
	t_point	point;
	double		diameter;
	t_color	color;
}		t_sphere;

typedef struct	s_plane
{	
	t_point	p;
	t_vector	v;
	t_color	color;
}		t_plane;

typedef struct	s_square
{
	t_point	point;
	t_vector	orientation;
	double	size;
	t_color	color;
}		t_square;

typedef struct	s_cylinder
{
	t_point	point;
	t_vector	orientation;
	double	diameter;
	double	height;
	t_color	color;	
}		t_cylinder;

typedef struct	s_triangle
{
	t_point	p1;
	t_point	p2;
	t_point	p3;
	t_color	color;	
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
	t_object	*object;
	struct s_obj_link	*next;
}		t_obj_link;

typedef struct	s_scene
{
	t_resolution	res;
	t_amb_light	al;
	t_camera	*cam_list;
	t_light		*light_list;
	t_obj_link	*object_list;
}		t_scene;

double	ft_two_pts_dist(t_point a, t_point b);

void	ft_ptr_err(char *s, int i, int x);
void	ft_errors(int i, char *s);

void	ft_read_file(char *file, t_scene *ascene);
void	ft_translate_line(char **line, t_scene *ascene);
int		ft_read_color(char *s, t_color *color_storage);
int		ft_read_double(char *s, double *coor);
int		ft_read_point(char*s, t_point *point);

int		ft_read_vector(char *s, t_vector *vector);
void	ft_res_rd(char **line, t_scene *ascene);
void	ft_al_rd(char **line, t_scene *ascene);
void	ft_cam_rd(char **line, t_scene *ascene);
void	ft_light_rd(char **line, t_scene *ascene);

void	ft_pl_rd(char **line, t_scene *ascene);
void	ft_sp_rd(char **line, t_scene *ascene);
void	ft_sq_rd(char **line, t_scene *ascene);
void	ft_cy_rd(char **line, t_scene *ascene);
void	ft_tr_rd(char **line, t_scene *ascene);

void	ft_add_cam(t_scene *ascene, t_camera *new_cam);
void	ft_add_light(t_scene *ascene, t_light *new_light);
void	ft_add_object(t_scene *ascene, t_obj_link *new_ol);

int	main(int argc, char **argv);
void	ft_init_scene(t_scene *ascene);

t_vector	ft_vec_from_3pts(t_point a, t_point b, t_point c);
double	ft_max_double(double a, double b);

#endif
