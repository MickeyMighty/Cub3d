/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 23:43:14 by loamar            #+#    #+#             */
/*   Updated: 2020/05/12 18:49:56 by lorenzoamar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include "../lib/mlx/mlx.h"
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
// # define GREEN 0x00ff00
# define BLACK 0x000000
# define BROWN 0x4d2600
// # define DARK_BLUE
// # define GREY2

/*
** MOVE
*/

# define KEY_CTRL 256
# define KEY_SHIFT 257
# define KEY_UP 126
# define KEY_W 13
# define KEY_DOWN 125
# define KEY_S 1
# define KEY_LEFT 123
# define KEY_A 0
# define KEY_RIGHT 124
# define KEY_D 2
# define KEY_F 3
# define KEY_G 5
# define KEY_PLUS 69
# define KEY_ESC 53
# define KEY_E 14
# define KEY_Q 12
# define KEY_V 9

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

# define widthtex 64
# define heightex 64
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
** ###################
** ## APPLICATION : ##
** ###################
*/

typedef struct	s_cub3d
{
	struct s_application	*game;
	struct s_player 		*player;
	struct s_draw 			*img;
	struct s_map 			*map;
	struct s_sprite 		*sprites;

}				t_cub3d;

typedef struct	s_application
{
	int 		size_x;
	int 		size_y;
	char 		*title;

	void 		*mlx_ptr;
	void 		*win_ptr;
	void 		*img_ptr;
	// int 		*img_buf;

	int 		bits_per_pixels;
	int 		bits_per_pixels2;
	int 		bits_per_pixels3;
	int 		bits_per_pixels4;
	int 		bits_per_pixels5;
	int 		bits_per_pixels6;
	int 		size_line;
	int 		size_line2;
	int 		size_line3;
	int 		size_line4;
	int 		size_line5;
	int 		size_line6;
	int 		endian;
	int 		endian2;
	int 		endian3;
	int 		endian4;
	int 		endian5;
	int 		endian6;
	char		*pixels;
	char		*pixels2;
	char		*pixels3;
	char		*pixels4;
	char		*pixels5;
	char		*pixels6;

	int 		bitpx;

	float		frametime;

	int 		save;

}				t_application;

/*
** ###########
** ## MAP : ##
** ###########
*/

typedef struct s_map
{
	int 	error;
	int 	nb_sprites;
	int 	*sprite_order;
	float	*sprite_distance;

	char 	*beta_res_x;
	char 	*beta_res_y;
	int 	res_x;
	int 	res_y;
	int		size;
	int		size2;
	int		size_space;

	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;

	char	*sprite_texture;

	char	*ceiling_color;
	int 	ceiling_addr;
	char	*floor_color;
	int 	floor_addr;

	int 	ticket;

	int 	width_map;
	int 	heigh_map;

	int 	check;
	int 	check_pos;
	int 	check_space;

	int 	size_x_max;
	int 	*size_x;
	int 	size_y;

	int 	pos_x;
	int 	check_pos_x;
	int 	check_pos_y;
	int 	pos_y;
	int		**map;
	char	**map_beta;
}				t_map;

/*
** ##############
** ## PLAYER : ##
** ##############
*/

typedef struct s_player
{
	//text floor and ceiling
	// int 	dist_current;
	// int 	floor_x
	// direction x et direction y
	float	dir_x;
	float 	dir_y;

	int 	if_sprite;

	float	olddir_x;
	float	oldplane_x;

	float 	pos_x;
	float 	pos_y;

	float 	raydir_x;
	float 	raydir_y;

	// test
	float 	raydir_x0;
	float 	raydir_y0;
	float 	raydir_x1;
	float 	raydir_y1;
	int 	p;
	float 	posz;
	float 	rowdistance;
	float 	floor_step_x;
	float 	floor_step_y;
	float 	floor_x;
	float 	floor_y;
	int 	cell_x;
	int 	cell_y;
	int 	tx;
	int 	ty;
	int 	checkerboardpattern;
	// fin test

// plane x et plane y
	float	plane_x;
	float	plane_y;

//// longueur du rayon d'un côté x ou y au x ou y suivant
	float	sidedist_x;
	float	sidedist_y;

	float	deltadist_x;
	float	deltadist_y;


	int 	step_x;
	int 	step_y;

	float	camera_x;
	float	camera_y;
// ou l'on se s0itue dans la map
	int		map_x;
	int		map_y;

	float 	time;
	float 	oldtime;

	int 	id;

	float 	ray_pos_x;
	float 	ray_pos_y;

	float 	*distances;
	int 	*sides;
	float 	*hit_wall_x;
	float 	*hit_sprite_x;
//// la version 2d raycaster du plan de la caméra

	// float	plan_x;
	// float	plan_y;
// si un côté x ou un côté y d'un mur a été touché
	float 	side_x;
	float	side_y;

	float	move_speed;
	float	rot_speed;

// y a-t-il eu un coup au mur?
	int		hit;

// un mur NS ou EW a-t-il été touché?
	int 	side;

	int 	*tex_x;
// quelle direction pour avancer dans la direction x ou y (+1 ou -1)
	float	perpwalldist;

	unsigned int 	move_s;
	unsigned int 	move_b;
	unsigned int 	move_r;
	unsigned int 	rotate_r;
	unsigned int 	move_l;
	unsigned int 	rotate_l;
	unsigned int 	move_fly;
	unsigned int 	move_faster;
	unsigned int 	squat;
	unsigned int 	bug_vision;
	unsigned int 	bug_empty;
}				t_player;

/*
** ##############
** ## VECTOR : ##
** ##############
*/

typedef struct s_draw
{
	int 	lineheight;
	int 	wall_start;
	int 	wall_end;
	int 	color;
	int 	*img_buf;
	void 	**xpm_to_img;
	int 	**data_textures;
	// char	**path_textures;


	unsigned char r;
	unsigned char g;
	unsigned char b;
}				t_draw;

/*
** ##############
** ## VECTOR : ##
** ##############
*/


typedef struct s_sprite
{
	float 	pos_x;
	float 	pos_y;
	float 	dist_x;
	float	dist_y;
	// int 	first_hit_col;
	int 	first_hit;
	int 	first_hit2;
	// int 	last_hit_col;
	int 	last_hit;
	int 	last_hit2;
	int 	x_start;
	int 	y_start;
	int 	x_end;
	int 	y_end;
	// int 	height_in_px;
	int 	height;
	// int 	width_in_px;
	int 	width;
	int 	sprite_screen_x;
	float 	transform_x;
	// float	corrected_dist_x;
	float 	transform_y;
	// float	corrected_dist_y;
	// float 	inv_det;
	float	tex_x;
	float	tex_y;
	int		order;
	int		order2;
	float	distance;
	struct s_sprite		*next;
}				t_sprite;

// typedef struct s_sprite
// {
// 	int		first_hit;
// 	int		last_hit;
// 	int 	pos_x;
// 	int 	pos_y;
// 	int 	first_hit;
// 	int 	last_hit;
// 	int 	draw_start_x;
// 	int 	draw_start_y;
// 	int 	draw_end_x;
// 	int 	draw_end_y;
// 	int 	height;
// 	int 	width;
// 	int 	tex_y;
// 	int 	tex_x;
// 	int 	sprite_screen_x;
// 	float 	transform_x;
// 	float 	transform_y;
// 	float 	inv_det;
// 	float	tex_x;
// 	float	tex_y;
// 	int		order;
// 	float	distance;
// 	struct s_sprite		*next;
// }				t_sprite;

// typedef struct s_sprite
// {
// 	int					order;
// 	float				pos_x;
// 	float				old_pos_x;
// 	float				pos_y;
// 	float				old_pos_y;
// 	float				dist_x;
// 	float				dist_y;
// 	float				corrected_dist_x;
// 	float				corrected_dist_y;
// 	int					sprite_screen_x;
// 	int					height_in_px;
// 	int					width_in_px;
// 	int					x_start;
// 	int					x_end;
// 	int					y_start;
// 	int					y_end;
// 	int					tex_x;
// 	int					tex_y;
// 	// struct s_sprite		*next;
//
// }				t_sprite;
// typedef struct s_sprite
// {
// 	int 	order;
// 	float 	x;
// 	float 	y;
// 	int 	texture;
// }				t_sprite;

/*
** ############################################################################
*/

/*
** parsing/parsing.c
*/

// char 			*get_cub_string(int argc, char **argv);
int 			parsing_cub3d(int argc, char **argv, t_cub3d *cub);
void			ft_strdel(char **as);
int     		parsing_map(t_cub3d *cub, char *str_cub);

/*
** check/init.c
*/

void 	init_map(t_map *map);
int	 	init_player(t_player *player, t_map *map);
t_draw			*malloc_image(t_draw *img);
t_map    		*malloc_map(t_map *map);
t_application   *malloc_application(t_application *app);
t_player   		*malloc_player(t_player *player);
t_cub3d 		*malloc_cub(t_cub3d *cub);
t_sprite   		*malloc_sprite(t_sprite *sprite);


/*
** parsing/parsutils.c
*/

char			*str_end_check(char *str, char *end);
int 			ft_ispos(char c);
void 			ft_find_size(t_map *map, char *str_cub, int index);
int 			check_line_map(char *str_cub, int index);
int 			ft_is_map(char c);

/*
** parsing/parsutils2.c
*/

int     check_map_param(char *str_cub, int index);
int 	ft_get_my_ticket(t_map *map, char *str_cub, int index);
void 	get_map_param(t_map *map, char *str_cub, int index);
int     ft_nowhitespace(char *str, int index, t_map *map);
int     data_check(t_map *map);

// t_map   		*init_map(t_map *map);
int 		    check_argc(int argc, char **argv);

/*
** key.c
*/

void    move(t_player *player, t_map *map);
int     key_press(int key, t_player *player);
int     key_release(int key, t_player *player);

/*
** raycasting.c
*/

// void     ray_casting(t_player *player, t_map *map, t_application *game, t_draw *img);
int     ray_casting(t_cub3d *cub);

/*
** draw.c
*/

int     draw_buffer(t_cub3d *cub);

/*
** error.c
*/

int 		get_text(t_cub3d *cub);

/*
** error.c
*/

// int				ft_error_cub(t_application *cub3d, char *msg);
// int				ft_error_map(t_map *map, char *msg);
// int				Error_msg(void);
// int				ft_error_player(t_player *player, char *msg);
// int				ft_error_image(t_draw *img, char *msg);
int 	ft_error(t_cub3d *cub, char *msg);
// int		on_exit(t_cub3d *cub);

/*
** free.c
*/

void    free_split(char **str);

/*
** sprite.c
*/

int			detect_sprites(t_cub3d  *cub);
// void	sprites(t_cub3d *cub);
void		get_sprites(t_cub3d *cub, int column);

void     draw_sprites(t_cub3d *cub);
// void    get_sprite_no_so(t_player *player, int column, int step_x, int side);
// void    get_sprite_we_ea(t_player *player, int column, int step_y, int side);

/*
** useless_bonus.c
*/

int    moove_fly(t_cub3d *cub, int column);
int 	get_text_bug(t_cub3d *cub);
int     bug_vision(t_cub3d *cub, int check_x, int check_y, int wall_size);


/*
** BMP
*/

int			create_bmp(t_cub3d *cub);
int			check_map(t_cub3d *cub);
int     check_arg(int argc, char **argv);


//int				get_args(int argc, char **argv);

#endif
