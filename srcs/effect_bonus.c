// #include "../includes/cub3d.h"
//
// //////////////////BONUS//////////////////////////////
// static int			count_sprites(t_cub3d *cub)
// {
// 	int x;
// 	int y;
// 	int nb_sprite;
//
// 	y = -1;
// 	nb_sprite = 0;
// 	while (++y < cub->map->size_y)
// 	{
// 		x = -1;
// 		while (++x < cub->map->size_x)
// 		{
// 			if (cub->map->map[y][x] == 2)
// 				nb_sprite += 1;
// 		}
// 	}
// 	return (nb_sprite);
// }
//
// /*
// ** loop | store hit col on res_x
// */
//
// static int			get_last_order(t_sprite *sprites)
// {
// 	t_sprite	*s;
// 	int			order;
//
// 	s = sprites;
// 	order = 0;
// 	while (s)
// 	{
// 		if (s->order > order)
// 			order = s->order;
// 		s = s->next;
// 	}
// 	return (order + 1);
// }
//
// /*
// ** store hit col on res_x
// */
//
// void		get_sprites(t_cub3d *cub, int hit_col)
// {
// 	t_sprite	*s;
// 	int			i;
//
// 	s = cub->sprites;
// 	i = 0;
// 	while (s)
// 	{
// 		if (cub->player->map_x == (int)s->pos_x && cub->player->map_y == (int)s->pos_y)
// 		{
// 			if (s->order == 0)
// 			{
// 				s->first_hit_col = hit_col;
// 				s->distance = (s->pos_x - cub->player->pos_x) * (s->pos_x - cub->player->pos_x)
// 					+ (s->pos_y - cub->player->pos_y) * (s->pos_y - cub->player->pos_y);
// 				s->order = get_last_order(cub->sprites);
// 			}
// 			else
// 				s->last_hit_col = hit_col;
// 		}
// 		s = s->next;
// 	}
// }
//
// /*
// ** loop | swap data
// */
//
// static void		swap_sprite_data(t_sprite *s1, t_sprite *s2)
// {
// 	float	s2_pos_x;
// 	float	s2_pos_y;
// 	float	s2_distance;
// 	int		s2_i[3];
//
// 	s2_pos_x = s2->pos_x;
// 	s2_pos_y = s2->pos_y;
// 	s2_distance = s2->distance;
// 	s2_i[0] = s2->order;
// 	s2_i[1] = s2->first_hit_col;
// 	s2_i[2] = s2->last_hit_col;
// 	s2->pos_x = s1->pos_x;
// 	s2->pos_y = s1->pos_y;
// 	s2->distance = s1->distance;
// 	s2->order = s1->order;
// 	s2->first_hit_col = s1->first_hit_col;
// 	s2->last_hit_col = s1->last_hit_col;
// 	s1->pos_x = s2_pos_x;
// 	s1->pos_y = s2_pos_y;
// 	s1->distance = s2_distance;
// 	s1->order = s2_i[0];
// 	s1->first_hit_col = s2_i[1];
// 	s1->last_hit_col = s2_i[2];
// }
//
// /*
// ** loop | sort
// */
//
// void		sort_sprites(t_cub3d *cub)
// {
// 	t_sprite *s;
// 	t_sprite *elem;
//
// 	s = cub->sprites;
// 	if (!s->next)
// 		return ;
// 	while (s)
// 	{
// 		elem = s;
// 		while (elem)
// 		{
// 			if (elem->next)
// 				if (elem->distance < elem->next->distance)
// 					swap_sprite_data(elem, elem->next);
// 			elem = elem->next;
// 		}
// 		s = s->next;
// 	}
// }
//
// static void		push_distance(t_cub3d *cub, t_sprite *new_s)
// {
// 	t_sprite *s;
// 	t_sprite *prev_s;
//
// 	s = cub->sprites;
// 	prev_s = NULL;
// 	while (s)
// 	{
// 		if (new_s->distance > s->distance)
// 		{
// 			if (prev_s)
// 				prev_s->next = new_s;
// 			new_s->next = s;
// 			if (!prev_s)
// 				cub->sprites = new_s;
// 			return ;
// 		}
// 		prev_s = s;
// 		s = s->next;
// 	}
// 	prev_s->next = new_s;
// }
//
// /*
// ** init | create sorted linked list
// */
//
// static int			sort_and_add_sprite(t_cub3d *cub, int x, int y)
// {
// 	t_sprite *new_s;
//
// 	if (!(new_s = (t_sprite *)malloc(sizeof(t_sprite))))
// 		return (0);
// 	new_s->pos_x = x + .5;
// 	new_s->pos_y = y + .5;
// 	new_s->distance = ((x + .5) - cub->player->pos_x) * ((x + .5) - cub->player->pos_x)
// 	+ ((y + .5) - cub->player->pos_y) * ((y + .5) - cub->player->pos_y);
// 	new_s->next = NULL;
// 	new_s->order = 0;
// 	if (!cub->sprites)
// 		cub->sprites = new_s;
// 	else
// 		push_distance(cub, new_s);
// 	return (1);
// }
//
// /*
// ** init | parse_sprites
// */
//
// static int			parse_sprites(t_cub3d *cub)
// {
// 	int x;
// 	int y;
//
// 	y = -1;
// 	while (++y < cub->map->size_y)
// 	{
// 		x = -1;
// 		while (++x < cub->map->size_x)
// 		{
// 			if (cub->map->map[y][x] == 2 && !sort_and_add_sprite(cub, x, y))
// 				return (0);
// 		}
// 	}
// 	return (1);
// }
//
// int			detect_sprites(t_cub3d *cub)
// {
// 	int		nb_sprite;
//
// 	nb_sprite = 0;
// 	if (!(nb_sprite = count_sprites(cub)))
// 		return (1);
// 	return (parse_sprites(cub));
// }
//
// /*
// ** loop | prepare sprite drawing
// */
//
// static void		prepare_sprite(t_cub3d *cub, t_sprite *s, float inverse_coef)
// {
// 	s->dist_x = s->pos_x - cub->player->pos_x;
// 	s->dist_y = s->pos_y - cub->player->pos_y;
// 	s->corrected_dist_x = inverse_coef *
// 		(cub->player->dir_y * s->dist_x - cub->player->dir_x * s->dist_y);
// 	s->corrected_dist_y = inverse_coef * (-cub->player->plane_y *
// 		s->dist_x + cub->player->plane_x * s->dist_y);
// 	s->sprite_screen_x = (int)((cub->map->res_x / 2) *
// 		(1 + s->corrected_dist_x / s->corrected_dist_y));
// 	s->height_in_px = abs((int)((float)cub->map->res_y / s->corrected_dist_y));
// 	s->width_in_px = abs((int)((float)cub->map->res_y / s->corrected_dist_y));
// 	s->y_start = ft_max((int)(cub->map->res_y / 2 - s->height_in_px / 2), 0);
// 	s->y_end = ft_min((int)(cub->map->res_y /
// 		2 + s->height_in_px / 2), cub->map->res_y - 1);
// 	s->x_start = ft_max((int)(-s->width_in_px /
// 		2 + s->sprite_screen_x), 0);
// 	s->x_end = ft_min((int)(s->width_in_px /
// 		2 + s->sprite_screen_x), cub->map->res_x - 1);
// }
//
// static void		draw_sprite(t_cub3d *cub, t_sprite *s)
// {
// 	int			x;
// 	int			y;
//
// 	x = -1;
// 	while (s->x_start + ++x < s->x_end)
// 	{
// 		if (s->x_start + x >= s->first_hit_col && s->x_start +
// 		x <= s->last_hit_col)
// 		{
// 			s->tex_x = (int)(256 * ((s->x_start + x) - (-s->width_in_px /
// 			2 + s->sprite_screen_x)) * 512 / s->width_in_px) / 256;
// 			y = -1;
// 			while (s->y_start + ++y < s->y_end)
// 			{
// 				s->tex_y = ((((s->y_start + y) * 256 - cub->map->res_y * 128 +
// 				s->height_in_px * 128) * 512) / s->height_in_px) / 256;
// 				if (cub->img->data_textures[4][(int)(s->tex_y * 512 + s->tex_x)]
// 				!= cub->img->data_textures[4][0])
// 					cub->img->img_buf[(s->y_start + y) * cub->map->res_x + (s->x_start +
// 					x)] = cub->img->data_textures[4][(int)(s->tex_y * 512 + s->tex_x)];
// 			}
// 		}
// 	}
// }
//
// /*
// ** draw_sprites
// */
//
// void		draw_sprites(t_cub3d *cub)
// {
// 	t_sprite	*s;
// 	float		inverse_coef;
//
// 	sort_sprites(cub);
// 	s = cub->sprites;
// 	inverse_coef = 1.0 / (cub->player->plane_x * cub->player->dir_y - cub->player->plane_y * cub->player->dir_x);
// 	while (s)
// 	{
// 		if (s->order > 0)
// 		{
// 			prepare_sprite(cub, s, inverse_coef);
// 			draw_sprite(cub, s);
// 			s->order = 0;
// 		}
// 		s = s->next;
// 	}
// }
