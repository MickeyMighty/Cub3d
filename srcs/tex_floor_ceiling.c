/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_floor_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 23:38:59 by loamar            #+#    #+#             */
/*   Updated: 2020/03/11 03:21:02 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


static void 	set_floor(t_cub3d *cub, int *y)
{
	if (cub->ns_or_ew == 0 && cub->ray_dir.x > 0)
	{
		cub->floor.x = cub->block.x;
		cub->floor.y = cub->block.y + cub->wall_x;
	}
	else if (cub->ns_or_ew == 0 && cub->ray_dir.x < 0)
	{
		cub->floor.x = cub->block.x + 1.0;
		cub->floor.y = cub->block.y + cub->wall_x;
	}
	else if (cub->ns_or_ew == 1 && cub->ray_dir.y > 0)
	{
		cub->floor.x = cub->block.x + cub->wall_x;
		cub->floor.y = cub->block.y;
	}
	else
	{
		cub->floor.x = cub->block.x + cub->wall_x;
		cub->floor.y = cub->block.y + 1.0;
	}
	cub->discub_wall = cub->perp;
	cub->discub_cub->player = 0.0;
	(cub->y_end < 0) ? cub->y_end = H : 0;
	*y = cub->y_end - 1;
}

static void	    ceiling_casting(t_env *env, t_thread *t, int x, int y)
{
    while (++x < cub->map->res_x)
    {
            cub->player->cell_x = (int)cub->player->floor_x;
            cub->player->cell_y = (int)cub->player->floor_y;
            cub->player->tx = (int)(widthtex * (cub->player->floor_x - cub->player->cell_x)) % widthtex;
            // widthtex - 1;
            cub->player->ty = (int)(heightex * (cub->player->floor_y - cub->player->cell_y)) % heightex;
            // heightex - 1;
            cub->player->floor_x += cub->player->floor_step_x;
            cub->player->floor_y += cub->player->floor_step_y;
            cub->player->checkerboardpattern = (int)(cub->player->cell_x + cub->player->cell_y) % 1;

    }
	if (cub->map->bool_ceil)
	{
		ft_memcpy(&t->color_str, &env->t[level_id(env->map, 2)].data_addr[t->j],
				sizeof(int));
		t->color = (int)t->color_str;
		t->color = darken(env, t->color, t->dist_current,
				env->map->item_candle);
		put_pixel(env, x, env->map->h2 * 2 - y, t->color);
		put_pixel(env, x, env->map->h2 * 2 - y, darken(env, t->color,
					abs((env->map->h2 * 2 - y) - env->map->h2) * 0.005,
					env->map->item_candle));
	}
}

int     floor_dda(t_cub3d *cub)
{
    int     x;
    int     y;

    x = 0;
    y = 0;
    set_floor(cub, &y);
    while (++y < cub->map->res_y)
    {
        cub->player->raydir_x0 = (cub->player->dir_x - cub->player->plane_x);
        cub->player->raydir_y0 = (cub->player->dir_y - cub->player->plane_y);
        cub->player->raydir_x1 = (cub->player->dir_x + cub->player->plane_x);
        cub->player->raydir_y1 = (cub->player->dir_y + cub->player->plane_y);
        cub->player->p = (x - cub->map->res_y) / 2;
        cub->player->posz = 0.5 * cub->map->res_y;
        cub->player->rowdistance = cub->player->posz / cub->player->p;
        // cub->player->floor_step_x = cub->player->rowdistance * (cub->player->raydir_x1 - cub->player->raydir_x0) / cub->map->res_x;
        // cub->player->floor_step_y = cub->player->rowdistance * (cub->player->raydir_y1 - cub->player->raydir_y0) / cub->map->res_x;
        cub->player->floor_x = cub->player->pos_x + cub->player->rowdistance * cub->player->raydir_x0;
        cub->player->floor_y = cub->player->pos_y + cub->player->rowdistance * cub->player->raydir_y0;
        ceiling_dda(cub, y++);
    }
    return (1);
}
