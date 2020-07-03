/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 23:40:36 by loamar            #+#    #+#             */
/*   Updated: 2020/07/02 16:15:05 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		free_map2(t_cub3d *cub, int error)
{
	if (error == 4)
		free_split(cub->map->map_beta);
	if (cub->map->map)
		free_tab_int(cub->map->map, cub->map->size_y);
	if (cub->map->sprite_order)
		free(cub->map->sprite_order);
	if (cub->map->sprite_distance)
		free(cub->map->sprite_distance);
	if (cub->map->beta_res_x)
		free(cub->map->beta_res_x);
	if (cub->map->beta_res_y)
		free(cub->map->beta_res_y);
}

static void		free_map(t_cub3d *cub, int error)
{
	free_map2(cub, error);
	if (cub->map->north_texture)
		free(cub->map->north_texture);
	if (cub->map->south_texture)
		free(cub->map->south_texture);
	if (cub->map->west_texture)
		free(cub->map->west_texture);
	if (cub->map->east_texture)
		free(cub->map->east_texture);
	if (cub->map->sprite_texture)
		free(cub->map->sprite_texture);
	if (cub->map->ceiling_color)
		free(cub->map->ceiling_color);
	if (cub->map->floor_color)
		free(cub->map->floor_color);
	if (cub->map->size_x)
		free(cub->map->size_x);
	free(cub->map);
}

static void		free_player(t_cub3d *cub, int error)
{
	if (error == 3)
		free(cub->player);
	else
	{
		if (cub->player->distances)
			free(cub->player->distances);
		if (cub->player->sides)
			ft_memdel((void *)&cub->player->sides);
		if (cub->player->hit_wall_x)
			ft_memdel((void *)&cub->player->hit_wall_x);
		if (cub->player->hit_sprite_x)
			ft_memdel((void *)&cub->player->hit_sprite_x);
		if (cub->player->tex_x)
			ft_memdel((void *)&cub->player->tex_x);
		free(cub->player);
	}
}

static void		free_img(t_cub3d *cub, int error)
{
	if (error == 3 || error == 4)
		free(cub->img);
	else
	{
		if (cub->img->data_textures)
			free_tab_int(cub->img->data_textures, cub->img->size_error);
		if (cub->img->xpm_to_img)
			free_tab_int((int**)cub->img->xpm_to_img, cub->img->size_error);
		free(cub->img);
	}
}

int				ft_error(t_cub3d *cub, char *msg, int error)
{
	error_msg(error, msg);
	if (cub)
	{
		if (cub->map)
			free_map(cub, error);
		if (cub->player)
			free_player(cub, error);
		if (cub->img)
			free_img(cub, error);
		if (cub->sprites && (error == 1 || error == 0))
			free_sprite(cub);
		else
			free(cub->sprites);
		if (cub->game)
			free_game(cub, error);
		free(cub);
	}
	if (error == 1 || error == 3)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
	return (1);
}
