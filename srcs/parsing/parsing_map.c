/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 10:57:14 by loamar            #+#    #+#             */
/*   Updated: 2020/06/16 02:33:34 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int		get_line2(t_cub3d *cub, int index, int fill)
{
	if (cub->map->map_beta[index][fill] == ' ')
		return (4);
	else if (cub->map->map_beta[index][fill] == '\n')
		cub->map->heigh_map++;
	else if (cub->map->map_beta[index][fill] == '1')
		return (1);
	else if (cub->map->map_beta[index][fill] == '2')
	{
		cub->map->nb_sprites++;
		return (2);
	}
	else if (cub->map->map_beta[index][fill] == '0')
		return (0);
	else if (ft_ispos(cub->map->map_beta[index][fill]) == 1)
	{
		if (cub->map->check == 1)
			return (5);
		get_pos(cub, cub->map->map_beta[index][fill]);
		cub->player->pos_x = (double)fill + 0.5;
		cub->player->pos_y = (double)index + 0.5;
		cub->map->check = 1;
	}
	return (0);
}

static int		*get_line(t_cub3d *cub, int index)
{
	int		*line;
	int		fill;

	cub->map->check_line = 0;
	fill = 0;
	if (!(line = (int*)malloc(sizeof(int) *
	ft_strlen(cub->map->map_beta[index]))))
		return (0);
	while (fill < (int)ft_strlen(cub->map->map_beta[index]))
	{
		line[fill] = get_line2(cub, index, fill);
		if (line[fill] == 5)
			return (0);
		fill++;
	}
	return (line);
}

int				parsing_map2(t_cub3d *cub, char *str_cub)
{
	if (check_map_beta(cub->map, str_cub) == 0)
		return (0);
	if (!(cub->map->map_beta = ft_split(str_cub, '\n')))
		return (0);
	while (cub->map->size_y < cub->map->heigh_map)
	{
		if (cub->map->size_x_max <
				(int)ft_strlen(cub->map->map_beta[cub->map->size_y]))
			cub->map->size_x_max =
				(int)ft_strlen(cub->map->map_beta[cub->map->size_y]);
		cub->map->size_y++;
	}
	if (!(cub->map->size_x = (int*)malloc(sizeof(int) * cub->map->size_y)))
		return (0);
	cub->map->heigh_map = 0;
	while (cub->map->heigh_map < cub->map->size_y)
	{
		cub->map->size_x[cub->map->heigh_map] =
			(int)ft_strlen(cub->map->map_beta[cub->map->heigh_map]);
		cub->map->heigh_map++;
	}
	return (1);
}

int				parsing_map(t_cub3d *cub)
{
	int		line_beta;

	if (!(cub->map->map = (int**)malloc(sizeof(int*) * (cub->map->size_y))))
		return (0);
	line_beta = 0;
	while (line_beta < cub->map->size_y)
	{
		cub->map->map[line_beta] = get_line(cub, line_beta);
		line_beta++;
	}
	if (cub->player->pos_x == 0 || cub->player->pos_y == 0)
		return (0);
	if (!(cub->map->sprite_order = (int*)malloc(sizeof(int) *
	cub->map->nb_sprites + 1)))
		return (0);
	if (!(cub->map->sprite_distance = (float*)malloc(sizeof(int) *
	cub->map->nb_sprites + 1)))
		return (0);
	if (check_map(cub) == 0)
		return (0);
	free_split(cub->map->map_beta);
	return (1);
}
