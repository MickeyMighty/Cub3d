/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 22:18:52 by loamar            #+#    #+#             */
/*   Updated: 2020/03/12 07:09:59 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*str_end_check(char *str, char *end)
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

int 	ft_ispos(char c)
{
	if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
		return (1);
	else
		return (0);
}

// static int	 	check_xpm(t_map *map, char *str_cub, int index)
// {
// 	int 	check;
// 	int 	check2;
// 	int 	check3;
// 	char 	*xpm;
//
// 	check = 0;
// 	check2 = 0;
// 	check3 = index;
// 	xpm = ".xpm";
// 	if (map->ticket != R)
// 	{
// 		while (str_cub[index] != '\n')
// 		{
// 			if (str_cub[index] == xpm[check])
// 			{
// 				check2 = index;
// 			 	while (str_cub[index] == xpm[check])
// 				{
// 					index++;
// 					check++;
// 					if (str_cub[index] != xpm[check] && str_cub[index] != ' ' && str_cub[index] != '\n')
// 						return (check);
// 				}
// 				while (index > check3 || str_cub[index] != '/')
// 					index--;
// 				if (str_cub[index] == '/')
// 				{
// 					printf("YAAAAAAAAAAA\n");
// 					check3 = index + 1;
// 				}
// 			}
// 			index++;
// 		}
// 	}
// 	return (check3);
// }

void 	ft_find_size(t_map *map, char *str_cub, int index)
{
	map->size = 1;
	map->size2 = 1;
	map->size_space = 0;
	// index = check_xpm(map, str_cub, index);
	while (str_cub[index] != '\n' && str_cub[index] != ' ')
	{
		map->size++;
		index++;
	}
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

// int 	check_line_map(char *str_cub, int index)
// {
// 	int 	check;
// 	int 	pos;
// 	int 	pos2;
//
// 	pos = 0;
// 	pos2 = 0;
// 	check = 0;
// 	while (check < 3)
// 	{
// 		if (ft_is_map(str_cub[index]) == 1)
// 		{
// 			index++;
// 			if (str_cub[index] == '1')
// 				pos2++;
// 		}
// 		else if (ft_is_map(str_cub[index]) == 2)
// 		{
// 			if (pos == 1)
// 				return (2);
// 			index++;
// 			pos = 1;
// 		}
// 		else if (str_cub[index] == ' ')
// 			index++;
// 		else if (str_cub[index] == '\n')
// 		{
// 			if ((pos2 < 3 && check == 0)
// 			|| (pos2 < 2 && (check == 1 || check == 2)))
// 				return (2);
// 			check++;
// 			index++;
// 			pos = 0;
// 		}
// 		else
// 			return (0);
// 	}
// 	return (1);
// }

int 	ft_is_map(char c)
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
