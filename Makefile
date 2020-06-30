# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loamar <loamar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/04 16:46:41 by loamar            #+#    #+#              #
#    Updated: 2020/06/28 17:46:32 by lorenzoamar      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= cub3d

CC				= gcc

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror -I.

LIBFT			=  lib/libft/libft.a

LIB_LINUX		= -I/usr/local/include -L/usr/local/lib -lmlx -L/usr/include -lm -lbsd -lX11 -lXext
LIB_MAC			= -I/usr/local/include -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
LIBS			= $(LIB_MAC)

SRCS			= 	./srcs/cub3d.c \
					./srcs/parsing/parsing_cub.c \
					./srcs/parsing/parsing_map.c \
					./srcs/parsing/parsutils.c \
					./srcs/parsing/check_cub.c \
					./srcs/parsing/check_map.c \
					./srcs/parsing/get_pos.c \
					./srcs/raycasting/raycasting.c \
					./srcs/visual/draw.c \
					./srcs/displacements/key.c \
					./srcs/displacements/move.c \
					./srcs/sprite/sprite.c \
					./srcs/sprite/draw_sprite.c \
					./srcs/utils/error.c \
					./srcs/utils/free.c \
					./srcs/utils/check.c \
					./srcs/utils/init.c \
					./srcs/utils/init2.c \
					./srcs/visual/textures.c \
					./srcs/visual/bmp.c

OBJS			= $(SRCS:.c=.o)

all:			$(NAME)


$(NAME):		$(OBJS)
				make -C lib/libft
				gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT} ${LIBS}

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)
				make clean -C lib/libft

fclean:			clean
				$(RM) $(NAME) $(LIBFT)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
