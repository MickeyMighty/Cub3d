/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 22:02:39 by loamar            #+#    #+#             */
/*   Updated: 2020/06/08 14:05:31 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		move_up_down(t_player *player, t_map *map)
{
	if (player->move_s)
	{
		if (map->map[(int)player->pos_y][(int)(player->pos_x + player->dir_x *
		player->move_speed)] == 0)
			player->pos_x += (player->dir_x * player->move_speed);
		if (map->map[(int)(player->pos_y + player->dir_y * player->move_speed)]
		[(int)player->pos_x] == 0)
			player->pos_y += (player->dir_y * player->move_speed);
	}
	else if (player->move_b)
	{
		if (map->map[(int)player->pos_y][(int)(player->pos_x - player->dir_x
		* player->move_speed)] == 0)
			player->pos_x -= (player->dir_x * player->move_speed);
		if (map->map[(int)(player->pos_y - player->dir_y *
		player->move_speed)][(int)player->pos_x] == 0)
			player->pos_y -= (player->dir_y * player->move_speed);
	}
}

static void		rotate_right(t_player *player)
{
	player->old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(-player->move_speed) -
	player->dir_y * sin(-player->move_speed);
	player->dir_y = player->old_dir_x * sin(-player->move_speed) +
	player->dir_y * cos(-player->move_speed);
	player->old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(-player->move_speed) -
	player->plane_y * sin(-player->move_speed);
	player->plane_y = player->old_plane_x * sin(-player->move_speed) +
	player->plane_y * cos(-player->move_speed);
}

static void		rotate_left_right(t_player *player)
{
	player->move_speed = 0.09;
	if (player->rotate_l)
	{
		player->old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(player->move_speed) -
		player->dir_y * sin(player->move_speed);
		player->dir_y = player->old_dir_x * sin(player->move_speed) +
		player->dir_y * cos(player->move_speed);
		player->old_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(player->move_speed) -
		player->plane_y * sin(player->move_speed);
		player->plane_y = player->old_plane_x * sin(player->move_speed) +
		player->plane_y * cos(player->move_speed);
	}
	else if (player->rotate_r)
		rotate_right(player);
}

static void		move_left_right(t_player *player, t_map *map)
{
	player->move_speed = 0.09;
	if (player->move_l)
	{
		if (map->map[(int)player->pos_y]
		[(int)(player->pos_x - player->plane_x * player->move_speed)] == 0)
			player->pos_x -= (player->plane_x * player->move_speed);
		if (map->map[(int)(player->pos_y - player->plane_y *
		player->move_speed)][(int)player->pos_x] == 0)
			player->pos_y -= (player->plane_y * player->move_speed);
	}
	else if (player->move_r)
	{
		if (map->map[(int)player->pos_y]
		[(int)(player->pos_x + player->plane_x * player->move_speed)] == 0)
			player->pos_x += (player->plane_x * player->move_speed);
		if (map->map[(int)(player->pos_y + player->plane_y *
		player->move_speed)][(int)player->pos_x] == 0)
			player->pos_y += (player->plane_y * player->move_speed);
	}
}

void			move(t_player *player, t_map *map)
{
	if (player->move_faster == 1)
		player->move_speed = 0.5;
	if (player->move_faster == 0)
		player->move_speed = 0.2;
	if (player->move_s || player->move_b)
		move_up_down(player, map);
	if (player->move_l || player->move_r)
		move_left_right(player, map);
	if (player->rotate_l || player->rotate_r)
		rotate_left_right(player);
}
