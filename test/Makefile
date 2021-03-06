/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:42:21 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/01/22 17:23:59 by ael-mezz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# -*- Makefile -*-

SRC =	cub/main.c \
		cub/utils1.c \
		cub/rays.c \
		cub/player.c \
		cub/game.c \
		cub/walls.c				\
		cub/read_all.c			\
		utils/ft_putnbr_fd.c \
		utils/ft_strnstr.c \
		utils/ft_split.c \
		utils/ft_atoi.c \
		utils/get_next_line.c \
		utils/get_next_line_utils.c
OUT = cub3d
ARG = map.cub
all: clean
	@echo "Compiling..."
	gcc -I minilibx -lmlx -framework OpenGL -framework AppKit $(SRC) -o $(OUT) -O3 -g3
clean:
	@echo "Cleaning..."
	@rm -rf *.o $(OUT)

exec:
	@echo "Running..."
	@./$(OUT) $(ARG)