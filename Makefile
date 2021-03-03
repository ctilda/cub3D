# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 10:40:03 by ctilda            #+#    #+#              #
#    Updated: 2021/02/25 12:01:22 by ctilda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	cub3D
FLAGS =	-Wall -Wextra -Werror
HEAD =	cub3d.h

SRCS =	cub3d.c \
		src/raycast/ft_bmp.c \
		src/raycast/ft_draw.c \
		src/raycast/ft_floor_ceiling.c \
		src/error/ft_error.c \
		src/error/utils.c \
		src/raycast/ft_memory.c \
		src/raycast/ft_sprite.c \
		src/raycast/ft_raycast.c \
		src/map/ft_init_map.c \
		src/map/ft_parse_map.c \
		src/map/ft_extra_parse.c \
		src/move/ft_move.c \
		src/move/ft_key.c \
		src/raycast/ft_load.c \
		src/raycast/ft_read_sprite.c \
		src/raycast/ft_start_app.c \

OBJ =	$(SRCS:.c=.o)

LIBFT =		libft/libft.a
LIBMLX =	mlx/libmlx.a
GNL =		get_next_line/*.c -D BUFFER_SIZE=1

MLX =		-Lmlx -lmlx -framework OpenGL -framework AppKit

RM =		rm -f

$(NAME): $(OBJ) $(HEAD) $(LIBFT) $(LIBMLX)
	gcc $(OBJ) $(MLX) $(LIBFT) $(LIBMLX) -o $(NAME) $(GNL)

$(LIBFT): $(LIBMLX)
	@$(MAKE) -C libft

$(LIBMLX):
	@$(MAKE) -C mlx

$(OBJ): %.o:%.c $(HEAD)
	gcc $(FLAGS) -c $< -o $@

all:	$(NAME)

clean:
		$(RM) $(OBJ)
		@make clean -C libft
		@make clean -C mlx
		$(RM) *.bmp

fclean:	clean
		$(RM) $(NAME)
		@make fclean -C libft

re:		fclean all

.PHONY:		all clean fclean re
