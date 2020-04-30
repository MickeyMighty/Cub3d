/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:45:06 by loamar            #+#    #+#             */
/*   Updated: 2020/04/30 16:58:13 by lorenzoamar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int     check_map_param(char *str_cub, int index)
{
    // && (str_cub[index - 1] == '\n' || str_cub[index - 1] == ' ')
    // && (str_cub[index + 1] == ' '))
    //////////////////////////////////////////
    // && (str_cub[index - 1] == '\n' || str_cub[index - 1] == ' ')
    // && (str_cub[index + 2] == ' '))
    if (str_cub[index] == 'S' || str_cub[index] == 'F' \
    || str_cub[index] == 'C' || str_cub[index] == 'R') \
        return (1);
    else if ((str_cub[index] == 'N' && str_cub[index + 1] == 'O') \
    || (str_cub[index] == 'S' && str_cub[index + 1] == 'O') \
    || (str_cub[index] == 'W' && str_cub[index + 1] == 'E') \
    || (str_cub[index] == 'E' && str_cub[index + 1] == 'A'))
        return (1);
    else
        return (0);
}

int 	ft_get_my_ticket(t_map *map, char *str_cub, int index)
{
    int     pos;

    pos = 0;
    map->ticket = 0;
	if (str_cub[index] == 'R')
		map->ticket = R;
	else if (str_cub[index] == 'N' && str_cub[index + 1] == 'O')
		map->ticket = NO;
	else if (str_cub[index] == 'S' && str_cub[index + 1] == 'O')
		map->ticket = SO;
	else if (str_cub[index] == 'W' && str_cub[index + 1] == 'E')
		map->ticket = WE;
	else if (str_cub[index] == 'E' && str_cub[index + 1] == 'A')
		map->ticket = EA;
	else if (str_cub[index] == 'S')
		map->ticket = S;
	else if (str_cub[index] == 'F')
		map->ticket = F;
	else if (str_cub[index] == 'C')
		map->ticket = C;
    if (map->ticket == NO || map->ticket == SO || map->ticket == WE
    || map->ticket == EA)
        pos = 2;
    else if (map->ticket == R || map->ticket == S || map->ticket == F
    || map->ticket == C)
        pos = 1;
    return (pos);
}


void 	get_map_param(t_map *map, char *str_cub, int index)
{
  if (map->size == 0)
      return ;
	if (map->ticket == R)
	{
		map->beta_res_x = ft_substr(str_cub, index, map->size);
        index += map->size + map->size_space - 1;
        map->beta_res_y = ft_substr(str_cub, index, map->size2);
	}
    else if (map->ticket == NO)
        map->north_texture = ft_substr(str_cub, index, map->size - 1);
    else if (map->ticket == SO)
        map->south_texture = ft_substr(str_cub, index, map->size - 1);
    else if (map->ticket == WE)
        map->west_texture = ft_substr(str_cub, index, map->size - 1);
    else if (map->ticket == EA)
        map->east_texture = ft_substr(str_cub, index, map->size - 1);
    else if (map->ticket == S)
        map->sprite_texture = ft_substr(str_cub, index, map->size - 1);
    else if (map->ticket == F)
        map->floor_color = ft_substr(str_cub, index, map->size - 1);
    else if (map->ticket == C)
        map->ceiling_color = ft_substr(str_cub, index, map->size - 1);
}

int     ft_nowhitespace(char *str, int index, t_map *map)
{
    int     check;

    check = 0;
    map->error = 0;
    while (str[index] == ' ' || str[index] == '\n')
    {
        if (str[index] == '\n')
            map->error = 1;
        check++;
        index++;
    }
    return (check);
}

int     data_check(t_map *map)
{
    // if (map->beta_res_x && map->beta_res_y
        // && map->north_texture && map->south_texture
        // && map->west_texture && map->east_texture
        // && map->ceiling_color && map->floor_color
        // && map->sprite_texture)
    if (map->beta_res_x == NULL || map->beta_res_y == NULL
    || map->north_texture == NULL || map->south_texture == NULL
    || map->west_texture == NULL || map->east_texture == NULL
    || map->ceiling_color == NULL || map->floor_color == NULL
    || map->sprite_texture == NULL)
        return (0);
    else
        return (1);
}
