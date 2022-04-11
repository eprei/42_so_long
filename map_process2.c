/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_process2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epresa-c <epresa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:50:41 by epresa-c          #+#    #+#             */
/*   Updated: 2022/04/11 13:41:09 by epresa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_characters_sub(t_game *game, int x, int y)
{
	if ((game->tab[y][x] != '0') && (game->tab[y][x] != '1') && \
		(game->tab[y][x] != 'C') && (game->tab[y][x] != 'P') \
		&& (game->tab[y][x] != 'E'))
		ft_exit(game, "Error\nThe map can only contain:\
		'0' '1' 'C' 'E' 'P'", EXIT_FAILURE);
	else if (game->tab[y][x] == 'C')
		game->count_c++;
	else if (game->tab[y][x] == 'P')
	{
		game->count_p++;
		game->pos_x = x;
		game->pos_y = y;
	}
	else if (game->tab[y][x] == 'E')
		game->count_e++;
}

void	ft_check_characters(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_width)
	{	
		x = 0;
		while (x < game->map_length)
		{
			ft_check_characters_sub(game, x, y);
			x++;
		}
		y++;
	}
}
