/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 10:57:14 by loamar            #+#    #+#             */
/*   Updated: 2020/04/20 10:26:36 by lorenzoamar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// remplacer ' ' par '1'
// int     parsing_map(t_map *map, char *str_cub)
// {
//     ;
// }

static int     check_map_beta(t_map *map, char *str_cub)
{
    int     index;

    index = 0;
    while (str_cub[index] == '\n')
        index++;
    while (str_cub[index] != '\0')
    {
        // printf("\nstr_cub[index] => %c\n", str_cub[index]);
        map->check = ft_is_map(str_cub[index]);
        if (map->check == 0 || map->check_pos > 1)
            return (0);
        else if (map->check == 2)
            map->check_pos++;
        else if (map->check == 4)
            map->heigh_map++;
        index++;
    }
    // printf("heigh_map == %d\n", map->heigh_map);
    return (1);
}

static void     get_pos_next(t_cub3d *cub, char pos)
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

static void     get_pos(t_cub3d *cub, char pos)
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


static int     *get_line(t_cub3d *cub, int index)
{
    int     *line;
    int     fill;
    int     check;

    check = 0;
    fill = 0;
    if (!(line = (int*)malloc(sizeof(int) * ft_strlen(cub->map->map_beta[index]))))
        return (0);
    // printf("cub->map->map_beta[index][fill] => %c\n", cub->map->map_beta[index][fill]);
    while (fill < (int)ft_strlen(cub->map->map_beta[index]))
    {
        if (cub->map->map_beta[index][fill] == ' ')
            line[fill] = 0;
        else if (cub->map->map_beta[index][fill] == '\n')
            cub->map->heigh_map++;
        else if (cub->map->map_beta[index][fill] == '1')
            line[fill] = 1;
        else if (cub->map->map_beta[index][fill] == '2')
        {
            cub->map->nb_sprites++;
            line[fill] = 2;
        }
        else if (cub->map->map_beta[index][fill] == '0')
            line[fill] = 0;
        else if (ft_ispos(cub->map->map_beta[index][fill]) == 1)
        {
            if (check == 1)
                return (0);
            get_pos(cub, cub->map->map_beta[index][fill]);
            line[fill] = 0;
            // printf("player->pos_y => %f\n", player->pos_y);
            // printf("player->pos_x => %f\n", player->pos_x);
            cub->player->pos_x = (double)fill + 0.5;
            // cub->player->pos_x = (float)fill;
            cub->player->pos_y = (double)index + 0.5;
            // cub->map->map_beta[index][fill] = '0';
            // cub->player->pos_y = (float)index;
            // printf("AFTER\n");
            // printf("player->pos_y => %f\n", cub->player->pos_y);
            // printf("player->pos_x => %f\n", cub->player->pos_x);
            check = 1;
        }
        // printf("\nheigh map = %d\n", cub->map->heigh_map);
        // printf("%d", line[fill]);
        fill++;
        // printf("fill = %d\n",fill);
    }
    return (line);
}

int     parsing_map(t_cub3d *cub, char *str_cub)
{
    int     line_beta;

    if (check_map_beta(cub->map, str_cub) == 0)
        return (0);
    if (!(cub->map->map_beta = ft_split(str_cub, '\n')))
        return (0);
    while (cub->map->size_y < cub->map->heigh_map)
    {
        if (cub->map->size_x_max < (int)ft_strlen(cub->map->map_beta[cub->map->size_y]))
            cub->map->size_x_max = (int)ft_strlen(cub->map->map_beta[cub->map->size_y]);
        cub->map->size_y++;
    }
    if (!(cub->map->size_x = (int*)malloc(sizeof(int) * cub->map->size_y)))
        return (0);
    cub->map->heigh_map = 0;
    while (cub->map->heigh_map < cub->map->size_y)
    {
        cub->map->size_x[cub->map->heigh_map] = (int)ft_strlen(cub->map->map_beta[cub->map->heigh_map]);
        // printf("\ncub->map->size_x[cub->map->heigh_map] = %d\n", cub->map->size_x[cub->map->heigh_map]);
        cub->map->heigh_map++;
    }
    //FLOOD FILL
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
    if (check_map(cub) == 0)
      return (0);
    free_split(cub->map->map_beta);
    if (!(cub->map->sprite_order = (int*)malloc(sizeof(int) * cub->map->nb_sprites + 1)))
        return (0);
    if (!(cub->map->sprite_distance = (float*)malloc(sizeof(int) * cub->map->nb_sprites + 1)))
        return (0);
    // printf("yala\n");
    return (1);
}
// printf("map->size_x => %d\n", map->size_x);
// printf("map->size_y => %d\n", map->size_y);


// printf("size_y -> %d\n", map->size_y);
// printf("size_x -> %d\n", map->size_x);


// printf map sour str
// printf("\n-------------------------------------------------------\n");
// while (x < map->heigh_map)
// {
    //     y = 0;
    //     while (map_beta[x][y])
    //     {
        //         printf("%c",map_beta[x][y]);
        //         y++;
        //     }
        //     printf("\n");
        //     x++;
        // }
        // printf("\n-------------------------------------------------------\n");
        // printf("strlen de 1 => %zu\n", ft_strlen(map_beta[1]));
        // printf("\n-------------------------------------------------------\n");
        // printf("map_beta[1] :\n%s", map_beta[1]);
        // printf("\n-------------------------------------------------------\n");

// Printf map sous tab int
