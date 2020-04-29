/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 06:09:18 by loamar            #+#    #+#             */
/*   Updated: 2020/03/13 07:29:19 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


static int flood_fill(t_map *map, int pos_x, int pos_y, char target, char nb)
{
    // printf("\n\ndebut\n\n");
    // printf("floody2\n");
    // printf("floody3\n");
    printf("\n=========TOP=============\n");

    int     i;
    int     j;

    i = 0;
    while (i < map->size_y)
    {
        j = 0;
        while (map->map_beta[i][j] != '\0')
        {
            printf("%c", map->map_beta[pos_y][pos_x]);
            j++;
        }
        printf("\n");
        i++;
    }
    //////////////////////
    printf("\n=========BOT=============\n");
    printf("floody\n");
    printf("pos_y = %d\n", pos_y);
    printf("pos_x = %d\n", pos_x);
    printf("check_pos_y = %d\n", map->check_pos_y);
    printf("check_pos_x = %d\n", map->check_pos_x);
    printf("size_x = %d\n", map->size_x[pos_y]);
    printf("size_y = %d\n", map->size_y);
    // printf("map->map_beta[pos_y][pos_x] = %c\n", map->map_beta[pos_y][pos_x]);
	if (pos_y >= map->size_y || pos_y < 0)
    {
        printf("1\n");
        return (0);
    }
    else if (pos_x >= map->size_x[pos_y] || pos_x < 0)
    {

        printf("2\n");
        return (0);
    }
	else if (map->map_beta[pos_y][pos_x] == '1'
    || map->map_beta[pos_y][pos_x] == nb)
    {

        printf("3\n");
        return (1);
    }
    else if (ft_is_map(map->map_beta[pos_y][pos_x]) == 2
    && pos_y != map->check_pos_y && pos_x != map->check_pos_x)
    {
        printf("4\n");
        return (0);
    }
    else if (((map->map_beta[pos_y][pos_x] == 'N')
    || (map->map_beta[pos_y][pos_x] == 'S')
    || (map->map_beta[pos_y][pos_x] == 'E')
    || (map->map_beta[pos_y][pos_x] == 'W'))
    && (pos_y != map->check_pos_y) && (pos_x != map->check_pos_x))
    {
        printf("5\n");
        map->ticket = 1;
    }
    if ((map->map_beta[pos_y][pos_x] != target
    || map->map_beta[pos_y][pos_x] != nb
    || map->map_beta[pos_y][pos_x] != '2')
    && map->ticket == 1)
    {
        // printf("5\n");

        printf("6\n");
        return (0);
    }
    else
    {
        if (map->map_beta[pos_y][pos_x] == target)
        {
            printf("7\n");
            // printf("target ok\n");
            map->map_beta[pos_y][pos_x] = nb;
        }
        printf("8\n");
        // printf("map[pos_y][pos_x] = [%d]\n", map->map[pos_y][pos_x]);
        flood_fill(map, pos_x + 1, pos_y, target, nb);
        flood_fill(map, pos_x - 1, pos_y, target, nb);
        flood_fill(map, pos_x, pos_y + 1, target, nb);
        flood_fill(map, pos_x, pos_y - 1, target, nb);
    }
    // printf("7\n");
    // printf("floody6\n");
    return (1);
    // printf("floody11\n");
}

int	check_map(t_map *map, t_player *player)
{
    int     pos_x;
    int     pos_y;

    map->ticket = 0;
    printf("\n############################\n");
    printf("youpi\n");
    pos_x = (int)(player->pos_x - 0.5);
    printf("youpi2\n");
    pos_y = (int)(player->pos_y - 0.5);
    map->check_pos_x = pos_x;
    map->check_pos_y = pos_y;
    printf("size_y = %d\n", map->size_y);
    printf("size_x[pos_y] = %d\n", map->size_x[pos_y]);
    printf("youpi3\n");
    printf("\n##############################\n");
	if (map->size_y < 3 || map->size_x_max < 3)
        return (0);
    printf("youpi4\n");
	if (pos_y >= map->size_y || pos_y < 0)
        return (0);
    printf("youpi5\n");
	if (pos_x >= map->size_x[pos_y] || pos_x < 0)
        return (0);
    printf("youpi6\n");
    if (flood_fill(map, pos_x, pos_y, '0', '9') == 0)
        return (0);

    printf("map->ticket = %d\n", map->ticket);
    printf("youpi7\n");
    if (flood_fill(map, pos_x, pos_y, '9', '0') == 0)
        return (0);
    printf("youpi8\n");
    return (1);
}
//
// int     check_map(t_map *map)
// {
//     int     check;
//     int     check2;
//
//     check = 0;
//     check2 = 0;
//     while (check < map->size_y)
//     {
//         if (map->map[check] = 1)
//         {
//
//         }
//     }
// }
