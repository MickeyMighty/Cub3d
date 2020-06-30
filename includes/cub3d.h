/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 23:43:14 by loamar            #+#    #+#             */
/*   Updated: 2020/06/30 11:52:13 by lorenzoamar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER_SIZE 2
# include "../lib/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <math.h>

/*
** COLOR
*/

# define BUG "textures/sand.xpm"
# define WHITE 0xffffff
# define YELLOW 0xff0000
# define GREEN 0x00cc00
# define RED 0xff0000
# define BLUE 0x0000ff
# define GREY 0x808080
# define BLACK 0x000000
# define BROWN 0x4d2600

/*
** MOVE
*/

# define KEY_CTRL 65507
# define KEY_UP 65362
# define KEY_W 119
# define KEY_DOWN 65364
# define KEY_S 115
# define KEY_LEFT 65361
# define KEY_A 97
# define KEY_RIGHT 65363
# define KEY_D 100
# define KEY_F 3
# define KEY_G 5
# define KEY_PLUS 65451
# define KEY_ESC 65307
# define KEY_E 101
# define KEY_Q 113

/*
** TICKET MAP
*/

# define R 1
# define NO 2
# define SO 3
# define WE 4
# define EA 5
# define S 6
# define F 7
# define C 8

/*
** TEXTURES
*/

# define WIDTHTEX 64
# define HEIGHTEX 64
# define SPRITE 512
# define HALF_SPRITE 256
# define TIER_SPRITE 128

/*
** ############################################################################
** #                                                                          #
** # STRUCTURE :                                                              #
** #                                                                          #
** ############################################################################
*/

/*
** #############
** ## CUB3D : ##
** ############
*/

typedef struct				s_cub3d
{
	struct s_application	*game;
	struct s_player			*player;
	struct s_draw			*img;
	struct s_map			*map;
	struct s_sprite			*sprites;
}							t_cub3d;

/*
** #############
** ## GAME : ##
** ############
*/

typedef struct				s_application
{
	int						size_x;
	int						size_y;
	void					*mlx_ptr;
	void					*win_ptr;
	void					*img_ptr;
	int						bits_per_pixels;
	int						bits_per_pixels2;
	int						bits_per_pixels3;
	int						bits_per_pixels4;
	int						bits_per_pixels5;
	int						bits_per_pixels6;
	int						size_line;
	int						size_line2;
	int						size_line3;
	int						size_line4;
	int						size_line5;
	int						size_line6;
	int						endian;
	int						endian2;
	int						endian3;
	int						endian4;
	int						endian5;
	int						endian6;
	char					*pixels;
	char					*pixels2;
	char					*pixels3;
	char					*pixels4;
	char					*pixels5;
	char					*pixels6;
	int						bitpx;
	float					frametime;
	int						save;
}							t_application;

/*
** ###########
** ## MAP : ##
** ###########
*/

typedef struct				s_map
{
	int						parsing_check;
	int						error;
	int						nb_sprites;
	int						*sprite_order;
	float					*sprite_distance;
	char					*beta_res_x;
	char					*beta_res_y;
	int						res_x;
	int						res_y;
	int						size;
	int						size2;
	int						size_space;
	char					*north_texture;
	char					*south_texture;
	char					*west_texture;
	char					*east_texture;
	char					*sprite_texture;
	char					*ceiling_color;
	int						ceiling_addr;
	char					*floor_color;
	int						floor_addr;
	int						ticket;
	int						width_map;
	int						heigh_map;
	int						check;
	int						check_pos;
	int						check_space;
	int						check_line;
	int						size_x_max;
	int						*size_x;
	int						size_y;
	int						nb;
	int						target;
	int						pos_x;
	int						check_pos_x;
	int						check_pos_y;
	int						pos_y;
	int						**map;
	char					**map_beta;
}							t_map;

/*
** ##############
** ## PLAYER : ##
** ##############
*/

typedef struct				s_player
{
	float					dir_x;
	float					dir_y;
	int						if_sprite;
	float					olddir_x;
	float					oldplane_x;
	float					pos_x;
	float					pos_y;
	float					raydir_x;
	float					raydir_y;
	float					plane_x;
	float					plane_y;
	float					sidedist_x;
	float					sidedist_y;
	float					deltadist_x;
	float					deltadist_y;
	float					old_dir_x;
	float					old_plane_x;
	int						step_x;
	int						step_y;
	float					camera_x;
	float					camera_y;
	int						map_x;
	int						map_y;
	float					time;
	float					oldtime;
	int						id;
	float					ray_pos_x;
	float					ray_pos_y;
	float					*distances;
	int						*sides;
	float					*hit_wall_x;
	float					*hit_sprite_x;
	float					side_x;
	float					side_y;
	float					move_speed;
	float					rot_speed;
	int						hit;
	int						side;
	int						*tex_x;
	float					perpwalldist;
	unsigned int			move_s;
	unsigned int			move_b;
	unsigned int			move_r;
	unsigned int			rotate_r;
	unsigned int			move_l;
	unsigned int			rotate_l;
	unsigned int			move_faster;
}							t_player;

/*
** ##############
** ## IMAGE  : ##
** ##############
*/

typedef struct				s_draw
{
	int						size_error;
	int						lineheight;
	int						wall_start;
	int						wall_end;
	int						color;
	int						*img_buf;
	void					**xpm_to_img;
	int						**data_textures;
	unsigned char			r;
	unsigned char			g;
	unsigned char			b;
}							t_draw;

/*
** ##############
** ## SPRITE : ##
** ##############
*/

typedef struct				s_sprite
{
	float					pos_x;
	float					pos_y;
	float					dist_x;
	float					dist_y;
	int						first_hit;
	int						first_hit2;
	int						last_hit;
	int						last_hit2;
	int						x_start;
	int						y_start;
	int						x_end;
	int						y_end;
	int						height;
	int						width;
	int						sprite_screen_x;
	float					transform_x;
	float					transform_y;
	int						check_x;
	int						check_y;
	float					tex_x;
	float					tex_y;
	int						order;
	int						order2;
	float					distance;
	struct s_sprite			*next;
}							t_sprite;

/*
** ############################################################################
*/

/*
** cub3d.c
*/

int							get_text(t_cub3d *cub);

/*
** displacements/key.c.c
*/

int							key_press(int key, t_cub3d *cub);
int							key_release(int key, t_cub3d *cub);

/*
** displacements/move.c
*/

void						move(t_player *player, t_map *map);

/*
** parsing/check_cub.c
*/

int							check_map_param(char *str_cub, int index);
int							ft_get_my_ticket(t_map *map, char *str_cub,
							int index);
void						get_map_param(t_map *map, char *str_cub,
							int index);
int							ft_nowhitespace(char *str, int index, t_map *map,
							int type);
int							data_check(t_map *map);

/*
** parsing/check_map.c
*/

int							check_map(t_cub3d *cub);
int							size_of_ticket(t_map *map);
void						size_and_param(t_map *map, char *str_cub,
							int index);
int							check_loop(t_map *map);

/*
** parsing/get_pos.c
*/

int							check_map_beta(t_map *map, char *str_cub);
int							ft_ispos(char c);
void						get_pos_next(t_cub3d *cub, char pos);
void						get_pos(t_cub3d *cub, char pos);
int							loop_index(t_cub3d *cub, int index, char *str_cub);

/*
** parsing/parsing_cub.c
*/

int							color(char *col, int *dest);
int							parsing_cub3d(int argc, char **argv, t_cub3d *cub);
int							fill_map(t_map *map, char *str_cub, int index);
/*
** parsing/parsing_map.c
*/

int							parsing_map(t_cub3d *cub);
int							parsing_map2(t_cub3d *cub, char *str_cub);

/*
** parsing/parsutils.c
*/

char						*str_end_check(char *str, char *end);
void						ft_find_size(t_map *map, char *str_cub, int index);
int							check_parsing_cub(t_cub3d *cub, int check,
							int index, char *str_cub);
int							ft_is_map(char c);

/*
** raycasting/raycasting.c
*/

int							ray_casting(t_cub3d *cub);

/*
** sprite/draw_sprite.c
*/

void						swap_sprite_data(t_sprite *s1, t_sprite *s2);
void						sort_sprites(t_cub3d *cub);
void						draw_sprite(t_cub3d *cub, t_sprite *s);
void						set_sprite(t_cub3d *cub, t_sprite *sprite,
							float inverse_coef);
void						get_sprites(t_cub3d *cub, int column);

/*
** sprite/sprite.c
*/

int							get_last_order(t_sprite *sprites);
int							detect_sprites(t_cub3d *cub);

/*
** utils/check.c
*/

int							check_arg(int argc, char **argv);
int							cub3d_exit(t_cub3d *cub);
void						error_msg(int error, char *msg);

/*
** utils/error.c
*/

int							ft_error(t_cub3d *cub, char *msg, int error);

/*
** utils/free.c
*/

void						free_split(char **str);
void						free_tab_int(int **tab, int size);
void						free_sprite(t_cub3d *cub);
void						free_game(t_cub3d *cub, int error);

/*
** utils/init.c
*/

void						init_map(t_map *map);
t_cub3d						*malloc_cub(t_cub3d *cub);

/*
** utils/init2.c
*/

int							init_player(t_player *player, t_map *map);
void						init_sprite(t_sprite *sprites);
void						init_img(t_draw *img);

/*
** visual/bmp.c
*/

int							create_bmp(t_cub3d *cub);

/*
** visual/draw.c
*/

int							draw_buffer(t_cub3d *cub);
void						draw_sprites(t_cub3d *cub);

/*
** visual/textures.c
*/

int							display_textures(t_cub3d *cub, int res_x, int res_y,
							int i);

#endif
