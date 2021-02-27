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

SRCS = 	file_management.c	\
		file_management2.c	\
		file_management3.c	\
		main.c				\
		error_management.c	\
		initiate_all.c		\
		utils.c				\
		map2d.c				\
		rays.c				\
		walls.c				\
		player.c

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
	@$(CC) $(SRCS) $(NAME) $(FLAGS) -I minilibx -lmlx -framework OpenGL -framework AppKit -o cube3d

clean:
	@echo "cleaning..."
	@cd srcs && $(RM) *.o
	@cd libft && make clean

fclean: clean
	@$(RM) $(NAME)
	@cd libft && make fclean

exec:
	@echo "executing...\n\n====================="
	@./cube3d srcs/map.cub
	@echo =====================

re: fclean all exec
