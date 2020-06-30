/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:24:20 by loamar            #+#    #+#             */
/*   Updated: 2020/06/28 17:40:56 by lorenzoamar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void				fill_bitmap(t_cub3d *cub, int fd)
{
	unsigned char	rgb[3];
	int				x;
	int				y;

	y = 0;
	while (y < cub->map->res_y - 1)
	{
		x = 0;
		while (x < cub->map->res_x)
		{
			rgb[0] = (240 & (cub->img->img_buf[(cub->map->res_y - 1 - y)
			* cub->map->res_x + x]) >> 16);
			rgb[1] = (240 & (cub->img->img_buf[(cub->map->res_y - 1 - y)
			* cub->map->res_x + x]) >> 8);
			rgb[2] = (240 & cub->img->img_buf[(cub->map->res_y - 1 - y)
			* cub->map->res_x + x]);
			write(fd, rgb + 2, 1);
			write(fd, rgb + 1, 1);
			write(fd, rgb + 0, 1);
			x++;
		}
		y++;
	}
}

static unsigned char	*create_file_header(int res_y, int res_x)
{
	int						nb_octet;
	static unsigned char	bmp_file_header[] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};
	int						padding;

	padding = (4 - (res_x * 3) % 4) % 4;
	nb_octet = 14 + 40 + (3 * res_x + padding) * res_y;
	bmp_file_header[0] = (unsigned char)('B');
	bmp_file_header[1] = (unsigned char)('M');
	bmp_file_header[2] = (unsigned char)(nb_octet);
	bmp_file_header[3] = (unsigned char)(nb_octet >> 8);
	bmp_file_header[4] = (unsigned char)(nb_octet >> 16);
	bmp_file_header[5] = (unsigned char)(nb_octet >> 24);
	bmp_file_header[10] = (unsigned char)(54);
	return (bmp_file_header);
}

static unsigned char	*create_bitmap_header(int res_y, int res_x)
{
	static unsigned char bmp_bitmap_header[] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};

	bmp_bitmap_header[0] = (unsigned char)(40);
	bmp_bitmap_header[4] = (unsigned char)(res_x);
	bmp_bitmap_header[5] = (unsigned char)(res_x >> 8);
	bmp_bitmap_header[6] = (unsigned char)(res_x >> 16);
	bmp_bitmap_header[7] = (unsigned char)(res_x >> 24);
	bmp_bitmap_header[8] = (unsigned char)(res_y);
	bmp_bitmap_header[9] = (unsigned char)(res_y >> 8);
	bmp_bitmap_header[10] = (unsigned char)(res_y >> 16);
	bmp_bitmap_header[11] = (unsigned char)(res_y >> 24);
	bmp_bitmap_header[12] = (unsigned char)(1);
	bmp_bitmap_header[14] = (unsigned char)(3 * 8);
	return (bmp_bitmap_header);
}

int						create_bmp(t_cub3d *cub)
{
	int				fd;
	unsigned char	*file_header;
	unsigned char	*bitmap_header;

	file_header = create_file_header(cub->map->res_y - 1, cub->map->res_x);
	bitmap_header = create_bitmap_header(cub->map->res_y - 1, cub->map->res_x);
	if ((fd = open("save.bmp", O_RDWR)) < 0)
		ft_error(cub, "Bad screenshot 2.\n", 1);
	write(fd, file_header, 14);
	write(fd, bitmap_header, 40);
	fill_bitmap(cub, fd);
	close(fd);
	return (0);
}
