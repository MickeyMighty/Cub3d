/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:53:31 by loamar            #+#    #+#             */
/*   Updated: 2020/06/15 20:27:15 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
** Number of key :
** 126 = up (go straight)
** 125 = down (go back)
** 123 = left (go left)
** 124 = right (go right)
** 13 = w (go straight)
** 0 = a (go left)
** 1 = s (go back)
** 2 = d (go right)
** 53 = esc (exit)
*/

int		key_press(int key, t_cub3d *cub)
{
	if (key == KEY_UP || key == KEY_W)
		cub->player->move_s = 1;
	else if (key == KEY_DOWN || key == KEY_S)
		cub->player->move_b = 1;
	else if (key == KEY_LEFT || key == KEY_Q)
		cub->player->rotate_l = 1;
	else if (key == KEY_RIGHT || key == KEY_E)
		cub->player->rotate_r = 1;
	else if (key == KEY_PLUS)
		cub->player->move_faster = 1;
	else if (key == KEY_D)
		cub->player->move_r = 1;
	else if (key == KEY_A)
		cub->player->move_l = 1;
	else if (key == KEY_ESC)
		ft_error(cub, "Success", 0);
	return (0);
}

int		key_release(int key, t_cub3d *cub)
{
	if (key == KEY_UP || key == KEY_W)
		cub->player->move_s = 0;
	else if (key == KEY_DOWN || key == KEY_S)
		cub->player->move_b = 0;
	else if (key == KEY_LEFT || key == KEY_Q)
		cub->player->rotate_l = 0;
	else if (key == KEY_RIGHT || key == KEY_E)
		cub->player->rotate_r = 0;
	else if (key == KEY_D)
		cub->player->move_r = 0;
	else if (key == KEY_A)
		cub->player->move_l = 0;
	else if (key == KEY_PLUS)
		cub->player->move_faster = 0;
	return (0);
}
