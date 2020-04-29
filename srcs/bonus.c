/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:54:46 by loamar            #+#    #+#             */
/*   Updated: 2020/02/28 13:46:47 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int    moove_fly(t_cub3d *cub, int column)
{
    if (cub->player->move_fly == 1)
    {
        cub->player->camera_x = ((2.0 * ((float)column / (float)cub->map->res_x))
        * 1.0) * 2;
        cub->player->ray_pos_x = cub->player->pos_x;
        cub->player->ray_pos_y = cub->player->pos_y;
        cub->player->raydir_x = (cub->player->dir_x + cub->player->plane_x
        * cub->player->camera_x) * 2;
        cub->player->raydir_y = (cub->player->dir_y + cub->player->plane_y
        * cub->player->camera_x) * 2;
        return (1);
        // cub->player->camera_x = ((2.0 * ((float)column / (float)map->res_x)) * 1.0);
    }
    else
        return (0);
}

static int    bug_vision3(t_cub3d *cub,  int res_x, int res_y, int i)
{
    char    *str;

    str = BUG;
    if (i == 2)
    {
        if (!(cub->img->xpm_to_img[i] = mlx_xpm_file_to_image(cub->game->mlx_ptr,
            str, &res_x, &res_y)))
            return (0);
        else
            cub->img->data_textures[i] = (int*)mlx_get_data_addr(cub->img->xpm_to_img[i],
            &cub->game->bits_per_pixels, &cub->game->size_line, &cub->game->endian);
    }
    else if (i == 3)
    {
        if (!(cub->img->xpm_to_img[i] = mlx_xpm_file_to_image(cub->game->mlx_ptr,
            str, &res_x, &res_y)))
            return (0);
        else
            cub->img->data_textures[i] = (int*)mlx_get_data_addr(cub->img->xpm_to_img[i],
            &cub->game->bits_per_pixels, &cub->game->size_line, &cub->game->endian);
    }
    return (1);
}

static int    bug_vision2(t_cub3d *cub, int res_x, int res_y, int i)
{
    char    *str;

    str = BUG;
    if (i == 0)
    {
        if (!(cub->img->xpm_to_img[i] = mlx_xpm_file_to_image(cub->game->mlx_ptr,
        str, &res_x, &res_y)))
            return (0);
        else
            cub->img->data_textures[i] = (int*)mlx_get_data_addr(cub->img->xpm_to_img[i],
            &cub->game->bits_per_pixels, &cub->game->size_line, &cub->game->endian);
    }
    else if (i == 1)
    {
        if (!(cub->img->xpm_to_img[i] = mlx_xpm_file_to_image(cub->game->mlx_ptr,
        str, &res_x, &res_y)))
            return (0);
        else
            cub->img->data_textures[i] = (int*)mlx_get_data_addr(cub->img->xpm_to_img[i],
            &cub->game->bits_per_pixels, &cub->game->size_line, &cub->game->endian);
    }
    else if (i > 1)
        return (bug_vision3(cub, res_x, res_y, i));
    return (1);
}

int 		get_text_bug(t_cub3d *cub)
{
	int		res_x;
	int 	res_y;
    int     i;


	res_x = cub->map->res_x;
	res_y = cub->map->res_y;
    // if (cub->img->xpm_to_img)
    //     free(cub->img->xpm_to_img);
    // if (cub->img->data_textures)
    //     free(cub->img->data_textures);
	// if (!(cub->img->xpm_to_img = (void **)malloc(sizeof(void *) * 4)))
	// 	return (0);
	// if (!(cub->img->data_textures = (int **)malloc(sizeof(int *) * 4)))
	// 	return (0);
    i = 0;
    printf("poet\n");
    while (i < 4)
    {
        if (bug_vision2(cub, res_x, res_y, i) == 0)
            return (0);
        i++;
    }
	return (1);
}

int     bug_vision(t_cub3d *cub, int check_x, int check_y, int wall_size)
{
    int     tex_y;

    if (cub->player->bug_vision == 1)
    {
        // get_text_bug(cub);
        if (cub->player->sides[check_x] == 0 || cub->player->sides[check_x] == 1)
            tex_y = (((float)check_y * 2. - (float)cub->map->res_y + (float)wall_size)
            * (float)(64 / 2) / (float)wall_size);
        else
            tex_y = (((float)check_y * 2. - (float)cub->map->res_y + (float)wall_size)
            * (float)(64 / 2) / (float)wall_size);
        cub->img->img_buf[check_y * cub->map->res_x + check_x] = cub->img->data_textures[cub->player->sides[check_x]][(int)tex_y * 64 + cub->player->tex_x[check_x]];
        return (1);
    }
    else
    {
        // if (cub->img->xpm_to_img)
        //     free(cub->img->xpm_to_img);
        // if (cub->img->data_textures)
        //     free(cub->img->data_textures);
        // get_text(cub);
        return (0);
    }

}
