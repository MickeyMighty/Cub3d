/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 20:11:09 by loamar            #+#    #+#             */
/*   Updated: 2020/06/15 19:11:54 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		init_map2(t_map *map)
{
	map->beta_res_x = 0;
	map->beta_res_y = 0;
	map->north_texture = 0;
	map->south_texture = 0;
	map->west_texture = 0;
	map->east_texture = 0;
	map->sprite_texture = 0;
	map->ceiling_color = 0;
	map->floor_color = 0;
	map->parsing_check = 0;
	map->sprite_order = (int*)0;
	map->sprite_distance = (float*)0;
	map->map = (int**)0;
	map->map_beta = (char**)0;
	map->check_pos_x = 0;
	map->pos_y = 0;
	map->check_pos_y = 0;
	map->error = 0;
	map->nb_sprites = 0;
}

void			init_map(t_map *map)
{
	init_map2(map);
	map->res_y = 0;
	map->res_x = 0;
	map->size = 0;
	map->size2 = 0;
	map->size_space = 0;
	map->ticket = 0;
	map->width_map = 0;
	map->heigh_map = 0;
	map->check = 0;
	map->check_pos = 0;
	map->check_space = 0;
	map->check_line = 0;
	map->size_x = (int*)0;
	map->size_x_max = 0;
	map->size_y = 0;
	map->nb = 0;
	map->target = 0;
	map->pos_x = 0;
}

static void		init_game2(t_cub3d *cub)
{
	cub->game->endian = 0;
	cub->game->endian2 = 0;
	cub->game->endian3 = 0;
	cub->game->endian4 = 0;
	cub->game->endian5 = 0;
	cub->game->endian6 = 0;
	cub->game->pixels = 0;
	cub->game->pixels2 = 0;
	cub->game->pixels3 = 0;
	cub->game->pixels4 = 0;
	cub->game->pixels5 = 0;
	cub->game->pixels6 = 0;
	cub->game->bitpx = 0;
	cub->game->frametime = 0;
}

static void		init_game(t_cub3d *cub)
{
	init_game2(cub);
	cub->game->size_x = 0;
	cub->game->size_y = 0;
	cub->game->bits_per_pixels = 0;
	cub->game->bits_per_pixels2 = 0;
	cub->game->bits_per_pixels3 = 0;
	cub->game->bits_per_pixels4 = 0;
	cub->game->bits_per_pixels5 = 0;
	cub->game->bits_per_pixels6 = 0;
	cub->game->size_line = 0;
	cub->game->size_line2 = 0;
	cub->game->size_line3 = 0;
	cub->game->size_line4 = 0;
	cub->game->size_line5 = 0;
	cub->game->size_line6 = 0;
	cub->game->mlx_ptr = NULL;
	cub->game->win_ptr = NULL;
	cub->game->img_ptr = NULL;
	cub->game->save = 0;
}

t_cub3d			*malloc_cub(t_cub3d *cub)
{
	if (!(cub = (t_cub3d*)malloc(sizeof(t_cub3d))))
		return (NULL);
	if (!(cub->player = (t_player*)malloc(sizeof(t_player))))
		return (NULL);
	if (!(cub->game = (t_application*)malloc(sizeof(t_application))))
		return (NULL);
	if (!(cub->map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	if (!(cub->img = (t_draw*)malloc(sizeof(t_draw))))
		return (NULL);
	if (!(cub->sprites = (t_sprite*)malloc(sizeof(t_sprite))))
		return (NULL);
	init_map(cub->map);
	init_img(cub->img);
	init_game(cub);
	init_sprite(cub->sprites);
	cub->player->pos_x = 0;
	cub->player->pos_y = 0;
	cub->player->dir_x = 0;
	cub->player->dir_y = 0;
	cub->player->plane_x = 0;
	cub->player->plane_y = 0;
	cub->img->size_error = 0;
	return (cub);
}
