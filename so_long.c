/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epresa-c <epresa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:31:06 by epresa-c          #+#    #+#             */
/*   Updated: 2022/04/11 16:47:32 by epresa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_args(int argc, char **argv)
{
	if (argc > 2)
	{
		write(1, "ERROR\nToo many arguments.\n\
Correct usage: ./so_long <filemap.ber>\n", 68);
		exit(EXIT_FAILURE);
	}
	if (argc < 2)
	{
		write(1, "ERROR\nArguments are missing.\n\
Correct usage: ./so_long <filemap.ber>\n", 71);
		exit(EXIT_FAILURE);
	}
	if ((ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))) == NULL)
	{
		write(1, "ERROR\nIncorrect map extension. Please use a '.ber' file\n\
Correct usage: ./so_long <filemap.ber>\n", 99);
		exit(EXIT_FAILURE);
	}
}

void	ft_exit(t_game *game, char *error_message, int exit_status)
{
	int	i;

	i = (int)game->map_width;
	while (i > 0)
	{
		free(game->tab[i - 1]);
		game->tab[i - 1] = NULL;
		i--;
	}
	free(game);
	game = NULL;
	ft_printf("%s\n", error_message);
	exit(exit_status);
}

int	ft_exit_cross(t_game *game)
{
	ft_exit(game, "Game over\n", EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	ft_check_args(argc, argv);
	game = malloc(sizeof(t_game));
	if (game == NULL)
		ft_exit(game, "ERROR\nMalloc error", EXIT_FAILURE);
	ft_game_init(game);
	ft_process_map(game, argv[1]);
	ft_update_win_size(game);
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		ft_exit(game, "ERROR\nmlx_init has failed", EXIT_FAILURE);
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
	game->win_size_x, game->win_size_y, "So Long");
	ft_init_images(game);
	ft_put_tab_to_window(game);
	mlx_key_hook(game->win_ptr, key_ctrl, game);
	mlx_hook(game->win_ptr, 17, 0, ft_exit_cross, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}

void	ft_end_game(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	mlx_string_put(game->mlx_ptr, game->win_ptr, game->win_size_x / 3, \
	game->win_size_y / 2, 0x00ffffff, "YOU WIN! ESC key to exit");
}
