/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 11:55:20 by loamar            #+#    #+#             */
/*   Updated: 2020/06/16 02:41:43 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** Number of key :
** 126 = up (moving forward)
** 125 = down (retreat)
** 123 = left (go left)
** 124 = right (go right)
** 13 = w (moving forward)
** 0 = a (go left)
** 1 = s (retreat)
** 2 = d (go right)
** 53 = esc (exit)
*/

static int		screenshot(t_cub3d *cub)
{
	int		fd;

	move(cub->player, cub->map);
	if (!cub->sprites->next && !detect_sprites(cub))
		ft_error(cub, "Malloc.\n", 1);
	if (ray_casting(cub) == 0)
		ft_error(cub, "Raycasting.\n", 1);
	draw_buffer(cub);
	if ((fd = open("save.bmp", O_CREAT)) < 0)
		ft_error(cub, "Bad screenshot.\n", 1);
	close(fd);
	if (cub->sprites)
		draw_sprites(cub);
	create_bmp(cub);
	return (1);
}

static int		update_win(t_cub3d *cub)
{
	move(cub->player, cub->map);
	if (!cub->sprites->next && !detect_sprites(cub))
		ft_error(cub, "Malloc\n", 1);
	if (ray_casting(cub) == 0)
		ft_error(cub, "Raycasting.\n", 1);
	draw_buffer(cub);
	if (cub->sprites)
		draw_sprites(cub);
	mlx_put_image_to_window(cub->game->mlx_ptr, (void*)cub->game->win_ptr,
	(void*)cub->game->img_ptr, 0, 0);
	return (0);
}

int				get_text(t_cub3d *cub)
{
	int		res_x;
	int		res_y;
	int		i;

	res_x = cub->map->res_x;
	res_y = cub->map->res_y;
	if (!(cub->img->xpm_to_img = (void **)malloc(sizeof(void *) * 5)))
		return (0);
	if (!(cub->img->data_textures = (int **)malloc(sizeof(int *) * 5)))
		return (0);
	i = 0;
	while (i < 5)
	{
		if (display_textures(cub, res_x, res_y, i) == 0)
			return (0);
		i++;
	}
	cub->img->size_error = 4;
	return (1);
}

static int		ft_mlx(t_cub3d *cub)
{
	cub->game->mlx_ptr = mlx_init();
	cub->game->win_ptr = mlx_new_window(cub->game->mlx_ptr,
	cub->map->res_x, cub->map->res_y, "Cub3d");
	if (!(get_text(cub)))
		return (0);
	cub->game->img_ptr = mlx_new_image(cub->game->mlx_ptr,
	cub->map->res_x, cub->map->res_y);
	cub->img->img_buf = (int*)mlx_get_data_addr(cub->game->img_ptr,
	&(cub->game->bits_per_pixels),
	&(cub->game->size_line), &(cub->game->endian));
	if (cub->game->save == 1)
		return (screenshot(cub));
	mlx_hook(cub->game->win_ptr, 2, 0, key_press, cub);
	mlx_hook(cub->game->win_ptr, 3, 0, key_release, cub);
	mlx_hook(cub->game->win_ptr, 17, 0, on_exit, cub);
	mlx_loop_hook(cub->game->mlx_ptr, update_win, cub);
	mlx_loop(cub->game->mlx_ptr);
	return (1);
}

int				main(int argc, char **argv)
{
	t_cub3d		*cub;

	cub = NULL;
	if (!(cub = malloc_cub(cub)))
		ft_error((cub), "Malloc.\n", 3);
	if (parsing_cub3d(argc, argv, cub) == 0)
		ft_error((cub), "Wrong Map.\n", 3);
	if (init_player(cub->player, cub->map) == 0)
		ft_error((cub), "Malloc 2.\n", 3);
	if (ft_mlx(cub) == 0)
		return (ft_error(cub, "Bad Textures.\n", 1));
	return (0);
}
