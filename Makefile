
NAME = so_long

NAMELIBFT = libft.a

SRCS = so_long.c

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = gcc

LIBFTPATH = ./libft/

MLXPATH = ./minilibx_opengl_20191021

all: $(NAME)

$(NAME):
	make -C $(LIBFTPATH)
	make -C $(MLXPATH)
	CC -I .$(MLXPATH) so_long.c -L $(MLXPATH) $(LIBFTPATH)$(NAMELIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFTPATH)
	make clean -C $(MLXPATH)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFTPATH)

re: fclean all

.PHONY: all clean fclean re
