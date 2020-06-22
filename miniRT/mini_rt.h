/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 17:02:28 by nclabaux          #+#    #+#             */
/*   Updated: 2020/06/22 15:40:05 by nclabaux         ###   ########.fr       */
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
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
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
	t_point	p;
	t_vector	v;
	t_vector	l;
	t_vector	m;
	int	fov;
	struct s_camera	*next;
}		t_camera;

typedef struct	s_light
{
	t_point	p;
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

typedef struct	s_triangle
{
	t_point	p1;
	t_point	p2;
	t_point	p3;
	t_color	color;	
	double	area_x2;
}		t_triangle;

typedef struct	s_square
{
	t_point	p;
	t_vector	v;
	double	size;
	t_color	color;
	t_triangle	a;
	t_triangle	b;
}		t_square;

typedef struct	s_cylinder
{
	t_point	p;
	t_vector	v;
	double	d;
	double	height;
	t_color	color;	
}		t_cylinder;

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
	int		type;
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

typedef struct	s_ray
{
	t_point		p;
	t_vector	v;
}		t_ray;

typedef struct	s_intersec
{
	t_point		p;
	double		dist;
	t_vector	normal;
	t_color		color;
}		t_intersec;

typedef struct	s_img_link
{
	void	*ip;
	char	*fp;
	int		bpp;
	int		sl;
	int		en;
	struct s_img_link	*next;
}		t_img_link;

/*
**	calculus.c
*/
int		ft_solve_quadratic(double a, double b, double c, double root[2]);
double	ft_sq(double x);
double	ft_max_double(double a, double b);
double	ft_min_double(double a, double b);

/*
**	colors.c
*/
int	ft_rgb_to_int(t_color c);
t_color	ft_add_colors(t_color a, t_color b);
t_color	ft_multiply_colors(t_color a, t_color b);
t_color	ft_weight_color(t_color	c, double intensity);
unsigned int	ft_get_color(t_ray ray, void *mlx_ptr, t_scene scene);

/*
**	distance.c
*/
double	ft_two_pts_dist(t_point a, t_point b);

/*
**	errors.c
*/
void	ft_ptr_err(char *s, int i, int x);
void	ft_errors(int i, char *s);
void	ft_errors1(int i, char *s);

/*
**	file_reading.c
*/
void	ft_read_file(char *file, t_scene *ascene);
void	ft_translate_line(char **line, t_scene *ascene);
int		ft_read_color(char *s, t_color *color_storage);
int		ft_read_double(char *s, double *coor);
int		ft_read_point(char*s, t_point *point);

/*
**	file_reading1.c
*/
int		ft_read_vector(char *s, t_vector *vector);
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
**	images.c
*/
void	ft_gen_images(t_scene scene, t_img_link **img_lst, void *mlx_ptr);
void	ft_set_image(t_img_link **il, void *mlx_ptr, t_scene scene);
void	ft_create_bmp(void *image, char *filename, t_scene scene);

/*
**	intersection.c
*/
t_intersec	ft_pl_inter(t_ray, t_plane pl);
t_intersec	ft_tr_inter(t_ray, t_triangle tr);
t_intersec	ft_sq_inter(t_ray, t_square sq);
t_intersec	ft_sp_inter(t_ray, t_sphere sp);
t_intersec	ft_cy_inter(t_ray, t_cylinder cy);

/*
**	intersection1.c
*/
double	ft_point_in_triangle(t_point p, t_triangle tr);
t_intersec	ft_cy_side(t_ray ray, t_cylinder cy);
double*		ft_set_number(t_ray ray, t_cylinder cy);

/*
**	light.c
*/
t_color	ft_get_light(t_intersec i, t_scene scene);

/*
**	list_handling.c
*/
void	ft_add_cam(t_scene *ascene, t_camera *new_cam);
void	ft_add_light(t_scene *ascene, t_light *new_light);
void	ft_add_object(t_scene *ascene, t_obj_link *new_ol);

/*
**	loop.c
*/
int esc_key_pressed(int key, void *p);

/*
**	main.c
*/
int	main(int argc, char **argv);
void	ft_init_scene(t_scene *ascene);
t_vector	ft_get_ray_v(t_scene scene, t_camera *cam, int x, int y);
t_intersec	ft_shot_ray(t_ray ray, t_scene scene);

/*
**	set_data.c
*/
void	ft_set_tr_data(t_triangle *tr);
void	ft_set_sq_data(t_square *sq);

/*
**	vectorial_calculus.c
*/
t_vector	ft_3p_to_v(t_point a, t_point b, t_point c);
double		ft_scalar_prod(t_vector a, t_vector b);
t_vector	ft_cross_prod(t_vector a, t_vector b);
double	ft_norm(t_vector v);
t_vector	ft_2p_to_v(t_point a, t_point b);

/*
**	vectorial_calculus1.c
*/
t_point	ft_add_v(t_point p, t_vector v, double	size);
t_vector	ft_unit_v(t_vector v);

/*
**	verification.c
*/
void	ft_scene_verif(t_scene *ascene, void *mlx_ptr);
int		ft_vector_verif(t_vector *v);
void	ft_res_verif(t_scene *ascene, void *mlx_ptr);
void	ft_al_verif(t_scene *ascene);

/*
**	verification1.c
*/
void	ft_cam_verif(t_scene *ascene);
void	ft_light_verif(t_scene *ascene);

#endif
