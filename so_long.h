#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx_opengl_20191021/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <math.h>

# define LEFT 0
# define RIGHT 2
# define DOWN 1
# define UP 13
# define ESC 53

typedef struct s_game
{
    void *mlx_ptr;
    void *win_ptr;
	int win_size_x;
	int win_size_y;
	char **tab;
	void *img_dog;
	void *img_empty;
	void *img_wall;
	void *img_item;
	void *img_exit;
	char *dog_texture;
	char *empty_texture;
	char *wall_texture;
	char *item_texture;
	char *exit_texture;
    int img_res;
	unsigned int count_movs;
	char *count_str;
	int pos_dog_x;
	int pos_dog_y;
	int map_length;
	int map_width;
	unsigned int count_c;
	int count_e;
	int count_p;
} t_game;

int	key_ctrl(int key, t_game *game_ptr);
void	ft_check_args(int argc, char **argv);
void	ft_game_init(t_game *game_ptr);
void	ft_exit(t_game *game_ptr, char *error_message, int exit_status);
int	main(int argc, char **argv);
void	ft_count_lines(t_game *game_ptr, char *argv1);
size_t	ft_strlen_without_new_line(const char *s);
int	ft_check_rectangle(t_game *game_ptr);
void	ft_get_map(t_game *game_ptr, char *argv1);
int	ft_check_walls(t_game *game_ptr);
void	ft_check_characters(t_game *game_ptr);
void	ft_process_map(t_game *game_ptr, char *argv1);
void	ft_update_win_size(t_game *game_ptr);
void ft_init_images(t_game *game_ptr);
void	fn_put_tab_to_window(t_game *game_ptr);
void ft_process_mov(t_game *game_ptr, int x, int y);

#endif