/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:13:02 by loamar            #+#    #+#             */
/*   Updated: 2020/03/10 06:40:31 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void    draw_floor_ceiling(t_cub3d *cub, int check_x, int check_y)
{
    // int     floor_tex_x;
    // int     floor_tex_y;
    // int     tex_y;
    // color(cub);
    // plafond
    // printf("baba\n");
    // printf("img_buf -> %d\n", cub->game->img_buf[check_y * cub->map->res_x + check_x]);
    // if (cub->player->move_fly == 1)
    // {
    //     cub->img->img_buf[check_y * cub->map->res_x + check_x] = BLUE;
    //     cub->img->img_buf[ft_min(cub->map->res_y - check_y, cub->map->res_y) * cub->map->res_x + check_x] = RED;
    // }
    // else if (cub->player->bug_vision == 1)
    // {
    //     cub->img->img_buf[check_y * cub->map->res_x + check_x] = BLACK;
    //     cub->img->img_buf[ft_min(cub->map->res_y - check_y, cub->map->res_y) * cub->map->res_x + check_x] = BLACK;
    // }
    // else
    // {
        //bonus
        // tex_y = (((float)check_y * 2. - (float)cub->map->res_y + (float)wall_size)
        // * (float)(64 / 2) / wall_size);
        // cub->img->img_buf[check_y * cub->map->res_x + check_x] = cub->img->data_textures[cub->player->sides[check_x]][(int)tex_y * 64 + cub->player->tex_x[check_x]];
        // cub->img->img_buf[ft_min(cub->map->res_y - check_y, cub->map->res_y) * cub->map->res_x + check_x] = cub->img->data_textures[cub->player->sides[check_x]][(int)tex_y * 64 + cub->player->tex_x[check_x]];
        // fin bonus

        //bonus
        // cub->img->img_buf[check_y * cub->map->res_x + check_x] = cub->img->data_textures[2][cub->player->ty * 64 + cub->player->tx];
        //
        // cub->img->img_buf[ft_min(cub->map->res_y - check_y, cub->map->res_y) * cub->map->res_x + check_x] = cub->img->data_textures[5][cub->player->ty * 64 + cub->player->tx];
        // fin bonus

        // test
        // cub->player->tx = (int)(cub->player->floor_x * 64) % 64;
        // cub->player->ty = (int)(cub->player->floor_y * 64) % 64;
        //
        // cub->img->img_buf[check_y * cub->map->res_x + check_x] = cub->img->data_textures[2][cub->player->ty * 64 + cub->player->tx];
        //
        // cub->img->img_buf[ft_min(cub->map->res_y - check_y, cub->map->res_y) * cub->map->res_x + check_x] = cub->img->data_textures[5][cub->player->ty * 64 + cub->player->tx];
        // test fin
        // printf("check_y = %d\n", check_y);
        // printf("cub->img->img_buf[check_y * cub->map->res_x + check_x] => %d\n", cub->img->img_buf[check_y * cub->map->res_x + check_x]);
        // printf("=> check_y * cub->map->res_x - check_x => %d\n", check_y * cub->map->res_x - check_x);
        // printf("plz => ft_min(cub->map->res_y - check_y, cub->map->res_y) * cub->map->res_x + check_x => %d\n", ft_min(cub->map->res_y - check_y, cub->map->res_y) * (cub->map->res_x + check_x));
        // printf("cub->img->img_buf[ft_min(cub->map->res_y - check_y, cub->map->res_y) * cub->map->res_x + check_x] => %d\n", cub->img->img_buf[(cub->map->res_y - check_y) * (cub->map->res_x + check_x)]);
        // cub->player->time = 1;
        // check_x = check_x + 0;
        // check_y = check_y + 0;
        // ICI tout les calcules sont bon!
        // printf("yeyo\n");
        // cub->img->img_buf[check_y * cub->map->res_x + check_x] = WHITE;
        // printf("yeyo2\n");
        // cub->img->img_buf[ft_min(check_y - cub->map->res_y, cub->map->res_y) * cub->map->res_x + check_x] = BROWN;
        // printf("check_y = %d\n", check_y);
        // printf("check_x = %d\n", check_x);
        // printf("res_y = %d\n", cub->map->res_y);
        // printf("res_x = %d\n", cub->map->res_x);
        // cub->img->img_buf[ft_min(cub->map->res_y - check_y, cub->map->res_y) * cub->map->res_x + check_x] = BROWN;
        // cub->img->img_buf[(cub->map->res_y - check_y) * cub->map->res_x + check_x] = BROWN;
        // printf("yeyo3\n");
        // printf("yeyo2\n");
        cub->img->img_buf[check_y * cub->map->res_x + check_x] = cub->map->ceiling_addr;
        // printf("yeyo3\n");
        // cub->img->img_buf[(cub->map->res_y - check_y) * cub->map->res_x + check_x] = BROWN;
        cub->img->img_buf[ft_min(cub->map->res_y - check_y, cub->map->res_y) * cub->map->res_x + check_x] = cub->map->floor_addr;
    // cub->img->img_buf[check_y * cub->map->res_x + check_x] = WHITE;
    // printf("after img_buf -> %d\n", cub->game->img_buf[check_y * cub->map->res_x + check_x]);
    // sole
    // cub->img->img_buf[check_y * cub->map->res_x + check_x] = GREY;
    // printf("baba1\n");
    // printf("baba2\n");
    // cub->game->img_buf[cub->map->res_y] = cub->img->color;
}

static void    draw_wall(t_cub3d *cub, int check_x, int check_y, int wall_size)
{
    // color(cub);
    // printf("yala1\n");
    // int tex_y;
    int     tex_y;

    // tex_y = (((float)check_y * 2.0 - (float)cub->map->res_y + wall_size) * (float)(64 / 2) / (float)wall_size);
    // if (cub->player->sides[check_x] == 0 || cub->player->sides[check_x] == 1)
    // if (cub->player->move_fly == 1)
    //     cub->img->img_buf[check_y * cub->map->res_x + check_x] = GREEN;
    // else if (bug_vision(cub, check_x, check_y, wall_size) == 0)
    // {
        if (cub->player->sides[check_x] == 0 || cub->player->sides[check_x] == 1)
            tex_y = (((float)check_y * 2. - (float)cub->map->res_y + (float)wall_size)
            * (float)(64 / 2) / (float)wall_size);
        else
            tex_y = (((float)check_y * 2. - (float)cub->map->res_y + (float)wall_size)
            * (float)(64 / 2) / (float)wall_size);
        cub->img->img_buf[check_y * cub->map->res_x + check_x] = cub->img->data_textures[cub->player->sides[check_x]][(int)tex_y * 64 + cub->player->tex_x[check_x]];
        // cub->img->img_buf[check_y * cub->map->res_x + check_x] = GREEN;
        // if (cub->player->sides[check_x] == 1)
        //     cub->img->img_buf[check_y * cub->map->res_x + check_x] = BLACK;
        // else
        //     cub->img->img_buf[check_y * cub->map->res_x + check_x] = GREY;
    // }
        // tex_y = ((float)check_y * 2.0 - (float)cub->map->res_y + (float)wall_size) * (float)(64/2) / (float)wall_size;
    // printf("yala2\n");
	// 	* (float)(64 / 2) / (float)wall_pxl_high);
    // printf("yala3\n");
    // cub->game->img_buf[check_y * cub->map->res_x + check_x] = BLUE;
    // cub->game->img_buf[]
}

int     draw_buffer(t_cub3d *cub)
{
    int     check_x;
    int     check_y;
    int     wall_size;
    int     wall_start;
    int     wall_end;

    check_x = 0;
    while (check_x < cub->map->res_x - 1)
    {
        // printf("said2\n");
        wall_size = abs((int)(cub->map->res_y / cub->player->distances[check_x]));
        // printf("said3\n");
        wall_start = ft_max((int)(cub->map->res_y / 2 - wall_size / 2), 0);
        // printf("said4\n");
        wall_end = ft_min((int)(cub->map->res_y / 2 + wall_size / 2), cub->map->res_y);
        // printf("said5\n");
        // printf("wall_size = %d\n", wall_size);
        // printf("wall_start = %d\n", wall_start);
        // printf("wall_end = %d\n", wall_end);
        if (cub->player->bug_empty == 1)
        {
            // wall_size += 50;
            // wall_start = cub->map->res_y;
            wall_end = cub->map->res_y;
        }
        // if (cub->img->wall_start < 0)
        //     cub->img->wall_start = 0;
        check_y = 0;
        // printf("said7\n");
        while (check_y++ < (int)wall_start)
            draw_floor_ceiling(cub, check_x, check_y);
        // printf("said7-bis\n");

        // while ()
        while (check_y < (int)wall_end)
            draw_wall(cub, check_x, check_y++, wall_size);
        // check_y = 0;
        // while (check_y < (int)wall_start)
            // cub->img->img_buf[check_y * cub->map->res_x + check_x] = WHITE;
        // printf("said8\n");
        check_x++;
    }
    check_y = 0;
    return (1);
}
/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
// static void    draw_floor_ceiling(t_cub3d *cub, int check_x, int check_y, int wall_size)
// {
//     int i;
//
//     i = wall_size;
//     // int     floor_tex_x;
//     // int     floor_tex_y;
//     // int     tex_y;
//     // color(cub);
//     // plafond
//     // printf("baba\n");
//     // printf("img_buf -> %d\n", cub->game->img_buf[check_y * cub->map->res_x + check_x]);
//     // if (cub->player->move_fly == 1)
//     // {
//     //     cub->img->img_buf[check_y * cub->map->res_x + check_x] = BLUE;
//     //     cub->img->img_buf[ft_min(cub->map->res_y - check_y, cub->map->res_y) * cub->map->res_x + check_x] = RED;
//     // }
//     // else if (cub->player->bug_vision == 1)
//     // {
//     //     cub->img->img_buf[check_y * cub->map->res_x + check_x] = BLACK;
//     //     cub->img->img_buf[ft_min(cub->map->res_y - check_y, cub->map->res_y) * cub->map->res_x + check_x] = BLACK;
//     // }
//     // else
//     // {
//         //bonus
//         // tex_y = (((float)check_y * 2. - (float)cub->map->res_y + (float)wall_size)
//         // * (flnnoat)(64 / 2) / wall_size);
//         // cub->img->img_buf[check_y * cub->map->res_x + check_x] = cub->img->data_textures[cub->player->sides[check_x]][(int)tex_y * 64 + cub->player->tex_x[check_x]];
//         // cub->img->img_buf[ft_min(cub->map->res_y - check_y, cub->map->res_y) * cub->map->res_x + check_x] = cub->img->data_textures[cub->player->sides[check_x]][(int)tex_y * 64 + cub->player->tex_x[check_x]];
//         // fin bonus
//
//         //bonus
//         // cub->img->img_buf[check_y * cub->map->res_x + check_x] = cub->img->data_textures[2][cub->player->ty * 64 + cub->player->tx];
//         //
//         // cub->img->img_buf[ft_min(cub->map->res_y - check_y, cub->map->res_y) * cub->map->res_x + check_x] = cub->img->data_textures[5][cub->player->ty * 64 + cub->player->tx];
//         // fin bonus
//
//         // test
//         // cub->player->tx = (int)(cub->player->floor_x * 64) % 64;
//         // cub->player->ty = (int)(cub->player->floor_y * 64) % 64;
//         //
//         // cub->img->img_buf[check_y * cub->map->res_x + check_x] = cub->img->data_textures[2][cub->player->ty * 64 + cub->player->tx];
//         //
//         // cub->img->img_buf[ft_min(cub->map->res_y - check_y, cub->map->res_y) * cub->map->res_x + check_x] = cub->img->data_textures[5][cub->player->ty * 64 + cub->player->tx];
//         // test fin
//     // cub->img->img_buf[check_y * cub->map->res_x + check_x] = WHITE;
//     // cub->img->img_buf[ft_min(cub->map->res_y - check_y, cub->map->res_y) * cub->map->res_x + check_x] = BLACK;
//     printf("poeteuuuh1\n");
//     cub->img->img_buf[check_y * cub->map->res_x + check_x] = RED;
//     printf("poeteuuuh2\n");
// 	cub->img->img_buf[ft_min(cub->map->res_y - check_y, cub->map->res_y) * cub->map->res_x + check_x] = WHITE;
//     // printf("after img_buf -> %d\n", cub->game->img_buf[check_y * cub->map->res_x + check_x]);
//     printf("poeteuuuh3\n");
//     // sole
//     // cub->img->img_buf[check_y * cub->map->res_x + check_x] = GREY;
//     // printf("baba1\n");
//     // printf("baba2\n");
//     // cub->game->img_buf[cub->map->res_y] = cub->img->color;
// }
//
// static void    draw_wall(t_cub3d *cub, int check_x, int check_y, int wall_size)
// {
//     // color(cub);
//     // printf("yala1\n");
//     // int tex_y;
//     int     tex_y;
//
//     // tex_y = (((float)check_y * 2.0 - (float)cub->map->res_y + wall_size) * (float)(64 / 2) / (float)wall_size);
//     // if (cub->player->sides[check_x] == 0 || cub->player->sides[check_x] == 1)
//     // if (cub->player->move_fly == 1)
//     //     cub->img->img_buf[check_y * cub->map->res_x + check_x] = GREEN;
//     // else if (bug_vision(cub, check_x, check_y, wall_size) == 0)
//     // {
//     if (cub->player->sides[check_x] == 0 || cub->player->sides[check_x] == 1)
//         tex_y = (((float)check_y * 2. - (float)cub->map->res_y + (float)wall_size)
//         * (float)(64 / 2) / (float)wall_size);
//     else
//         tex_y = (((float)check_y * 2. - (float)cub->map->res_y + (float)wall_size)
//         * (float)(64 / 2) / (float)wall_size);
//     cub->img->img_buf[check_y * cub->map->res_x + check_x] = cub->img->data_textures[cub->player->sides[check_x]][(int)tex_y * 64 + cub->player->tex_x[check_x]];
//         // if (cub->player->sides[check_x] == 1)
//         //     cub->img->img_buf[check_y * cub->map->res_x + check_x] = BLACK;
//         // else
//         //     cub->img->img_buf[check_y * cub->map->res_x + check_x] = GREY;
//     // }
//         // tex_y = ((float)check_y * 2.0 - (float)cub->map->res_y + (float)wall_size) * (float)(64/2) / (float)wall_size;
//     // printf("yala2\n");
// 	// 	* (float)(64 / 2) / (float)wall_pxl_high);
//     // printf("yala3\n");
//     // cub->game->img_buf[check_y * cub->map->res_x + check_x] = BLUE;
//     // cub->game->img_buf[]
// }
//
// int     draw_buffer(t_cub3d *cub)
// {
//     int     check_x;
//     int     check_y;
//     int     wall_size;
//     int     wall_start;
//     int     wall_end;
//
//     wall_size = 0;
//     wall_start = 0;
//     wall_end = 0;
//
//     // printf("said1\n");
//     check_x = 0;
//     while (check_x < cub->map->res_x - 1)
//     {
//         wall_size = abs((int)(cub->map->res_y / cub->player->distances[check_x]));
//         wall_start = ft_max((int)(cub->map->res_y / 2 - wall_size / 2), 0);
//         wall_end = ft_min((int)(cub->map->res_y / 2 + wall_size / 2), cub->map->res_y);
//         check_y = 0;
//         printf("wall size = %d\n", wall_size);
//         printf("wall start = %d\n", wall_start);
//         printf("wall end = %d\n", wall_end);
//         if (cub->img->wall_start < 0)
//             cub->img->wall_start = 0;
//         while (check_y < (int)wall_start)
//         {
//             printf("check_y = %d\n", check_y);
//             draw_floor_ceiling(cub, check_x, check_y++, wall_size);
//         }
//         while (check_y < (int)wall_end)
//             draw_wall(cub, check_x, check_y++, wall_size);
//         check_x++;
//     }
//     return (1);
// }
// ////////////////////////////////////////////////
// ////////////////////////////////////////////////
// ////////////////////////////////////////////////
// ////////////////////////////////////////////////
// ////////////////////////////////////////////////
// ////////////////////////////////////////////////
// ////////////////////////////////////////////////
// ////////////////////////////////////////////////
// ////////////////////////////////////////////////
// ////////////////////////////////////////////////
// ////////////////////////////////////////////////
// ////////////////////////////////////////////////
// ////////////////////////////////////////////////
// ////////////////////////////////////////////////
// ////////////////////////////////////////////////
// ////////////////////////////////////////////////
// ////////////////////////////////////////////////
// ////////////////////////////////////////////////
// ////////////////////////////////////////////////
// ////////////////////////////////////////////////
// ////////////////////////////////////////////////
//
// // bonus chelou
//
// // static void    draw_floor_ceiling(t_cub3d *cub, int check_x, int check_y, int wall_size)
// // {
// //     // int     floor_tex_x;
// //     // int     floor_tex_y;
// //     // int     tex_y;
// //     // color(cub);
// //     // plafond
// //     // printf("baba\n");
// //     // printf("img_buf -> %d\n", cub->game->img_buf[check_y * cub->map->res_x + check_x]);
// //     // if (cub->player->move_fly == 1)
// //     // {
// //     //     cub->img->img_buf[check_y * cub->map->res_x + check_x] = BLUE;
// //     //     cub->img->img_buf[ft_min(cub->map->res_y - check_y, cub->map->res_y) * cub->map->res_x + check_x] = RED;
// //     // }
// //     // else if (cub->player->bug_vision == 1)
// //     // {
// //     //     cub->img->img_buf[check_y * cub->map->res_x + check_x] = BLACK;
// //     //     cub->img->img_buf[ft_min(cub->map->res_y - check_y, cub->map->res_y) * cub->map->res_x + check_x] = BLACK;
// //     // }
// //     // else
// //     // {
// //         //bonus
// //         // tex_y = (((float)check_y * 2. - (float)cub->map->res_y + (float)wall_size)
// //         // * (float)(64 / 2) / wall_size);
// //         // cub->img->img_buf[check_y * cub->map->res_x + check_x] = cub->img->data_textures[cub->player->sides[check_x]][(int)tex_y * 64 + cub->player->tex_x[check_x]];
// //         // cub->img->img_buf[ft_min(cub->map->res_y - check_y, cub->map->res_y) * cub->map->res_x + check_x] = cub->img->data_textures[cub->player->sides[check_x]][(int)tex_y * 64 + cub->player->tex_x[check_x]];
// //         // fin bonus
// //
// //         //bonus
// //         // cub->img->img_buf[check_y * cub->map->res_x + check_x] = cub->img->data_textures[2][cub->player->ty * 64 + cub->player->tx];
// //         //
// //         // cub->img->img_buf[ft_min(cub->map->res_y - check_y, cub->map->res_y) * cub->map->res_x + check_x] = cub->img->data_textures[5][cub->player->ty * 64 + cub->player->tx];
// //         // fin bonus
// //
// //         // test
// //         // cub->player->tx = (int)(cub->player->floor_x * 64) % 64;
// //         // cub->player->ty = (int)(cub->player->floor_y * 64) % 64;
// //         //
// //         // cub->img->img_buf[check_y * cub->map->res_x + check_x] = cub->img->data_textures[2][cub->player->ty * 64 + cub->player->tx];
// //         //
// //         // cub->img->img_buf[ft_min(cub->map->res_y - check_y, cub->map->res_y) * cub->map->res_x + check_x] = cub->img->data_textures[5][cub->player->ty * 64 + cub->player->tx];
// //         // test fin
// //     cub->img->img_buf[check_y * cub->map->res_x + check_x] = WHITE;
// //     cub->img->img_buf[ft_min(cub->map->res_y - check_y, cub->map->res_y) * cub->map->res_x + check_x] = BROWN;
// //     // printf("after img_buf -> %d\n", cub->game->img_buf[check_y * cub->map->res_x + check_x]);
// //     // sole
// //     // cub->img->img_buf[check_y * cub->map->res_x + check_x] = GREY;
// //     // printf("baba1\n");
// //     // printf("baba2\n");
// //     // cub->game->img_buf[cub->map->res_y] = cub->img->color;
// // }
// //
// // static void    draw_wall(t_cub3d *cub, int check_x, int check_y, int wall_size)
// // {
// //     // color(cub);
// //     // printf("yala1\n");
// //     // int tex_y;
// //     int     tex_y;
// //
// //     // tex_y = (((float)check_y * 2.0 - (float)cub->map->res_y + wall_size) * (float)(64 / 2) / (float)wall_size);
// //     // if (cub->player->sides[check_x] == 0 || cub->player->sides[check_x] == 1)
// //     // if (cub->player->move_fly == 1)
// //     //     cub->img->img_buf[check_y * cub->map->res_x + check_x] = GREEN;
// //     // else if (bug_vision(cub, check_x, check_y, wall_size) == 0)
// //     // {
// //         if (cub->player->sides[check_x] == 0 || cub->player->sides[check_x] == 1)
// //             tex_y = (((float)check_y * 2. - (float)cub->map->res_y + (float)wall_size)
// //             * (float)(64 / 2) / (float)wall_size);
// //         else
// //             tex_y = (((float)check_y * 2. - (float)cub->map->res_y + (float)wall_size)
// //             * (float)(64 / 2) / (float)wall_size);
// //         cub->img->img_buf[check_y * cub->map->res_x + check_x] = cub->img->data_textures[cub->player->sides[check_x]][(int)tex_y * 64 + cub->player->tex_x[check_x]];
// //         // if (cub->player->sides[check_x] == 1)
// //         //     cub->img->img_buf[check_y * cub->map->res_x + check_x] = BLACK;
// //         // else
// //         //     cub->img->img_buf[check_y * cub->map->res_x + check_x] = GREY;
// //     // }
// //         // tex_y = ((float)check_y * 2.0 - (float)cub->map->res_y + (float)wall_size) * (float)(64/2) / (float)wall_size;
// //     // printf("yala2\n");
// // 	// 	* (float)(64 / 2) / (float)wall_pxl_high);
// //     // printf("yala3\n");
// //     // cub->game->img_buf[check_y * cub->map->res_x + check_x] = BLUE;
// //     // cub->game->img_buf[]
// // }
// //
// // int     draw_buffer(t_cub3d *cub)
// // {
// //     int     check_x;
// //     int     check_y;
// //     int     wall_size;
// //     int     wall_start;
// //     int     wall_end;
// //
// //     // printf("said1\n");
// //     check_x = 0;
// //     while (check_x < cub->map->res_x - 1)
// //     {
// //         wall_size = abs((int)(cub->map->res_y / cub->player->distances[check_x]));
// //         wall_start = ft_max((int)(cub->map->res_y / 2 - wall_size / 2), 0);
// //         wall_end = ft_min((int)(cub->map->res_y / 2 + wall_size / 2), cub->map->res_y);
// //         check_y = 0;
// //         // if (cub->img->wall_start < 0)
// //         //     cub->img->wall_start = 0;
// //         while (check_y < (int)wall_end)
// //             draw_wall(cub, check_x, check_y++, wall_size);
// //         check_x++;
// //     }
// //     return (1);
// // }
