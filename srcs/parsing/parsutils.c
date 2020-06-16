/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 22:18:52 by loamar            #+#    #+#             */
/*   Updated: 2020/06/04 20:14:20 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char			*str_end_check(char *str, char *end)
{
	int		index;
	int		index2;

	index = 0;
	index2 = 0;
	if (!str)
		str = NULL;
	while (str[index])
	{
		index++;
		while (str[index] == end[index2])
		{
			if (str[index] != end[index2])
				return (NULL);
			if (str[index] == '\0' && end[index2] == '\0')
				return (str);
			index++;
			index2++;
		}
	}
	return (NULL);
}

static int		ft_count_index(t_map *map, char *str_cub, int index)
{
	int		i;

	i = 0;
	map->size = 1;
	map->size2 = 1;
	map->size_space = 0;
	while (str_cub[index] != '\n' && str_cub[index] != ' ')
	{
		map->size++;
		index++;
		i++;
	}
	return (i);
}

void			ft_find_size(t_map *map, char *str_cub, int index)
{
	index += ft_count_index(map, str_cub, index);
	if (str_cub[index] == ' ' && map->ticket == R)
	{
		while (str_cub[index] == ' ')
		{
			index++;
			map->size_space++;
		}
		if (str_cub[index] == '\n')
		{
			map->size = 0;
			return ;
		}
		else
		{
			while (str_cub[index] != '\n' && str_cub[index] != ' ')
			{
				map->size2++;
				index++;
			}
		}
	}
}

int				ft_is_map(char c)
{
	if ((c >= '0' && c <= '2'))
		return (1);
	else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (2);
	else if (c == ' ')
		return (3);
	else if (c == '\n')
		return (4);
	else
		return (0);
}

int				check_parsing_cub(t_cub3d *cub, int check, int index,
	char *str_cub)
{
	cub->map->res_x = ft_atoi(cub->map->beta_res_x);
	cub->map->res_y = ft_atoi(cub->map->beta_res_y);
	if (color(cub->map->ceiling_color, &(cub->map->ceiling_addr)) == 0)
		return (0);
	if (color(cub->map->floor_color, &(cub->map->floor_addr)) == 0)
		return (0);
	if (cub->map->res_x > 2560)
		cub->map->res_x = 2560;
	if (cub->map->res_y > 1440)
		cub->map->res_y = 1440;
	check = index;
	if (str_cub[index] == '\n')
		index++;
	while (str_cub[index] == ' ')
	{
		index++;
		while (str_cub[index] == '\n')
		{
			check = index;
			index++;
		}
	}
	return (check);
}
