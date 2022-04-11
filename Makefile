# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epresa-c <epresa-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 10:31:46 by epresa-c          #+#    #+#              #
#    Updated: 2022/04/11 13:41:39 by epresa-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

NAMELIBFT = libft.a

SRCS = so_long.c map_process1.c map_process2.c game_init.c movement_process1.c movement_process2.c

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = gcc

LIBFTPATH = ./libft/

MLXPATH = ./minilibx_opengl_20191021

all: $(NAME)

$(NAME):
	make -C $(LIBFTPATH)
	make -C $(MLXPATH)
	CC -I .$(MLXPATH) $(SRCS) -L $(MLXPATH) $(LIBFTPATH)$(NAMELIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFTPATH)
	make clean -C $(MLXPATH)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFTPATH)

re: fclean all

.PHONY: all clean fclean re
