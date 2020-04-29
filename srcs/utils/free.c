/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:37:28 by loamar            #+#    #+#             */
/*   Updated: 2020/03/06 01:46:39 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    free_split(char **str)
{
    int     index;

    index = 0;
    while (str[index])
    {
        free(str[index]);
        index++;
    }
    free(str);
}

// void		free_sprites(t_game *g)
// {
// 	t_sprite *tmp;
//
// 	while (g->sprites)
// 	{
// 		tmp = g->sprites->next;
// 		if (g->sprites)
// 			free(g->sprites);
// 		g->sprites = tmp;
// 	}
// }
// //
// void		free_map(t_game *g)
// {
// 	int y;
//
// 	y = -1;
// 	while (g->map && ++y < g->map_y_len)
// 		ft_strdel(&g->map[y]);
// 	if (g->map && g->map_y_len)
// 		free(g->map);
// }

// void		free_textures(t_game *g)
// {
// 	int i;
//
// 	i = -1;
// 	while (i < 5)
// 	{
// 		ft_memdel((void *)&g->path_textures[i]);
// 		ft_memdel((void *)&g->data_textures[i]);
// 		ft_memdel((void *)&g->xpm_to_img[i++]);
// 	}
// }
//
// void		free_g(t_game *g)
// {
// 	ft_strdel(&g->buffer);
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

// int			handle_error(t_game *g, char *error_msg)
// {
// 	ft_putstr_fd("Error\n", 2);
// 	ft_putstr_fd(error_msg, 2);
// 	if (g)
// 		free_g(g);
// 	return (0);
// }
