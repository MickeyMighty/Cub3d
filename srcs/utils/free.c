/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:37:28 by loamar            #+#    #+#             */
/*   Updated: 2020/06/15 18:24:35 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_split(char **str)
{
	int		index;

	index = 0;
	while (str[index])
	{
		free(str[index]);
		index++;
	}
	free(str);
}

void	free_tab_int(int **tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_sprite(t_cub3d *cub)
{
	t_sprite *next;

	while (cub->sprites->next)
	{
		next = cub->sprites->next;
		if (cub->sprites)
			free(cub->sprites);
		cub->sprites = next;
	}
	free(cub->sprites);
}

void	free_game(t_cub3d *cub, int error)
{
	if (error == 2 || error == 3 || error == 4)
		free(cub->game);
	else
	{
		if (cub->game->img_ptr)
			mlx_destroy_image(cub->game->mlx_ptr, cub->game->img_ptr);
		if (cub->game->win_ptr)
		{
			mlx_clear_window(cub->game->mlx_ptr, cub->game->win_ptr);
			mlx_destroy_window(cub->game->mlx_ptr, cub->game->win_ptr);
		}
		free(cub->game);
	}
}
