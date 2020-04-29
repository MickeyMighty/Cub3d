/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 02:05:05 by loamar            #+#    #+#             */
/*   Updated: 2020/03/11 03:21:13 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		swap_sprite_data(t_sprite *s1, t_sprite *s2)
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

static void		sort_sprites(t_cub3d *cub)
{
	t_sprite 	*sprite2;
	t_sprite 	*sprite3;

	sprite2 = cub->sprites;
	if (!sprite2->next)
		return ;
	while (sprite2)
	{
		sprite3 = sprite2;
		while (sprite3)
		{
			if (sprite3->next)
			{
				if (sprite3->distance < sprite3->next->distance)
					swap_sprite_data(sprite3, sprite3->next);
			}
			sprite3 = sprite3->next;
		}
		sprite2 = sprite2->next;
	}
}

static void		draw_sprite(t_cub3d *cub, t_sprite *s)
{
	int			check_x;
	int			check_y;

	check_x = 0;
	while (s->x_start + check_x < s->x_end)
	{
		if (s->x_start + check_x >= s->first_hit && s->x_start + check_x <= s->last_hit)
		{
			s->tex_x = (int)(HALF_SPRITE * ((s->x_start + check_x) - (-s->width /
			2 + s->sprite_screen_x)) * SPRITE / s->width) / HALF_SPRITE;
			check_y = 0;
			while (s->y_start + check_y < s->y_end)
			{
				s->tex_y = ((((s->y_start + check_y) * HALF_SPRITE - cub->map->res_y * 128 +
				s->height * 128) * SPRITE) / s->height) / HALF_SPRITE;
				if (cub->img->data_textures[4][(int)(s->tex_y * SPRITE + s->tex_x)]
				!= cub->img->data_textures[4][0])
					cub->img->img_buf[(s->y_start + check_y) * cub->map->res_x + (s->x_start +
					check_x)] = cub->img->data_textures[4][(int)(s->tex_y * SPRITE + s->tex_x)];
				check_y++;
			}
		}
		check_x++;
	}
}

static void		set_sprite(t_cub3d *cub, t_sprite *sprite, float inverse_coef)
{
	sprite->dist_x = sprite->pos_x - cub->player->pos_x;
	sprite->dist_y = sprite->pos_y - cub->player->pos_y;
	sprite->transform_x = inverse_coef *
		(cub->player->dir_y * sprite->dist_x - cub->player->dir_x * sprite->dist_y);
		//ligne pour faire les contours
	// sprite->transform_x = (cub->player->dir_y * sprite->dist_x - cub->player->dir_x * sprite->dist_y);
	sprite->transform_y = inverse_coef * (-cub->player->plane_y *
	sprite->dist_x + cub->player->plane_x * sprite->dist_y);
	// sprite->transform_y = (-cub->player->plane_y *
	// sprite->dist_x + cub->player->plane_x * sprite->dist_y);
	sprite->sprite_screen_x = (int)((cub->map->res_x / 2) *
		(1 + sprite->transform_x / sprite->transform_y));
	sprite->height = abs((int)((float)cub->map->res_y / sprite->transform_y));
	sprite->width = abs((int)((float)cub->map->res_y / sprite->transform_y));
	sprite->y_start = ft_max((int)(cub->map->res_y / 2 - sprite->height / 2), 0);
	sprite->y_end = ft_min((int)(cub->map->res_y /
		2 + sprite->height / 2), cub->map->res_y - 1);
	sprite->x_start = ft_max((int)(-sprite->width /
		2 + sprite->sprite_screen_x), 0);
	sprite->x_end = ft_min((int)(sprite->width /
		2 + sprite->sprite_screen_x), cub->map->res_x - 1);
	// sprite->x_end = ft_min((int)(sprite->width / 2 + sprite->sprite_screen_x), cub->map->res_x - 1);
}

void		draw_sprites(t_cub3d *cub)
{
	t_sprite	*sprite2;
	float		inverse_coef;

	sort_sprites(cub);
	sprite2 = cub->sprites;
	inverse_coef = 1.0 / (cub->player->plane_x * cub->player->dir_y - cub->player->plane_y * cub->player->dir_x);
	while (sprite2)
	{
		if (sprite2->order > 0)
		{
			set_sprite(cub, sprite2, inverse_coef);
			draw_sprite(cub, sprite2);
			sprite2->order = 0;
		}
		sprite2 = sprite2->next;
	}
}
