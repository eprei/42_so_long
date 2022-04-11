/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epresa-c <epresa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:31:32 by epresa-c          #+#    #+#             */
/*   Updated: 2022/04/11 14:54:56 by epresa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx_opengl_20191021/mlx.h"
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include <fcntl.h>

# define LEFT 0
# define RIGHT 2
# define DOWN 1
# define UP 13
# define ESC 53

typedef struct s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				win_size_x;
	int				win_size_y;
	char			**tab;
	void			*img_dog;
	void			*img_empty;
	void			*img_wall;
	void			*img_item;
	void			*img_exit;
	char			*dog_txt;
	char			*empty_txt;
	char			*wall_txt;
	char			*item_txt;
	char			*exit_txt;
	int				img_res;
	unsigned int	count_movs;
	char			*count_str;
	int				pos_x;
	int				pos_y;
	int				map_length;
	int				map_width;
	unsigned int	count_c;
	int				count_e;
	int				count_p;
}	t_game;

int		key_ctrl(int key, t_game *game);
void	ft_check_args(int argc, char **argv);
void	ft_game_init(t_game *game);
void	ft_exit(t_game *game, char *error_message, int exit_status);
int		main(int argc, char **argv);
void	ft_count_lines(t_game *game, char *argv1);
size_t	ft_strlen_without_new_line(const char *s);
int		ft_check_rectangle(t_game *game);
void	ft_get_map(t_game *game, char *argv1);
int		ft_check_walls(t_game *game);
void	ft_check_characters(t_game *game);
void	ft_process_map(t_game *game, char *argv1);
void	ft_update_win_size(t_game *game);
void	ft_init_images(t_game *game);
void	ft_put_tab_to_window(t_game *game);
void	ft_process_mov(t_game *game, int x, int y);
void	ft_update_window(t_game *game, int x, int y);
void	ft_end_game(t_game *game);
void	ft_update_pos(t_game *game, int x, int y);
void	ft_img_to_win(t_game *game, int x, int y);
void	ft_check_characters_sub(t_game *game, int x, int y);

#endif
