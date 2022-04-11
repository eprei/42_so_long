/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_process1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epresa-c <epresa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:50:41 by epresa-c          #+#    #+#             */
/*   Updated: 2022/04/11 13:41:16 by epresa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_rectangle(t_game *game)
{
	size_t	strlen;
	size_t	comparation;
	int		i;

	strlen = 0;
	i = (int)game->map_width;
	comparation = ft_strlen_without_new_line(game->tab[i - 1]);
	while (i > 0)
	{
		strlen = ft_strlen_without_new_line(game->tab[i - 1]);
		if (strlen != comparation)
			return (1);
		comparation = strlen;
		i--;
	}
	game->map_length = comparation;
	return (0);
}

void	ft_get_map(t_game *game, char *argv1)
{
	int	fd;
	int	j;

	fd = open(argv1, O_RDONLY);
	if (fd == -1)
		ft_exit(game, strerror(errno), EXIT_FAILURE);
	game->tab = malloc(sizeof(char *) * game->map_width);
	j = 0;
	while (j < game->map_width)
		game->tab[j++] = get_next_line(fd);
	close(fd);
	if (ft_check_rectangle(game) == 1)
		ft_exit(game, "ERROR\nThe selected map does not meet the requirements.\
		Please use a rectangular map", EXIT_FAILURE);
}

int	ft_check_walls(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_width)
	{	
		x = 0;
		while (x < game->map_length)
		{
			if ((y == 0) && game->tab[y][x] != '1')
				return (1);
			else if ((y == game->map_width - 1) && game->tab[y][x] != '1')
				return (1);
			else if ((x == game->map_length - 1) && game->tab[y][x] != '1')
				return (1);
			else if ((x == 0) && game->tab[y][x] != '1')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_process_map(t_game *game, char *argv1)
{
	ft_count_lines(game, argv1);
	ft_get_map(game, argv1);
	if (ft_check_walls(game))
		ft_exit(game, "Error\n\
		The map must be surrounded by walls (character 1).", EXIT_FAILURE);
	ft_check_characters(game);
	if ((game->count_p != 1) || \
	(game->count_e < 1) || (game->count_c < 1))
		ft_exit(game, "Error\nThe map must contain at least one C character,\
		one E character and one P character.", EXIT_FAILURE);
}
