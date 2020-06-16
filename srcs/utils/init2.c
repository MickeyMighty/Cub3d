/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 16:42:19 by loamar            #+#    #+#             */
/*   Updated: 2020/06/14 16:40:28 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		init_player3(t_player *player)
{
	player->step_x = 0;
	player->step_y = 0;
	player->camera_x = 0;
	player->camera_y = 0;
	player->map_x = 0;
	player->map_y = 0;
	player->id = 0;
	player->ray_pos_x = 0;
	player->ray_pos_y = 0;
	player->side_x = 0;
	player->side_y = 0;
	player->move_speed = 0;
	player->rot_speed = 0;
	player->hit = 0;
	player->side = 0;
	player->perpwalldist = 0;
}

static void		init_player2(t_player *player)
{
	player->if_sprite = 0;
	player->olddir_x = 0;
	player->oldplane_x = 0;
	player->raydir_x = 0;
	player->raydir_y = 0;
	player->sidedist_x = 0;
	player->sidedist_y = 0;
	player->deltadist_x = 0;
	player->deltadist_y = 0;
	player->old_dir_x = 0;
	player->move_faster = 0;
	player->time = 0;
	player->oldtime = 0;
	player->move_s = 0;
	player->move_b = 0;
	player->move_l = 0;
	player->rotate_l = 0;
	player->move_r = 0;
	player->rotate_r = 0;
	player->move_speed = 0;
	init_player3(player);
}

int				init_player(t_player *player, t_map *map)
{
	player->hit_sprite_x = (float*)0;
	player->distances = (float*)0;
	player->sides = (int*)0;
	player->hit_wall_x = (float*)0;
	player->tex_x = (int*)0;
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
	init_player2(player);
	return (1);
}

void			init_img(t_draw *img)
{
	img->size_error = 0;
	img->lineheight = 0;
	img->wall_start = 0;
	img->wall_end = 0;
	img->color = 0;
	img->img_buf = (int*)0;
	img->xpm_to_img = (void**)NULL;
	img->data_textures = (int**)0;
	img->r = 0;
	img->g = 0;
	img->b = 0;
}

void			init_sprite(t_sprite *sprites)
{
	sprites->pos_x = 0;
	sprites->pos_y = 0;
	sprites->dist_x = 0;
	sprites->dist_y = 0;
	sprites->first_hit = 0;
	sprites->first_hit2 = 0;
	sprites->last_hit = 0;
	sprites->last_hit2 = 0;
	sprites->x_start = 0;
	sprites->y_start = 0;
	sprites->x_end = 0;
	sprites->y_end = 0;
	sprites->height = 0;
	sprites->width = 0;
	sprites->sprite_screen_x = 0;
	sprites->transform_x = 0;
	sprites->transform_y = 0;
	sprites->check_x = 0;
	sprites->check_y = 0;
	sprites->tex_x = 0;
	sprites->tex_y = 0;
	sprites->order = 0;
	sprites->order2 = 0;
	sprites->distance = 0;
}
