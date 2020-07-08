/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 17:02:28 by nclabaux          #+#    #+#             */
/*   Updated: 2020/07/08 19:05:19 by nclabaux         ###   ########.fr       */
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

typedef struct	s_td
{
	double	x;
	double	y;
	double	z;
}				t_td;

typedef struct	s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_color;

typedef struct	s_resolution
{
	int	x;
	int	y;
}				t_resolution;

typedef struct	s_amb_light
{
	double		intensity;
	t_color		color;
}				t_amb_light;

typedef struct	s_camera
{
	t_td			p;
	t_td		v;
	t_td		l;
	t_td		m;
	int				fov;
	struct s_camera	*next;
}				t_camera;

typedef struct	s_light
{
	t_td			p;
	double			brightness;
	t_color			color;
	struct s_light	*next;
}				t_light;

typedef struct	s_sphere
{
	t_td	p;
	double	diam;
	t_color	color;
}				t_sphere;

typedef struct	s_plane
{
	t_td		p;
	t_td	v;
	t_color		color;
}				t_plane;

typedef struct	s_triangle
{
	t_td	p1;
	t_td	p2;
	t_td	p3;
	t_color	color;
	double	area_x2;
}				t_triangle;

typedef struct	s_square
{
	t_td		p;
	t_td	v;
	double		size;
	t_color		color;
	t_triangle	a;
	t_triangle	b;
	t_triangle	c;
	t_triangle	d;
}				t_square;

typedef struct	s_cylinder
{
	t_td		p;
	t_td	v;
	double		d;
	double		h;
	t_color		color;
}				t_cylinder;

typedef	union	u_object
{
	t_sphere	sp;
	t_plane		pl;
	t_square	sq;
	t_cylinder	cy;
	t_triangle	tr;
}				t_object;

typedef	struct	s_obj_link
{
	t_object			*object;
	int					type;
	struct s_obj_link	*next;
}				t_obj_link;

typedef struct	s_img_link
{
	void				*ip;
	unsigned int				*fp;
	int					bpp;
	int					sl;
	int					en;
	int					nbr;
	int					total;
	struct s_img_link	*next;
}				t_img_link;

typedef struct	s_scene
{
	t_resolution	res;
	t_amb_light		al;
	t_camera		*cam_list;
	int				cam_nbr;
	t_light			*light_list;
	t_obj_link		*object_list;
	t_img_link		*img_list;
}				t_scene;

typedef struct	s_ray
{
	t_td		p;
	t_td	v;
}				t_ray;

typedef struct	s_intersec
{
	t_td		p;
	double		dist;
	t_td		normal;
	t_color		color;
}				t_intersec;

typedef struct	s_pixel
{
	int		x;
	int		y;
	unsigned int	color;
}				t_pixel;

/*
**	calculus.c
*/
int				ft_solve_quadra(double a, double b, double c, double root[2]);
double			ft_sq(double x);
double			ft_max_double(double a, double b);
double			ft_min_double(double a, double b);

/*
**	colors.c
*/
int				ft_rgb_to_int(t_color c);
t_color			ft_add_colors(t_color a, t_color b);
t_color			ft_multiply_colors(t_color a, t_color b);
t_color			ft_weight_color(t_color	c, double intensity);
unsigned int	ft_get_color(t_ray ray, void *mlx_ptr, t_scene scene);

/*
**	distance.c
*/
double			ft_2p_dist(t_td a, t_td b);

/*
**	errors.c
*/
void			ft_ptr_err(char *s, int i, int x);
void			ft_errors(int i, char *s);
void			ft_errors1(int i, char *s);
void			ft_errors2(int i, char *s);

/*
**	file_reading.c
*/
void			ft_read_file(char *file, t_scene *ascene);
void			ft_translate_line(char **line, t_scene *ascene);
int				ft_read_color(char *s, t_color *color_storage);
int				ft_read_double(char *s, double *coor);
int				ft_read_td(char*s, t_td *point);

/*
**	file_reading1.c
*/
void			ft_res_rd(char **line, t_scene *ascene);
void			ft_al_rd(char **line, t_scene *ascene);
void			ft_cam_rd(char **line, t_scene *ascene);
void			ft_light_rd(char **line, t_scene *ascene);

/*
**	file_reading2.c
*/
void			ft_pl_rd(char **line, t_scene *ascene);
void			ft_sp_rd(char **line, t_scene *ascene);
void			ft_sq_rd(char **line, t_scene *ascene);
void			ft_cy_rd(char **line, t_scene *ascene);
void			ft_tr_rd(char **line, t_scene *ascene);

/*
**	images.c
*/
void			ft_gen_img(t_scene *ascene, void *mlx_ptr);
t_img_link		*ft_set_image(void *mlx_ptr, t_scene scene);
void			ft_add_pixel(t_img_link	*il, t_pixel px);
void			ft_create_bmp(void *image, char *filename, t_scene scene);

/*
**	intersection.c
*/
t_intersec		ft_pl_inter(t_ray ray, t_plane pl);
t_intersec		ft_tr_inter(t_ray ray, t_triangle tr);
t_intersec		ft_sq_inter(t_ray ray, t_square sq);
t_intersec		ft_sp_inter(t_ray ray, t_sphere sp);
t_intersec		ft_cy_inter(t_ray ray, t_cylinder cy);

/*
**	intersection1.c
*/
double			ft_td_in_triangle(t_td p, t_triangle tr);
t_intersec		ft_cy_side(t_ray ray, t_cylinder cy);
double			*ft_set_number(t_ray ray, t_cylinder cy);

/*
**	light.c
*/
t_color			ft_get_light(t_intersec i, t_scene scene);

/*
**	list_handling.c
*/
void			ft_add_cam(t_scene *ascene, t_camera *new_cam);
void			ft_add_light(t_scene *ascene, t_light *new_light);
void			ft_add_object(t_scene *ascene, t_obj_link *new_ol);
void			ft_add_img_link(t_scene *ascene, t_img_link *new_img_link);

/*
**	loop.c
*/
int				ft_key(int key, void *p[4]);
void			ft_disp_next_img(void *p[4]);
void			ft_disp_prev_img(void *p[4]);
void			ft_terminator(t_scene *ascene);

/*
**	main.c
*/
int				main(int argc, char **argv);
void			ft_put_images_to_window(void *mlx_ptr, t_scene *ascene);

/*
**	ray.c
*/
void			ft_init_scene(t_scene *ascene);
t_td		ft_get_ray_v(t_scene scene, t_camera *cam, int x, int y);
t_intersec		ft_shot_ray(t_ray ray, t_scene scene);

/*
**	set_data.c
*/
void			ft_set_tr_data(t_triangle *tr);
void			ft_set_sq_data(t_square *sq, t_scene *ascene);
void			ft_create_4tr_sq(t_square *sq, t_scene *ascene);
void			ft_alloc_tr(t_triangle tr, t_scene *ascene);

/*
**	vectorial_calculus.c
*/
t_td		ft_3p_to_v(t_td a, t_td b, t_td c);
double			ft_dot(t_td a, t_td b);
t_td		ft_cross(t_td a, t_td b);
double			ft_norm(t_td v);
t_td		ft_2p_to_v(t_td a, t_td b);

/*
**	vectorial_calculus1.c
*/
t_td			ft_add_td_n(t_td p, t_td v, double n);
t_td		ft_unit_v(t_td v);
t_td		ft_inverse(t_td v);
t_td		ft_multi_td(t_td v, double n);

/*
**	verification.c
*/
void			ft_scene_verif(t_scene *ascene, void *mlx_ptr);
void			ft_td_verif(t_td *v);
void			ft_res_verif(t_scene *ascene, void *mlx_ptr);
void			ft_al_verif(t_scene *ascene);

/*
**	verification1.c
*/
void			ft_cam_verif(t_scene *ascene);
void			ft_light_verif(t_scene *ascene);
void			ft_object_verif(t_scene *ascene);

#endif
