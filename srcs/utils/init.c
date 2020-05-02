/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 20:11:09 by loamar            #+#    #+#             */
/*   Updated: 2020/05/02 16:19:51 by lorenzoamar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void 	init_map(t_map *map)
{
	map->beta_res_y = NULL;
	map->beta_res_x = NULL;
	map->res_y = 0;
	map->res_x = 0;
	map->size = 0;
	map->size2 = 0;
	map->size_space = 0;
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->west_texture = NULL;
	map->east_texture = NULL;
	map->sprite_texture = NULL;
	map->ceiling_color = NULL;
	map->floor_color = NULL;
	map->ticket = 0;
	map->width_map = 0;
	map->heigh_map = 0;
	map->check = 0;
	map->check_pos = 0;
	map->check_space = 0;
	map->size_x = 0;
	map->size_y = 0;
	map->pos_x = 0;
	map->pos_y = 0;
	map->error = 0;
	map->nb_sprites = 0;
}

int	 	init_player(t_player *player, t_map *map)
{
	player->move_faster = 0;
	player->move_fly = 0;
    player->time = 0;
    player->oldtime = 0;
	player->move_s = 0;
	player->move_b = 0;
	player->move_l = 0;
	player->squat = 0;
	player->bug_empty = 0;
	player->rotate_l = 0;
	player->move_r = 0;
	player->rotate_r = 0;
	player->move_speed = 0;
	if (!(player->tex_x = (int *)malloc(sizeof(int) * (map->res_x))))
		return (0);
  if (!(player->distances = (float *)malloc(sizeof(float) * (map->res_x))))
      return (0);
  if (!(player->sides = (int *)malloc(sizeof(int) * (map->res_x))))
      return (0);
  if (!(player->hit_wall_x = (float *)malloc(sizeof(float) * (map->res_x))))
      return (0);
  if (!(player->hit_sprite_x = (float *)malloc(sizeof(float) * (map->res_x))))
      return (0);
	return (1);
}

// int	 	init_sprite(t_sprite *sprite)
// {
// 	sprite->pos_x = 0;
// 	sprite->pos_y = 0;
//
// }

t_cub3d 	*malloc_cub(t_cub3d *cub)
{
	if (!(cub = (t_cub3d*)malloc(sizeof(t_cub3d))))
		return (0);
	// if (!((cub = (t_cub3d*)malloc(sizeof(t_cub3d)))
	// || (cub->map = (t_map*)malloc(sizeof(t_map)))
	// || (cub->player = (t_player*)malloc(sizeof(t_player)))
	// || (cub->game = (t_application*)malloc(sizeof(t_application)))
	// || (cub->img = (t_draw*)malloc(sizeof(t_draw)))
	// || (cub->sprites = (t_sprite*)malloc(sizeof(t_sprite)))))
	// 	return (0);
	// else
	// {
		// cub->map = NULL;
		// init_map(cub->map);
		// cub->player = NULL;
		// init_player(cub->player, cub->map);
		// cub->game = NULL;
		// cub->img = NULL;
		// cub->sprites = NULL;
	// }
	// if (cub == NULL || !cub)
	// 	return (NULL);
	return (cub);
}

t_map   *malloc_map(t_map *map)
{
	map = (t_map*)malloc(sizeof(t_map));
	if (map == NULL || !map)
		return (NULL);
	init_map(map);
	return (map);
}

t_sprite   *malloc_sprite(t_sprite *sprite)
{
	sprite = (t_sprite*)malloc(sizeof(t_sprite));
	if (sprite == NULL || !sprite)
		return (NULL);
	// init_sprite(sprite);
	return (sprite);
}

t_application   *malloc_application(t_application *app)
{
    app = (t_application*)malloc(sizeof(t_application));
    if (app == NULL || !app)
    	return (NULL);
    return (app);
}

t_draw		*malloc_image(t_draw *img)
{
	img = (t_draw*)malloc(sizeof(t_draw));
	if (img == NULL || !img)
		return (NULL);
	return (img);
}

t_player   *malloc_player(t_player *player)
{
    player = (t_player*)malloc(sizeof(t_player));
    if (player == NULL || !player)
    	return (NULL);
    return (player);
}
