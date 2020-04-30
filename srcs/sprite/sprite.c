/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:13:48 by loamar            #+#    #+#             */
/*   Updated: 2020/04/30 16:59:10 by lorenzoamar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int 		get_last_order(t_sprite *sprites)
{
	t_sprite	*sprite2;
	int			order;

	sprite2 = sprites;
	order = 0;
	while (sprite2)
	{
		if (sprite2->order > order)
			order = sprite2->order;
		sprite2 = sprite2->next;
	}
	return (order + 1);
}

void		get_sprites(t_cub3d *cub, int column)
{
	t_sprite	*sprite2;
	// int			i;

	sprite2 = cub->sprites;
	// i = 0;
	while (sprite2)
	{
		if (cub->player->map_x == (int)sprite2->pos_x && cub->player->map_y == (int)sprite2->pos_y)
		{
			if (sprite2->order == 0)
			{
				sprite2->first_hit = column;
				sprite2->distance =
				(sprite2->pos_x - cub->player->pos_x)
				* (sprite2->pos_x - cub->player->pos_x)
				+ (sprite2->pos_y - cub->player->pos_y)
				* (sprite2->pos_y - cub->player->pos_y);
				sprite2->order = get_last_order(cub->sprites);
			}
			else
				sprite2->last_hit = column;
		}
		sprite2 = sprite2->next;
	}
}

static void		push_distance(t_cub3d *cub, t_sprite *new_s)
{
	t_sprite *sprite2;
	t_sprite *prev_s;

	sprite2 = cub->sprites;
	prev_s = NULL;
	while (sprite2)
	{
		if (new_s->distance > sprite2->distance)
		{
			if (prev_s)
				prev_s->next = new_s;
			new_s->next = sprite2;
			if (!prev_s)
				cub->sprites = new_s;
			return ;
		}
		prev_s = sprite2;
		sprite2 = sprite2->next;
	}
	prev_s->next = new_s;
}

static int			sort_and_add_sprite(t_cub3d *cub, int x, int y)
{
	t_sprite *new_s;

	if (!(new_s = (t_sprite *)malloc(sizeof(t_sprite))))
		return (0);
	new_s->pos_x = x + 0.5;
	new_s->pos_y = y + 0.5;
	new_s->distance = ((x + 0.5) - cub->player->pos_x) * ((x + 0.5) - cub->player->pos_x)
	+ ((y + 0.5) - cub->player->pos_y) * ((y + 0.5) - cub->player->pos_y);
	new_s->next = NULL;
	new_s->order = 0;
	if (!cub->sprites)
		cub->sprites = new_s;
	else
		push_distance(cub, new_s);
	return (1);
}

static int			parse_sprites(t_cub3d  *cub)
{
	int x;
	int y;

	y = 0;
	while (y < cub->map->size_y)
	{
		x = 0;
		while (x < cub->map->size_x[y])
		{
			if (cub->map->map[y][x] == 2 && !sort_and_add_sprite(cub, x, y))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int			detect_sprites(t_cub3d  *cub)
{
	int		nb_sprite;

	nb_sprite = 0;
	if (nb_sprite == cub->map->nb_sprites)
		return (1);
	return (parse_sprites(cub));
}
