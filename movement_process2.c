/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_process2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epresa-c <epresa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:14:32 by epresa-c          #+#    #+#             */
/*   Updated: 2022/04/11 13:14:37 by epresa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_img_to_win(t_game *game, int x, int y)
{
	if (game->tab[y][x] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->img_empty, x * game->img_res, y * game->img_res);
	if (game->tab[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->img_wall, x * game->img_res, y * game->img_res);
	else if (game->tab[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->img_item, x * game->img_res, y * game->img_res);
	else if (game->tab[y][x] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->img_dog, x * game->img_res, y * game->img_res);
	else if (game->tab[y][x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->img_exit, x * game->img_res, y * game->img_res);
}

void	ft_put_tab_to_window(t_game *game)
{
	int	x;
	int	y;

	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	y = 0;
	while (y < game->map_width)
	{	
		x = 0;
		while (x < game->map_length)
		{
			ft_img_to_win(game, x, y);
			x++;
		}
		y++;
	}
}
