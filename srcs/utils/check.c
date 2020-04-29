/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:51:34 by loamar            #+#    #+#             */
/*   Updated: 2020/03/11 22:48:15 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int     check_arg(int argc, char **argv)
{
    if (argc == 0 || argc > 3)
        return (0);
    else if ((ft_strncmp("-save", argv[1], 5) == 0)
    && str_end_check(argv[2], ".cub") != NULL && argc == 3)
        return (2);
    // if (!str_end_check(argv[1], ".cub"))
    //     return (0);
    else if (str_end_check(argv[1], ".cub") && argc == 2)
        return (1);
    else
        return (0);
}
// static int		fill_map(t_map *map, char *str_cub, int index)
// {
// 	// printf("before str_cub[index] == %c \n", str_cub[index]);
// 	index += ft_nowhitespace(str_cub, index);
// 	// printf("after str_cub[index] == %c \n", str_cub[index]);
//
// 	while (str_cub[index] != ' ')
// 	{
// 		// printf("poet\n");
// 		if (check_map_param(str_cub, index) == 1)
// 		{
// 			// printf("poet1\n");
// 			index += ft_get_my_ticket(map, str_cub, index);
// 			// ft_get_ticket que faire si il n y a pas de bon flag ?? genre jefopvbpvnvoibeove.
// 			// printf("poet2\n");
// 			index += ft_nowhitespace(str_cub, index);
// 			// if ((str_cub, index) == 1)
// 			// {
// 			// 	// A CHANGER
// 			// 	return (0);
// 			// }
// 			// else
// 			// {
// 			// printf("poet3\n");
// 			ft_find_size(map, str_cub, index);
// 			// printf("poet4\n");
// 			get_map_param(map, str_cub, index);
// 			// printf("poet5\n");
// 			if (map->ticket != R)
// 				map->size2 = 0;
// 			// printf("poet6\n");
// 			// printf("map->size = %d\nmap->size_space = %d\nmap->size2 = %d\n", map->size, map->size_space, map->size2);
// 			// printf("before index = %d\n", index);
// 			// printf("str_cub[index] == %c \n", str_cub[index]);
// 			index += (map->size + map->size_space + map->size2 - 1);
// 			index += ft_nowhitespace(str_cub, index);
// 			// printf("after bis index = %d\n", index);
// 			// printf("poet7\n");
// 			// printf("str_cub[index] == %c \n", str_cub[index]);
// 			return (index);
// 			// }
// 		}
// 		// printf("poet8\n");
// 		index++;
// 	}
// 	// printf("fail\n");
// 	// printf("str_cub[index] == %c \n", str_cub[index]);
// 	return (index);
// }
