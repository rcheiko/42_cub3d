# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/20 15:58:56 by rcheiko           #+#    #+#              #
#    Updated: 2021/04/20 15:59:36 by rcheiko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

SRCS		=	map/check_map.c map/ft_split.c map/ft_utils.c \
				map/ft_utils_2.c map/ft_utils_3.c map/get_next_line_utils.c \
				map/get_next_line.c map/pars_map.c map/pars_widget_map_1.c \
				map/pars_widget_map_2.c map/pars_widget_map_3.c \
				map/trait_pars.c \
				fct_init_2.c fct_init.c fill_sprite.c fill_texture.c \
				ft_keyhook.c ft_movement.c ft_utils.c ft_utils_2.c \
				init_struct.c minimap.c ray_casting.c ray_casting_2.c \
				ray_casting_3.c screenshot.c sprite_init.c sprite.c wall.c \
				free.c

SRCS_BONUS	=	map/check_map.c map/ft_split.c map/ft_utils.c \
				map/ft_utils_2.c map/ft_utils_3.c map/get_next_line_utils.c \
				map/get_next_line.c map/pars_map.c map/pars_widget_map_1.c \
				map/pars_widget_map_2.c map/pars_widget_map_3.c \
				map/trait_pars.c \
				fct_init_2.c fct_init_bonus.c fill_sprite.c fill_texture.c \
				ft_keyhook.c ft_movement.c ft_utils.c ft_utils_2.c \
				init_struct.c minimap.c ray_casting.c ray_casting_2.c \
				ray_casting_3.c screenshot.c sprite_init.c sprite.c wall.c \
				barre_de_vie.c free.c

OBJS		=	${SRCS:.c=.o}

OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

PATHSCREEN	=	./screenshot.bmp

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -I./includes

LINKFLAGS	=	-lmlx -framework OpenGL -framework AppKit

PATHMLX		=	./minilibx/libmlx.a

RM			=	rm -f

ifdef BONUS
${NAME}	:	${OBJS_BONUS}
			${CC} -o ${NAME} $^ ${LINKFLAGS} ${PATHMLX}
else
${NAME} :	${OBJS}
			${CC} -o ${NAME} $^ ${LINKFLAGS} ${PATHMLX}
endif

all: 			${NAME}

bonus:			
				$(MAKE) BONUS=1

screen:			
				${RM} ${PATHSCREEN}
clean:
				${RM} ${OBJS} ${OBJS_BONUS} ${PATHSCREEN} 

fclean:			clean
				${RM} ${NAME} ${PATHSCREEN}

re:				fclean all
