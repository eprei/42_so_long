all:
	cc -I ./minilibx_opengl_20191021  so_long.c -L ./minilibx_opengl_20191021/ -lmlx -framework OpenGL -framework AppKit -o so_long
