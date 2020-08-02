/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 17:02:28 by nclabaux          #+#    #+#             */
/*   Updated: 2020/08/02 17:28:59 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include <X11/Xlib.h>
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
	t_td			v;
	t_td			l;
	t_td			m;
	double			fov;
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
	t_td	p;
	t_td	v;
	t_color	color;
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
	t_td		v;
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
	t_td		v;
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
	unsigned int		*fp;
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
	void			*mlx;
}				t_scene;

typedef struct	s_ray
{
	t_td	p;
	t_td	v;
}				t_ray;

typedef struct	s_intersec
{
	t_td	p;
	double	dist;
	t_td	normal;
	t_color	color;
}				t_intersec;

typedef struct	s_pixel
{
	int				x;
	int				y;
	unsigned int	color;
	t_camera		*cam;
}				t_pixel;

typedef struct	s_bmp_header
{
	char			type[2];
	unsigned int	size;
	unsigned int	reserved;
	unsigned int	offset;
	unsigned int	dib_size;
	int				dib_x;
	int				dib_y;
	unsigned short	dib_color_planes;
	unsigned short	dib_bpp;
	unsigned int	dib_compress;
	unsigned int	dib_img_size;
	int				dib_x_ppm;
	int				dib_y_ppm;
	int				dib_colors_in_palette;
	int				dib_important_colors;
}				t_bmp_header;

/*
**	bmp.c
*/
void			ft_save_img(t_img_link *il, t_scene *as, char *rt_file);
char			*ft_gen_name(t_img_link *il, char *rt_file);
void			ft_bmp_header(int fd, t_scene *as);
void			ft_write_bmp_hd(int fd, t_bmp_header hd);
void			ft_write_bmp_data(int fd, t_img_link *il, t_scene *as);

/*
**	calculus.c
*/
int				ft_solve_quadra(double a, double b, double c, double root[2]);
double			ft_sq(double x);
double			ft_max_double(double a, double b);
double			ft_min_double(double a, double b);

/*
**	clear.c
*/
void			ft_terminator(t_scene *as);
int				ft_kill(t_scene *as);
void			ft_destroy_images(t_scene *as);

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
double			ft_p_line_dist(t_td p, t_td l_p, t_td l_v);

/*
**	errors.c
*/
void			ft_ptr_err(t_scene *as, char *s, int i, int x);
void			ft_errors(t_scene *as, int i, char *s);
void			ft_errors1(t_scene *as, int i, char *s);
void			ft_errors2(t_scene *as, int i, char *s);

/*
**	file_reading.c
*/
void			ft_read_file(char *file, t_scene *as);
void			ft_translate_line(char **line, t_scene *as);
int				ft_read_color(t_scene *as, char *s, t_color *color_storage);
int				ft_read_double(t_scene *as, char *s, double *coor);
int				ft_read_td(t_scene *as, char*s, t_td *point);

/*
**	file_reading1.c
*/
void			ft_res_rd(char **line, t_scene *as);
void			ft_al_rd(char **line, t_scene *as);
void			ft_cam_rd(char **line, t_scene *as);
void			ft_light_rd(char **line, t_scene *as);
void			ft_pl_rd(char **line, t_scene *as);

/*
**	file_reading2.c
*/
void			ft_sp_rd(char **line, t_scene *as);
void			ft_sp_rd2(char **s, t_scene *as, t_obj_link *new_ol, int i);
void			ft_sq_rd(char **line, t_scene *as);
void			ft_sq_rd2(char **s, t_scene *as, t_square sq, int i);
void			ft_tr_rd(char **line, t_scene *as);

/*
**	file_reading3.c
*/
void			ft_cy_rd(char **line, t_scene *as);
void			ft_cy_rd2(char **s, t_scene *as, t_obj_link *new_ol, int i);

/*
**	images.c
*/
void			ft_gen_img(t_scene *as);
void			ft_img_loop(t_pixel px, t_scene *as, t_ray ray,
					t_img_link *new);
t_img_link		*ft_set_image(t_scene scene, int *nbr);
void			ft_add_pixel(t_img_link	*il, t_pixel px);

/*
**	intersection.c
*/
t_intersec		ft_pl_inter(t_ray ray, t_plane pl);
t_intersec		ft_tr_inter(t_ray ray, t_triangle tr);
double			ft_td_in_triangle(t_td p, t_triangle tr);
t_intersec		ft_sp_inter(t_ray ray, t_sphere sp);
t_intersec		ft_sp_inter2(t_ray ray, double r[2]);

/*
**	intersection1.c
*/
t_intersec		ft_cy_inter(t_ray ray, t_cylinder cy);
t_intersec		ft_cy_disc(t_ray ray, t_plane disc, double r);
t_intersec		ft_cy_side(t_ray ray, t_cylinder cy);
double			ft_get_roots(t_ray ray, t_cylinder cy);

/*
**	light.c
*/
t_color			ft_get_light(t_intersec i, t_scene scene);
t_color			ft_get_light2(t_color res, t_light *light, t_intersec i,
					double lambert);

/*
**	list_handling.c
*/
void			ft_add_cam(t_scene *as, t_camera *new_cam);
void			ft_add_light(t_scene *as, t_light *new_light);
void			ft_add_object(t_scene *as, t_obj_link *new_ol);
void			ft_add_img_link(t_scene *as, t_img_link *new_img_link);

/*
**	loop.c
*/
int				ft_key(int key, void *p[3]);
void			ft_disp_next_img(void *p[3]);
void			ft_disp_prev_img(void *p[3]);
int				ft_disp_curr_img(void *p[3]);

/*
**	main.c
*/
int				main(int argc, char **argv);
void			ft_init_scene(t_scene *as);
void			ft_put_images_to_window(t_scene *as);
void			ft_save_images_to_bmp(t_scene *as, char *rt_file);

/*
**	ray.c
*/
t_td			ft_get_ray_v(t_scene scene, t_camera *cam, int x, int y);
t_td			ft_get_ray_v2(double q, t_td v);
t_intersec		ft_shot_ray(t_ray ray, t_scene scene);

/*
**	set_data.c
*/
void			ft_set_cam_data(t_camera *cam);
void			ft_set_tr_data(t_triangle *tr);
void			ft_set_sq_data(t_square *sq, t_scene *as);
void			ft_create_4tr_sq(t_square *sq, t_scene *as);
void			ft_alloc_tr(t_triangle tr, t_scene *as);

/*
**	utils.c
*/
char			*ft_cut_filename(char *filename);

/*
**	vectorial_calculus.c
*/
t_td			ft_3p_to_v(t_td a, t_td b, t_td c);
double			ft_dot(t_td a, t_td b);
t_td			ft_cross(t_td a, t_td b);
double			ft_norm(t_td v);
t_td			ft_2p_to_v(t_td a, t_td b);

/*
**	vectorial_calculus1.c
*/
t_td			ft_add_td_n(t_td p, t_td v, double n);
t_td			ft_unit_v(t_td v);
t_td			ft_inverse(t_td v);
t_td			ft_multi_td(t_td v, double n);

/*
**	verification.c
*/
void			ft_scene_verif(t_scene *as);
void			ft_vector_verif(t_scene *as, t_td *v);
void			ft_res_verif(t_scene *as);
void			ft_al_verif(t_scene *as);

/*
**	verification1.c
*/
void			ft_cam_verif(t_scene *as);
void			ft_light_verif(t_scene *as);
void			ft_object_verif(t_scene *as);

#endif
