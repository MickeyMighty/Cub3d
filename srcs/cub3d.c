/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 11:55:20 by loamar            #+#    #+#             */
/*   Updated: 2020/04/21 09:01:44 by lorenzoamar      ###   ########.fr       */
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

// En gros, il faut lui donner 3 pointeurs sur des int a toi, ou il va stocker les 3 valeurs
// En supplement, il va te renvoye un pointeur sur un tableau de char, qui correspondra aux pixels de l'image

static int			screenshot(t_cub3d *cub)
{
	int fd;

	move(cub->player, cub->map);
	if (!cub->sprites && !detect_sprites(cub))
		return (0);
	if (ray_casting(cub) == 0)
		return (0);
	draw_buffer(cub);
	if (cub->sprites)
		draw_sprites(cub);
	fd = open("fi.bmp", O_CREAT);
	close(fd);
	create_bmp(cub);
	return (1);
}

static int		update_win(t_cub3d *cub)
{
	move(cub->player, cub->map);
	if (!cub->sprites && !detect_sprites(cub))
		ft_error(cub, "from->[sprite]\n");
	if (ray_casting(cub) == 0)
		ft_error(cub, "from->[raycasting]\n");
	draw_buffer(cub);
	if (cub->sprites)
		draw_sprites(cub);
	mlx_put_image_to_window(cub->game->mlx_ptr, (void*)cub->game->win_ptr, (void*)cub->game->img_ptr, 0, 0);
	return (0);
}

static int 	ft_mlx(t_cub3d *cub)
{
	if (!(cub->game->mlx_ptr = mlx_init())
	|| (!(cub->game->win_ptr = mlx_new_window(cub->game->mlx_ptr, cub->map->res_x, cub->map->res_y, "Cub3d")))
	|| (!(cub->game->img_ptr = mlx_new_image(cub->game->mlx_ptr, cub->map->res_x, cub->map->res_y)))
	|| (!(cub->img->img_buf = (int*)mlx_get_data_addr(cub->game->img_ptr, &(cub->game->bits_per_pixels),
	&(cub->game->size_line), &(cub->game->endian)))))
		return(0);
	if (!(get_text(cub)))
		return(0);
	if (cub->game->save == 1)
		return(screenshot(cub));
	mlx_hook(cub->game->win_ptr, 2, 0, key_press, cub->player);
	mlx_hook(cub->game->win_ptr, 3, 0, key_release, cub->player);
	mlx_hook(cub->game->win_ptr, 17, 0, on_exit, cub->player);
	mlx_loop_hook(cub->game->mlx_ptr, update_win, cub);
	mlx_loop(cub->game->mlx_ptr);
	return (1);
}

int		main(int argc, char **argv)
{
	t_cub3d				*cub;

	cub = NULL;

	// Probleme dans malloc obligé
	if (!(cub = malloc_cub(cub)))
		ft_error((cub), "[main/malloc_player] Error.\n");
	if (!(cub->player = malloc_player(cub->player)))
		ft_error((cub), "[main/malloc_player] Error.\n");
	if (!(cub->game = malloc_application(cub->game)))
		ft_error((cub), "[main/malloc_app] Error.\n");
	cub->game->save = 0;
	// init_map(cub->map);
	if (!(cub->map = malloc_map(cub->map)))
		ft_error((cub), "[main/malloc_map] Error.\n");
	if (!(cub->img = malloc_image(cub->img)))
		ft_error((cub), "[main/malloc_img] Error.\n");
	if (!(cub->sprites = malloc_sprite(cub->sprites)))
		ft_error((cub), "[main/malloc_sprite] Error.\n");
	if (parsing_cub3d(argc, argv, cub) == 0)
		ft_error((cub), "Wrong Map.\n");
	// if (!(cub->img->img_buf = (int*)malloc(sizeof(int) * cub->map->res_x)))
	// 	ft_error(cub, "error image buffer.\n");
	if (init_player(cub->player, cub->map) == 0)
		ft_error((cub), "error [main/init_player]\n");
	cub->sprites = NULL;
	// cub->game->mlx_ptr = NULL;
	// cub->game->win_ptr = NULL;
	// cub->game->img_ptr = NULL;
	// cub->img->img_buf = NULL;
	if (ft_mlx(cub) == 0)
		return (ft_error(cub, "error [main/mlx]"));
	// printf("\nMAP GOOD\n");
	printf("\n===========\nDONE\n===========\n");
	return (0);
}
