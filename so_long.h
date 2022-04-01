#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_game
{
    void *mlx_ptr;
    void *win_ptr;
	void *img_char_ptr;
	void *img_wall_ptr;
	void *img_items_ptr;
	void *img_exit_ptr;
    int img_res;
} t_game;

#endif