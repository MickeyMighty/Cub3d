/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:13:02 by loamar            #+#    #+#             */
/*   Updated: 2020/06/15 21:10:53 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		draw_floor_ceiling(t_cub3d *cub, int check_x, int check_y)
{
	cub->img->img_buf[check_y * cub->map->res_x + check_x] =
	cub->map->ceiling_addr;
	cub->img->img_buf[ft_min(cub->map->res_y - check_y, cub->map->res_y) *
	cub->map->res_x + check_x] = cub->map->floor_addr;
}

static void		draw_wall(t_cub3d *cub, int check_x, int check_y, int wall_size)
{
	int			tex_y;

	if (cub->player->sides[check_x] == 0 || cub->player->sides[check_x] == 1)
		tex_y = (((float)check_y * 2. - (float)cub->map->res_y +
		(float)wall_size) * (float)(64 / 2) / (float)wall_size);
	else
		tex_y = (((float)check_y * 2. - (float)cub->map->res_y +
		(float)wall_size) * (float)(64 / 2) / (float)wall_size);
	cub->img->img_buf[check_y * cub->map->res_x + check_x] =
	cub->img->data_textures[cub->player->sides[check_x]][(int)tex_y *
	64 + cub->player->tex_x[check_x]];
}

int				draw_buffer(t_cub3d *cub)
{
	int			wall_size;
	int			wall_start;
	int			wall_end;
	int			check_x;
	int			check_y;

	check_x = 0;
	while (check_x < cub->map->res_x - 1)
	{
		wall_size = abs((int)(cub->map->res_y /
		cub->player->distances[check_x]));
		wall_start = ft_max((int)(cub->map->res_y / 2 - wall_size / 2), 0);
		wall_end = ft_min((int)(cub->map->res_y / 2 + wall_size / 2),
		cub->map->res_y);
		if (wall_start < 0)
			wall_start = 0;
		check_y = 0;
		while (check_y++ < (int)wall_start)
			draw_floor_ceiling(cub, check_x, check_y);
		while (check_y < (int)wall_end)
			draw_wall(cub, check_x, check_y++, wall_size);
		check_x++;
	}
	check_y = 0;
	return (1);
}

void			draw_sprites(t_cub3d *cub)
{
	t_sprite	*sprite2;
	float		inverse_coef;

	sort_sprites(cub);
	sprite2 = cub->sprites;
	inverse_coef = 1.0 / (cub->player->plane_x * cub->player->dir_y -
	cub->player->plane_y * cub->player->dir_x);
	while (sprite2)
	{
		if (sprite2->order > 0)
		{
			set_sprite(cub, sprite2, inverse_coef);
			draw_sprite(cub, sprite2);
			sprite2->order = 0;
		}
		sprite2 = sprite2->next;
	}
}
