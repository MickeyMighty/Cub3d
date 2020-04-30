/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 06:09:18 by loamar            #+#    #+#             */
/*   Updated: 2020/04/30 16:41:22 by lorenzoamar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


static int flood_fill(t_cub3d *cub, int pos_x, int pos_y, char target, char nb)
{
	if (pos_y >= cub->map->size_y || pos_y < 0)
        ft_error(cub, "Wrong map 2.\n");
  else if (pos_x >= cub->map->size_x[pos_y] || pos_x < 0)
        ft_error(cub, "Wrong map 1.\n");
	else if (cub->map->map_beta[pos_y][pos_x] == '1'
    || cub->map->map_beta[pos_y][pos_x] == nb)
        return (1);
    else if (ft_is_map(cub->map->map_beta[pos_y][pos_x]) == 2
    && pos_y != cub->map->check_pos_y && pos_x != cub->map->check_pos_x)
        return (0);
    else if (((cub->map->map_beta[pos_y][pos_x] == 'N')
    || (cub->map->map_beta[pos_y][pos_x] == 'S')
    || (cub->map->map_beta[pos_y][pos_x] == 'E')
    || (cub->map->map_beta[pos_y][pos_x] == 'W'))
    && (pos_y != cub->map->check_pos_y) && (pos_x != cub->map->check_pos_x))
        cub->map->ticket = 1;
    if ((cub->map->map_beta[pos_y][pos_x] != target
    || cub->map->map_beta[pos_y][pos_x] != nb
    || cub->map->map_beta[pos_y][pos_x] != '2')
    && cub->map->ticket == 1)
        return (0);
    else
    {
        if (cub->map->map_beta[pos_y][pos_x] == target)
            cub->map->map_beta[pos_y][pos_x] = nb;
        flood_fill(map, pos_x + 1, pos_y, target, nb);
        flood_fill(map, pos_x - 1, pos_y, target, nb);
        flood_fill(map, pos_x, pos_y + 1, target, nb);
        flood_fill(map, pos_x, pos_y - 1, target, nb);
    }
    return (1);
}

int	check_map(t_cub3d *cub)
{
    int     pos_x;
    int     pos_y;

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
    if (flood_fill(cub->map, pos_x, pos_y, '0', '9') == 0)
        return (0)
    if (flood_fill(cub->map, pos_x, pos_y, '9', '0') == 0)
        return (0);
    return (1);
}
