/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 23:40:36 by loamar            #+#    #+#             */
/*   Updated: 2020/04/30 16:32:24 by lorenzoamar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void destroy_application(t_application to_destroy)
// {
// 	mlx_destroy_image(to_destroy.mlx_ptr, to_destroy.img_ptr);
// 	mlx_destroy_window(to_destroy.mlx_ptr, to_destroy.win_ptr);
// }
//
// void free_application(t_application *to_free)
// {
// 	destroy_application(*to_free);
// 	free(to_free);
// }

// int		ft_error_cub(t_application *game, char *msg)
// {
// 	ft_putstr_fd("Error\n", 2);
// 	ft_putstr_fd(msg, 2);
// 	if (game)
// 	{
// 		free(game);
// 		//cub3d = NULL;
// 	}
// 	//exit(EXIT_FAILURE);
// 	return (0);
// }
//
// int		ft_error_player(t_player *player, char *msg)
// {
// 	ft_putstr_fd("Error\n", 2);
// 	ft_putstr_fd(msg, 2);
// 	if (player)
// 	{
// 		free(player);
// 		//cub3d = NULL;
// 	}
// 	//exit(EXIT_FAILURE);
// 	return (0);
// }
//
// int		ft_error_image(t_draw *img, char *msg)
// {
// 	ft_putstr_fd("Error\n", 2);
// 	ft_putstr_fd(msg, 2);
// 	if (img)
// 	{
// 		free(img);
// 		//cub3d = NULL;
// 	}
// 	//exit(EXIT_FAILURE);
// 	return (0);
// }

//
// void		free_app(t_application *app)
// {
// 	ft_strdel(&g->str_cub);
// 	free_map(g);
// 	if (g->x_len_for_y)
// 		free(g->x_len_for_y);
// 	ft_memdel((void *)&g->mlx_init_ret);
// 	ft_memdel((void *)&g->mlx_new_win_ret);
// 	ft_memdel((void *)&g->mlx_new_img_ret);
// 	ft_memdel((void *)&g->img_buffer);
// 	ft_memdel((void *)&g->distances);
// 	ft_memdel((void *)&g->sides);
// 	ft_memdel((void *)&g->hit_wall_x);
// 	ft_memdel((void *)&g->tex_x);
// 	free_sprites(g);
// }

// int		ft_error_map(t_map *map, char *msg)
// {
// 	ft_putstr_fd("Error\n", 2);
// 	ft_putstr_fd(msg, 2);
// 	if (map)
// 	{
// 		free(map);
// 		//map = NULL;
// 	}
// 	//exit(EXIT_FAILURE);
// 	return (0);
// }
// static void    free_map(int **map2, t_map *map)
// {
//     int     index;
//
//     index = 0;
//     while (index < map->size_y)
//     {
//         free(map2[index]);
//         index++;
//     }
//     free(map2);
// }

int		ft_error(t_cub3d *cub, char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	if (cub)
	{
		if (cub->map)
		{
            // printf("poet\n");
			// if (cub->map->map)
			// 	free_map(cub->map->map, cub->map);
			// if (cub->map->sprite_order)
			// 	free(cub->map->sprite_order);
			// if (cub->map->sprite_distance)
			// 	free(cub->map->sprite_distance);
			// if (cub->map->beta_res_x)
			// 	free(cub->map->beta_res_x);
			// if (cub->map->beta_res_y)
			// 	free(cub->map->beta_res_y);
			// if (cub->map->north_texture)
			// 	free(cub->map->north_texture);
			// if (cub->map->south_texture)
			// 	free(cub->map->south_texture);
			// if (cub->map->west_texture)
			// 	free(cub->map->west_texture);
			// if (cub->map->east_texture)
			// 	free(cub->map->east_texture);
			// if (cub->map->sprite_texture)
			// 	free(cub->map->sprite_texture);
			// if (cub->map->ceiling_color)
			// 	free(cub->map->ceiling_color);
			// if (cub->map->floor_color)
			// 	free(cub->map->floor_color);
			free(cub->map);
		}
		if (cub->game)
		{
            // printf("poet2\n");
			// if (cub->game->mlx_ptr)
			// 	free(cub->game->mlx_ptr);
			// if (cub->game->win_ptr)
			// 	free(cub->game->win_ptr);
			// if (cub->game->img_ptr)
			// 	free(cub->game->img_ptr);
			// if (cub->game->pixels)
			// 	free(cub->game->pixels);
			// if (cub->game->pixels2)
			// 	free(cub->game->pixels2);
			free(cub->game);
		}
		if (cub->player)
		{

            // printf("poet3\n");
			// if (cub->player->distances)
			// 	free(cub->player->distances);
			// if (cub->player->sides)
			// 	free(cub->player->sides);
			// if (cub->player->hit_wall_x)
			// 	free(cub->player->hit_wall_x);
			// if (cub->player->hit_sprite_x)
			// 	free(cub->player->hit_sprite_x);
			// if (cub->player->tex_x)
			// 	free(cub->player->tex_x);
			free(cub->player);
		}
		if (cub->img)
		{
            // printf("poet4\n");
			// if (cub->img->img_buf)
			// 	free(cub->img->img_buf);
			// if (cub->img->data_textures)
			// 	free_map(cub->img->data_textures, cub->map);
			// if (cub->img->xpm_to_img)
			// 	free_map((int**)cub->img->xpm_to_img, cub->map);

			free(cub->img);
		}
		free(cub);
		//map = NULL;
	}
	exit(EXIT_FAILURE);
	return (0);
}

static void		free_cub(t_cub3d *cub)
{
	if (cub)
	{
		// if (cub->map)
		// 	free(cub->map);
		// if (cub->game)
		// 	free(cub->game);
		// if (cub->player)
		// 	free(cub->player);
		// if (cub->img)
		// 	free(cub->img);
		free(cub);
		//map = NULL;
	}
}

int		Error_msg(void)
{
	ft_putstr_fd("Error with Parsing", 2);
	exit(EXIT_FAILURE);
	return (0);
}
