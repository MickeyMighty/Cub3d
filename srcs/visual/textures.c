/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 13:50:16 by loamar            #+#    #+#             */
/*   Updated: 2020/06/13 18:07:59 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int		display_textures5(t_cub3d *cub, int res_x, int res_y, int i)
{
	if (i == 4)
	{
		if (!(cub->img->xpm_to_img[i] =
		mlx_xpm_file_to_image(cub->game->mlx_ptr,
		cub->map->sprite_texture, &res_x, &res_y)))
		{
			cub->img->size_error = 4;
			return (0);
		}
		else
			cub->img->data_textures[i] =
			(int*)mlx_get_data_addr(cub->img->xpm_to_img[i],
			&cub->game->bits_per_pixels6, &cub->game->size_line6,
			&cub->game->endian6);
	}
	return (1);
}

static int		display_textures4(t_cub3d *cub, int res_x, int res_y, int i)
{
	if (i == 3)
	{
		if (!(cub->img->xpm_to_img[i] =
		mlx_xpm_file_to_image(cub->game->mlx_ptr, cub->map->north_texture,
		&res_x, &res_y)))
		{
			cub->img->size_error = 3;
			return (0);
		}
		else
			cub->img->data_textures[i] =
			(int*)mlx_get_data_addr(cub->img->xpm_to_img[i],
			&cub->game->bits_per_pixels5, &cub->game->size_line5,
			&cub->game->endian5);
	}
	else if (i > 3 && i < 5)
		return (display_textures5(cub, res_x, res_y, i));
	return (1);
}

static int		display_textures3(t_cub3d *cub, int res_x, int res_y, int i)
{
	if (i == 2)
	{
		if (!(cub->img->xpm_to_img[i] =
		mlx_xpm_file_to_image(cub->game->mlx_ptr, cub->map->south_texture,
		&res_x, &res_y)))
		{
			cub->img->size_error = 2;
			return (0);
		}
		else
			cub->img->data_textures[i] =
			(int*)mlx_get_data_addr(cub->img->xpm_to_img[i],
			&cub->game->bits_per_pixels4, &cub->game->size_line4,
			&cub->game->endian4);
	}
	else if (i > 2 && i < 5)
		return (display_textures4(cub, res_x, res_y, i));
	return (1);
}

static int		display_textures2(t_cub3d *cub, int res_x, int res_y, int i)
{
	if (i == 1)
	{
		if (!(cub->img->xpm_to_img[i] =
		mlx_xpm_file_to_image(cub->game->mlx_ptr, cub->map->west_texture,
		&res_x, &res_y)))
		{
			cub->img->size_error = 1;
			return (0);
		}
		else
			cub->img->data_textures[i] =
			(int*)mlx_get_data_addr(cub->img->xpm_to_img[i],
			&cub->game->bits_per_pixels3, &cub->game->size_line3,
			&cub->game->endian3);
	}
	else if (i >= 1 && i < 5)
		return (display_textures3(cub, res_x, res_y, i));
	return (1);
}

int				display_textures(t_cub3d *cub, int res_x, int res_y, int i)
{
	if (i == 0)
	{
		if (!(cub->img->xpm_to_img[i] =
		mlx_xpm_file_to_image(cub->game->mlx_ptr, cub->map->east_texture,
		&res_x, &res_y)))
		{
			cub->img->size_error = 0;
			return (0);
		}
		else
			cub->img->data_textures[i] =
			(int*)mlx_get_data_addr(cub->img->xpm_to_img[i],
			&cub->game->bits_per_pixels2, &cub->game->size_line2,
			&cub->game->endian2);
	}
	else if (i >= 1 && i < 5)
		return (display_textures2(cub, res_x, res_y, i));
	return (1);
}
