/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:26:59 by loamar            #+#    #+#             */
/*   Updated: 2020/06/08 21:26:50 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		get_distances_no_so(t_player *player, int column, int step_x,
	int side)
{
	player->distances[column] = fabs((player->map_x - player->ray_pos_x +
	(1 - step_x) / 2) / player->raydir_x);
	player->hit_wall_x[column] = (float)player->ray_pos_y +
	(((float)player->map_x - player->ray_pos_x + (1. - (float)step_x) / 2.) /
	player->raydir_x) * player->raydir_y;
	player->hit_wall_x[column] -= (int)player->hit_wall_x[column];
	player->tex_x[column] = (int)(player->hit_wall_x[column] * 64);
	player->sides[column] = side;
	if (player->raydir_x > 0)
	{
		player->tex_x[column] = 64 - player->tex_x[column] - 1;
		player->sides[column] = 1;
	}
}

static void		get_distances_we_ea(t_player *player, int column, int step_y,
	int side)
{
	player->distances[column] = fabs((player->map_y - player->ray_pos_y +
	(1 - step_y) / 2) / player->raydir_y);
	player->sides[column] = side;
	player->hit_wall_x[column] = (float)player->ray_pos_x +
	(((float)player->map_y - player->ray_pos_y + (1. - (float)step_y) / 2.) /
	player->raydir_y) * player->raydir_x;
	player->hit_wall_x[column] -= (int)player->hit_wall_x[column];
	player->tex_x[column] = (int)(player->hit_wall_x[column] * 64);
	if (player->raydir_y < 0)
	{
		player->tex_x[column] = 64 - player->tex_x[column] - 1;
		player->sides[column] = 3;
	}
}

static void		set_dda_value(t_player *player, int *step_x, int *step_y)
{
	if (player->raydir_x < 0)
	{
		*step_x = -1;
		player->sidedist_x = (player->ray_pos_x - player->map_x) *
		player->deltadist_x;
	}
	else
	{
		*step_x = 1;
		player->sidedist_x = (player->map_x + 1.0 - player->ray_pos_x) *
		player->deltadist_x;
	}
	if (player->raydir_y < 0)
	{
		*step_y = -1;
		player->sidedist_y = (player->ray_pos_y - player->map_y) *
		player->deltadist_y;
	}
	else
	{
		*step_y = 1;
		player->sidedist_y = (player->map_y + 1.0 - player->ray_pos_y) *
		player->deltadist_y;
	}
}

static int		algo_dda(t_cub3d *cub, int column)
{
	int		check;
	int		hit;
	int		side;

	set_dda_value(cub->player, &cub->player->step_x, &cub->player->step_y);
	hit = 0;
	side = 0;
	while (hit == 0)
	{
		check = cub->player->sidedist_x < cub->player->sidedist_y;
		cub->player->sidedist_x += check ? cub->player->deltadist_x : 0.0;
		cub->player->sidedist_y += check ? 0.0 : cub->player->deltadist_y;
		cub->player->map_x += check ? cub->player->step_x : 0;
		cub->player->map_y += check ? 0 : cub->player->step_y;
		side = check ? 0 : 2;
		if (cub->map->map[cub->player->map_y][cub->player->map_x] == 1)
			hit = 1;
		else if (cub->map->map[cub->player->map_y][cub->player->map_x] == 2)
			get_sprites(cub, column);
	}
	if (side == 0)
		get_distances_no_so(cub->player, column, cub->player->step_x, side);
	else
		get_distances_we_ea(cub->player, column, cub->player->step_y, side);
	return (1);
}

int				ray_casting(t_cub3d *cub)
{
	int		column;

	column = 0;
	while (column < cub->map->res_x)
	{
		cub->player->camera_x = ((2.0 * ((float)column /
						(float)cub->map->res_x)) - 1.0);
		cub->player->ray_pos_x = cub->player->pos_x;
		cub->player->ray_pos_y = cub->player->pos_y;
		cub->player->raydir_x = (cub->player->dir_x + cub->player->plane_x
				* cub->player->camera_x);
		cub->player->raydir_y = (cub->player->dir_y + cub->player->plane_y
				* cub->player->camera_x);
		cub->player->map_x = (int)cub->player->ray_pos_x;
		cub->player->map_y = (int)cub->player->ray_pos_y;
		cub->player->deltadist_x = sqrt(1 + (cub->player->raydir_y *
		cub->player->raydir_y) / (cub->player->raydir_x *
		cub->player->raydir_x));
		cub->player->deltadist_y = sqrt(1 + (cub->player->raydir_x *
		cub->player->raydir_x) / (cub->player->raydir_y *
		cub->player->raydir_y));
		algo_dda(cub, column++);
	}
	return (1);
}
