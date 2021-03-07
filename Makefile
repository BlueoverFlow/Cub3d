# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-mezz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 12:57:37 by ael-mezz          #+#    #+#              #
#    Updated: 2021/02/25 17:57:06 by ael-mezz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft/libft.a

FLAGS =

SRCS = 	__main__.c			\
		elements_handling.c	\
		error_management.c	\
		file_management.c	\
		file_management2.c	\
		game.c				\
		initiate_all.c		\
		player.c			\
		rays.c				\
		utils1.c			\
		walls.c


SRCS_PATH = ./srcs

SRCS :=	$(addprefix $(SRCS_PATH)/, $(SRCS))

CC = gcc

RM = rm -f

LIBFT_OBJ_PTH = libft/srcs/*.o

OBJ = $(SRCS:.c=.o)

OBJ_DIR = mv *.o srcs

HEADER = includes/cube3d.h

all: $(NAME)

$(NAME): $(SRCS) $(HEADER)
	@cd libft && make all && make bonus
	@cd ..
	@$(CC) $(SRCS) $(NAME) $(FLAGS) -I minilibx -lmlx -framework OpenGL -framework AppKit -o cub3d

clean:
	@echo "cleaning..."
	@cd srcs && $(RM) *.o
	@cd libft && make clean
	@$(RM) cub3d
	@clear

fclean: clean
	@$(RM) $(NAME)
	@cd libft && make fclean

exec:
	@echo "executing...\n\n====================="
	@./cub3d map.cub
	@echo =====================

re: fclean all exec
