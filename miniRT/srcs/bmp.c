/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:38:44 by nclabaux          #+#    #+#             */
/*   Updated: 2020/08/02 17:46:20 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"

void	ft_save_img(t_img_link *il, t_scene *ascene, char *rt_file)
{
	char	*name;
	int		fd;

	name = NULL;
	if (!(name = ft_gen_name(il, rt_file)))
		ft_errors(ascene, 1011, "");
	if ((fd = open(name, O_WRONLY | O_TRUNC)) < 1)
	{
		if ((fd = open(name, O_WRONLY | O_CREAT, S_IRWXU)) < 1)
		{
			free(name);
			ft_printf("\n");
			ft_errors(ascene, 1022, "");
		}
	}
	ft_bmp_header(fd, ascene);
	ft_write_bmp_data(fd, il, ascene);
	close(fd);
	free(name);
}

char	*ft_gen_name(t_img_link *il, char *rt_file)
{
	char	*name;
	char	*file;
	size_t	size;

	if (!(file = ft_cut_filename(rt_file)))
		return (NULL);
	size = (ft_strlen(file) + 14);
	if (!(name = malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero(name, size);
	ft_strlcat(name, "saves/", size);
	ft_strlcat(name, file, size);
	ft_strlcat(name, "_XX.bmp", size);
	if (il->nbr < 100)
	{
		name[size - 7] = '0' + il->nbr / 10;
		name[size - 6] = '0' + il->nbr % 10;
	}
	else
	{
		name[size - 7] = 'a' + il->nbr / 26 - 1;
		name[size - 6] = 'a' + il->nbr % 26 - 1;
	}
	free(file);
	return (name);
}

void	ft_bmp_header(int fd, t_scene *ascene)
{
	t_bmp_header	hd;

	hd.type[0] = 'B';
	hd.type[1] = 'M';
	hd.offset = 54;
	hd.size = (ascene->res.x * ascene->res.y * 4) + hd.offset;
	hd.reserved = 0;
	hd.dib_size = 40;
	hd.dib_x = ascene->res.x;
	hd.dib_y = ascene->res.y;
	hd.dib_color_planes = 1;
	hd.dib_bpp = 32;
	hd.dib_compress = 0;
	hd.dib_img_size = hd.size;
	hd.dib_x_ppm = 2776;
	hd.dib_y_ppm = 2776;
	hd.dib_colors_in_palette = 0;
	hd.dib_important_colors = 0;
	ft_write_bmp_hd(fd, hd);
}

void	ft_write_bmp_hd(int fd, t_bmp_header hd)
{
	write(fd, &hd.type, 2);
	write(fd, &hd.size, 4);
	write(fd, &hd.reserved, 4);
	write(fd, &hd.offset, 4);
	write(fd, &hd.dib_size, 4);
	write(fd, &hd.dib_x, 4);
	write(fd, &hd.dib_y, 4);
	write(fd, &hd.dib_color_planes, 2);
	write(fd, &hd.dib_bpp, 2);
	write(fd, &hd.dib_compress, 4);
	write(fd, &hd.dib_img_size, 4);
	write(fd, &hd.dib_x_ppm, 4);
	write(fd, &hd.dib_y_ppm, 4);
	write(fd, &hd.dib_colors_in_palette, 4);
	write(fd, &hd.dib_important_colors, 4);
}

void	ft_write_bmp_data(int fd, t_img_link *il, t_scene *ascene)
{
	char	*data;
	int		pixel;
	int		byte;

	if (!(data = malloc(ascene->res.x * ascene->res.y * 4)))
		ft_errors(ascene, 1011, "");
	pixel = 0;
	byte = 0;
	while (pixel < ascene->res.x * ascene->res.y)
	{
		data[byte++] = il->fp[pixel] & 255;
		data[byte++] = (il->fp[pixel] & (255 << 8)) >> 8;
		data[byte++] = (il->fp[pixel] & (255 << 16)) >> 16;
		data[byte++] = 0;
		pixel++;
	}
	write(fd, data, ascene->res.x * ascene->res.y * 4);
	free(data);
}
