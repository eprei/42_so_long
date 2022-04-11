/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epresa-c <epresa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:56:55 by epresa-c          #+#    #+#             */
/*   Updated: 2022/04/11 12:30:29 by epresa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game_init(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->win_size_x = 0;
	game->win_size_y = 0;
	game->tab = NULL;
	game->img_dog = NULL;
	game->img_empty = NULL;
	game->img_wall = NULL;
	game->img_item = NULL;
	game->img_exit = NULL;
	game->dog_txt = "./xpm/P.xpm";
	game->empty_txt = "./xpm/0.xpm";
	game->wall_txt = "./xpm/1.xpm";
	game->item_txt = "./xpm/C.xpm";
	game->exit_txt = "./xpm/E.xpm";
	game->img_res = 60;
	game->count_movs = 0;
	game->pos_x = 0;
	game->pos_y = 0;
	game->map_length = 0;
	game->map_width = 0;
	game->count_c = 0;
	game->count_e = 0;
	game->count_p = 0;
}

void	ft_init_images(t_game *game)
{
	game->img_dog = mlx_xpm_file_to_image(game->mlx_ptr, \
	game->dog_txt, &game->img_res, &game->img_res);
	game->img_empty = mlx_xpm_file_to_image(game->mlx_ptr, \
	game->empty_txt, &game->img_res, &game->img_res);
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr, \
	game->wall_txt, &game->img_res, &game->img_res);
	game->img_item = mlx_xpm_file_to_image(game->mlx_ptr, \
	game->item_txt, &game->img_res, &game->img_res);
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, \
	game->exit_txt, &game->img_res, &game->img_res);
}

void	ft_count_lines(t_game *game, char *argv1)
{
	int		fd;
	char	*gnl_return;

	fd = open(argv1, O_RDONLY);
	if (fd == -1)
		ft_exit(game, strerror(errno), EXIT_FAILURE);
	while (1)
	{
		gnl_return = get_next_line(fd);
		if (gnl_return != NULL)
		{
			free(gnl_return);
			game->map_width += 1;
		}
		else
		{
			free(gnl_return);
			break ;
		}
	}
	close(fd);
	if (game->map_width < 3)
		ft_exit(game, "Error\n\
		The map must have at least three rows", EXIT_FAILURE);
}

void	ft_update_win_size(t_game *game)
{
	game->win_size_x = game->map_length * game->img_res;
	game->win_size_y = game->map_width * game->img_res;
}

size_t	ft_strlen_without_new_line(const char *s)
{
	unsigned long long	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}
