#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>

# define LEFT 0
# define RIGHT 2
# define DOWN 1
# define UP 13
# define ESC 53

typedef struct s_game
{
    void *mlx_ptr;
    void *win_ptr;
	void *img_char_ptr;
	void *img_wall_ptr;
	void *img_items_ptr;
	void *img_exit_ptr;
    int img_res;
	unsigned int count_movs;
	unsigned int pos_char_x;
	unsigned int pos_char_y;
	char *dog_texture;
} t_game;

#endif