/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 17:17:55 by loamar            #+#    #+#             */
/*   Updated: 2020/06/13 15:01:02 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		check_map_beta(t_map *map, char *str_cub)
{
	int		index;

	index = 0;
	while (str_cub[index] == '\n')
		index++;
	while (str_cub[index] != '\0')
	{
		map->check = ft_is_map(str_cub[index]);
		if (map->check == 0 || map->check_pos > 1)
			return (0);
		else if (map->check == 2)
			map->check_pos++;
		else if (map->check == 4)
			map->heigh_map++;
		index++;
	}
	return (1);
}

int		ft_ispos(char c)
{
	if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
		return (1);
	else
		return (0);
}

void	get_pos_next(t_cub3d *cub, char pos)
{
	if (pos == 'E')
	{
		cub->player->plane_y = -1;
		cub->player->plane_x = 0;
		cub->player->dir_y = 0;
		cub->player->dir_x = 1;
	}
	else if (pos == 'W')
	{
		cub->player->plane_y = 1;
		cub->player->plane_x = 0;
		cub->player->dir_y = 0;
		cub->player->dir_x = -1;
	}
}

void	get_pos(t_cub3d *cub, char pos)
{
	if (pos == 'N')
	{
		cub->player->plane_y = 0;
		cub->player->plane_x = -1;
		cub->player->dir_y = -1;
		cub->player->dir_x = 0;
	}
	else if (pos == 'S')
	{
		cub->player->plane_y = 0;
		cub->player->plane_x = 1;
		cub->player->dir_y = 1;
		cub->player->dir_x = 0;
	}
	else
		get_pos_next(cub, pos);
}

int		loop_index(t_cub3d *cub, int index, char *str_cub)
{
	int		check;

	index = 0;
	check = 0;
	while (data_check(cub->map) != 1 || cub->map->parsing_check != 9)
	{
		check = index;
		index = fill_map(cub->map, str_cub, index);
		cub->map->parsing_check = check_loop(cub->map);
		if (index == check && cub->map->parsing_check == 10)
			return (0);
	}
	index = check_parsing_cub(cub, check, index, str_cub);
	return (index);
}
