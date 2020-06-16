/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 06:09:18 by loamar            #+#    #+#             */
/*   Updated: 2020/06/14 16:51:21 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int		flood_fill(t_cub3d *cub, int pos_x, int pos_y)
{
	if ((pos_y >= cub->map->size_y || pos_y < 0)
	|| (pos_x >= cub->map->size_x[pos_y] || pos_x < 0)
	|| cub->map->map[pos_y][pos_x] == 4)
		ft_error(cub, "Wrong map.\n", 4);
	else if (cub->map->map[pos_y][pos_x] == 1
	|| cub->map->map[pos_y][pos_x] == cub->map->nb
	|| (cub->map->map[pos_y][pos_x] != cub->map->target
	&& cub->map->map[pos_y][pos_x] != 2))
		return (1);
	else
	{
		if (cub->map->map[pos_y][pos_x] != 2)
			cub->map->map[pos_y][pos_x] = cub->map->nb;
		flood_fill(cub, pos_x + 1, pos_y);
		flood_fill(cub, pos_x - 1, pos_y);
		flood_fill(cub, pos_x, pos_y + 1);
		flood_fill(cub, pos_x, pos_y - 1);
	}
	return (1);
}

int				check_map(t_cub3d *cub)
{
	int		pos_x;
	int		pos_y;

	cub->map->ticket = 0;
	pos_x = (int)(cub->player->pos_x - 0.5);
	pos_y = (int)(cub->player->pos_y - 0.5);
	cub->map->check_pos_x = pos_x;
	cub->map->check_pos_y = pos_y;
	if (cub->map->size_y < 3 || cub->map->size_x_max < 3)
		return (0);
	if (pos_y >= cub->map->size_y || pos_y < 0)
		return (0);
	if (pos_x >= cub->map->size_x[pos_y] || pos_x < 0)
		return (0);
	cub->map->target = 0;
	cub->map->nb = 9;
	if (flood_fill(cub, pos_x, pos_y) == 0)
		return (0);
	cub->map->target = 9;
	cub->map->nb = 0;
	if (flood_fill(cub, pos_x, pos_y) == 0)
		return (0);
	return (1);
}

int				size_of_ticket(t_map *map)
{
	if (map->ticket == NO || map->ticket == SO || map->ticket == WE
			|| map->ticket == EA)
		return (2);
	else if (map->ticket == R || map->ticket == S || map->ticket == F
			|| map->ticket == C)
		return (1);
	else
		return (0);
}

void			size_and_param(t_map *map, char *str_cub, int index)
{
	ft_find_size(map, str_cub, index);
	get_map_param(map, str_cub, index);
	if (map->ticket != R)
		map->size2 = 0;
}

int				check_loop(t_map *map)
{
	if (map->beta_res_x != NULL && map->beta_res_y != NULL
	&& map->parsing_check == 0)
		return (1);
	if (map->north_texture != NULL && map->parsing_check == 1)
		return (2);
	if (map->south_texture != NULL && map->parsing_check == 2)
		return (3);
	if (map->west_texture != NULL && map->parsing_check == 3)
		return (4);
	if (map->east_texture != NULL && map->parsing_check == 4)
		return (5);
	if (map->sprite_texture != NULL && map->parsing_check == 5)
		return (6);
	if (map->floor_color != NULL && map->parsing_check == 6)
		return (7);
	if (map->ceiling_color != NULL && map->parsing_check == 7)
		return (8);
	if (map->beta_res_x != NULL && map->beta_res_y != NULL
	&& map->north_texture != NULL && map->south_texture != NULL
	&& map->west_texture != NULL && map->east_texture != NULL
	&& map->ceiling_color != NULL && map->floor_color != NULL
	&& map->sprite_texture != NULL && map->parsing_check == 8)
		return (9);
	return (10);
}
