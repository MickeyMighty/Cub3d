/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:53:31 by loamar            #+#    #+#             */
/*   Updated: 2020/03/06 21:23:37 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

// key D => droite go
// key A => gauche go
// key Q et E => rotate
int     key_press(int key, t_player *player)
{
    printf("key => %d\n", key);
    if (key == KEY_UP || key == KEY_W)
        player->move_s = 1;
    else if (key == KEY_DOWN || key == KEY_S)
        player->move_b = 1;
    else if (key == KEY_LEFT || key == KEY_Q)
        player->rotate_l = 1;
    else if (key == KEY_RIGHT || key == KEY_E)
        player->rotate_r = 1;
    else if (key == KEY_F)
        player->move_fly = 1;
    else if (key == KEY_G)
        player->move_fly = 0;
    else if (key == KEY_PLUS)
        player->move_faster = 1;
    else if (key == KEY_D)
        player->move_r = 1;
    else if (key == KEY_A)
        player->move_l = 1;
    else if (key == KEY_V)
        player->bug_empty = 1;
    else if (key == KEY_SHIFT)
        player->squat = 1;
    else if (key == KEY_ESC)
    {
        free(player);
        //ft_free_all
        system("leaks a.out");
        exit(0);
    }
    return (0);
}

int     key_release(int key, t_player *player)
{
    if (key == KEY_UP || key == KEY_W)
        player->move_s = 0;
    else if (key == KEY_DOWN || key == KEY_S)
        player->move_b = 0;
    else if (key == KEY_LEFT || key == KEY_Q)
        player->rotate_l = 0;
    else if (key == KEY_RIGHT || key == KEY_E)
        player->rotate_r = 0;
    else if (key == KEY_D)
        player->move_r = 0;
    else if (key == KEY_A)
        player->move_l = 0;
    else if (key == KEY_PLUS)
        player->move_faster = 0;
    else if (key == KEY_E)
        player->bug_vision = 0;
    else if (key == KEY_V)
        player->bug_empty = 0;
    else if (key == KEY_SHIFT)
        player->squat = 0;
    // else if (key == KEY_ESC)
    // {
    //     free(player);
    //     //ft_free_all
    //     exit(0);
    // }
    return (0);
}
