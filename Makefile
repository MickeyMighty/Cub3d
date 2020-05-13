# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loamar <loamar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/04 16:46:41 by loamar            #+#    #+#              #
#    Updated: 2020/05/13 14:54:41 by lorenzoamar      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED =   \033[0;31m
BRED =  \033[1;31m
GREEN = \033[0;32m
BGREE = \033[1;32m
YELLOW =\033[0;33m
BLUE =  \033[0;34m
PINK =  \033[0;35m
CYAN =  \033[0;36m
RESET = \033[0m
WHITE = \033[1m

NAME 			= cub3d

CC				= gcc

RM				= rm -f

#CFLAGS			= -g3 -fsanitize=address -I.
#CFLAGS			= -g -O3 -Wall -Wextra -Werror -I.
#CFLAGS			= -g -O3 -Wall -Wextra -Werror -g3 -fsanitize=address -I.
CFLAGS			= $(CC) -o $(NAME) $(OBJ) -L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd
#CFLAGS			= -g -O3 -g3 -fsanitize=address -I.

LIBFT			=  lib/libft/libft.a

MLX				=  lib/minilibx-linux/libmlx.a
# MLX				=  lib/mlx/libmlx.dylib

LIBS			= -lm -lbsd -lX11 -lXext
# LIBS			= -Lmlx -lmlx -framework OpenGL -framework AppKit -L

SRCS			= 	./srcs/cub3d.c \
					./srcs/parsing/parsing_cub.c \
					./srcs/parsing/parsing_map.c \
					./srcs/parsing/parsutils.c \
					./srcs/parsing/check_cub.c \
					./srcs/parsing/check_map.c \
					./srcs/raycasting.c \
					./srcs/draw.c \
					./srcs/key.c \
					./srcs/move.c \
					./srcs/sprite/sprite.c \
					./srcs/sprite/draw_sprite.c \
					./srcs/utils/error.c \
					./srcs/utils/free.c \
					./srcs/utils/check.c \
					./srcs/utils/init.c \
					./srcs/textures.c \
					./srcs/bmp.c

OBJS			= $(SRCS:.c=.o)

#NAME			= cub3D

# NB = $(words $(SRC))
# NB3 = $(shell echo $$(( $(NB) + 1)))

# I =     0
# K = 0
# J =     0

all:			$(NAME)


$(NAME):		$(OBJS)

				make -C lib/libft
				gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT} ${LIBS}
				#@cp lib/libft/libft.a $(NAME)
				#@mkdir OBJS


#$(MLX):

clean:
				$(MAKE) -C lib/minilibx-linux clean
				$(RM) $(OBJS) $(BONUS_OBJS)
				make clean -C lib/libft
				# $(MAKE) -C lib/mlx clean

fclean:			clean
				$(RM) $(NAME) $(MLX) $(LIBFT)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
