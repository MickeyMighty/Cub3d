/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 16:56:26 by loamar            #+#    #+#             */
/*   Updated: 2020/06/16 02:06:52 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		swap_sprite_data(t_sprite *s1, t_sprite *s2)
{
	float	s2_pos_x;
	float	s2_pos_y;
	float	s2_distance;

	s2_pos_x = s2->pos_x;
	s2_pos_y = s2->pos_y;
	s2_distance = s2->distance;
	s2->order2 = s2->order;
	s2->first_hit2 = s2->first_hit;
	s2->last_hit2 = s2->last_hit;
	s2->pos_x = s1->pos_x;
	s2->pos_y = s1->pos_y;
	s2->distance = s1->distance;
	s2->order = s1->order;
	s2->first_hit = s1->first_hit;
	s2->last_hit = s1->last_hit;
	s1->pos_x = s2_pos_x;
	s1->pos_y = s2_pos_y;
	s1->distance = s2_distance;
	s1->order = s2->order2;
	s1->first_hit = s2->first_hit2;
	s1->last_hit = s2->last_hit2;
}

void		sort_sprites(t_cub3d *cub)
{
	t_sprite	*sprite2;
	t_sprite	*sprite3;

	sprite2 = cub->sprites;
	if (!sprite2->next)
		return ;
	while (sprite2)
	{
		sprite3 = sprite2;
		while (sprite3)
		{
			if (sprite3->next)
				if (sprite3->distance < sprite3->next->distance)
					swap_sprite_data(sprite3, sprite3->next);
			sprite3 = sprite3->next;
		}
		sprite2 = sprite2->next;
	}
}

void		draw_sprite(t_cub3d *cub, t_sprite *s)
{
	cub->sprites->check_x = 0;
	while (s->x_start + cub->sprites->check_x < s->x_end)
	{
		if (s->x_start + cub->sprites->check_x >= s->first_hit && s->x_start +
		cub->sprites->check_x <= s->last_hit)
		{
			s->tex_x = (int)(256 * ((s->x_start + cub->sprites->check_x) -
			(-s->width / 2 + s->sprite_screen_x)) * 512 / s->width) / 256;
			cub->sprites->check_y = 0;
			while (s->y_start + cub->sprites->check_y < s->y_end)
			{
				s->tex_y = ((((s->y_start + cub->sprites->check_y) *
				HALF_SPRITE - cub->map->res_y * 128 + s->height * 128) *
				SPRITE) / s->height) / HALF_SPRITE;
				if (cub->img->data_textures[4][(int)(s->tex_y *
				SPRITE + s->tex_x)] != cub->img->data_textures[4][0])
					cub->img->img_buf[(s->y_start + cub->sprites->check_y) *
					cub->map->res_x + (s->x_start + cub->sprites->check_x)] =
					cub->img->data_textures[4][(int)(s->tex_y * SPRITE +
					s->tex_x)];
				cub->sprites->check_y++;
			}
		}
		cub->sprites->check_x++;
	}
}

void		set_sprite(t_cub3d *cub, t_sprite *sprite, float inverse_coef)
{
	sprite->dist_x = sprite->pos_x - cub->player->pos_x;
	sprite->dist_y = sprite->pos_y - cub->player->pos_y;
	sprite->transform_x = inverse_coef * (cub->player->dir_y * sprite->dist_x -
	cub->player->dir_x * sprite->dist_y);
	sprite->transform_y = inverse_coef * (-cub->player->plane_y *
	sprite->dist_x + cub->player->plane_x * sprite->dist_y);
	sprite->sprite_screen_x = (int)((cub->map->res_x / 2) *
	(1 + sprite->transform_x / sprite->transform_y));
	sprite->height = abs((int)((float)cub->map->res_y / sprite->transform_y));
	sprite->width = abs((int)((float)cub->map->res_y / sprite->transform_y));
	sprite->y_start = ft_max((int)(cub->map->res_y / 2 -
	sprite->height / 2), 0);
	sprite->y_end = ft_min((int)(cub->map->res_y / 2 + sprite->height / 2),
	cub->map->res_y - 1);
	sprite->x_start = ft_max((int)(-sprite->width / 2 +
	sprite->sprite_screen_x), 0);
	sprite->x_end = ft_min((int)(sprite->width / 2 + sprite->sprite_screen_x),
	cub->map->res_x - 1);
}

void		get_sprites(t_cub3d *cub, int column)
{
	t_sprite	*sprite2;
	int			i;

	sprite2 = cub->sprites;
	i = 0;
	while (sprite2)
	{
		if (cub->player->map_x == (int)sprite2->pos_x && cub->player->map_y ==
		(int)sprite2->pos_y)
		{
			if (sprite2->order == 0)
			{
				sprite2->first_hit = column;
				sprite2->distance = (sprite2->pos_x - cub->player->pos_x) *
				(sprite2->pos_x - cub->player->pos_x) + (sprite2->pos_y -
				cub->player->pos_y) * (sprite2->pos_y - cub->player->pos_y);
				sprite2->order = get_last_order(cub->sprites);
			}
			else
				sprite2->last_hit = column;
		}
		sprite2 = sprite2->next;
	}
}
