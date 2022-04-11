/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epresa-c <epresa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:00:26 by epresa-c          #+#    #+#             */
/*   Updated: 2022/04/11 13:15:14 by epresa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_update_pos(t_game *game, int x, int y)
{
	game->pos_x = x;
	game->pos_y = y;
}

void	ft_process_mov(t_game *game, int x, int y)
{
	int	flag;

	flag = 0;
	if (game->tab[y][x] == 'C')
	{
		if (game->count_movs == 0)
			game->tab[game->pos_y][game->pos_x] = '0';
		game->tab[y][x] = '0';
		ft_update_pos(game, x, y);
		game->count_c--;
		game->count_movs++;
		flag = 1;
	}
	if (game->tab[y][x] == '0')
	{
		if (game->count_movs == 0)
			game->tab[game->pos_y][game->pos_x] = '0';
		ft_update_pos(game, x, y);
		game->count_movs++;
		flag = 1;
	}
	if (game->tab[y][x] == 'E' && game->count_c == 0)
		ft_end_game(game);
	else if (flag == 1)
		ft_update_window(game, x, y);
}

void	ft_update_window(t_game *game, int x, int y)
{
	ft_printf("Total number of movements: %d\n", game->count_movs);
	ft_put_tab_to_window(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_dog, \
	x * game->img_res, y * game->img_res);
}

int	key_ctrl(int key, t_game *game)
{
	if (key == LEFT)
		ft_process_mov(game, game->pos_x - 1, game->pos_y);
	else if (key == RIGHT)
		ft_process_mov(game, game->pos_x + 1, game->pos_y);
	else if (key == DOWN)
		ft_process_mov(game, game->pos_x, game->pos_y + 1);
	else if (key == UP)
		ft_process_mov(game, game->pos_x, game->pos_y - 1);
	else if (key == ESC)
		ft_exit(game, "Game over", EXIT_SUCCESS);
	return (0);
}
