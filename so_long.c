#include "so_long.h"

// BONUS escribir ft_count_str usando itoa para convertir count_movs en una str que utilizara
//			mlx_string_put para imprimir en pantalla la cantidad de movimientos

void ft_check_args(int argc, char **argv)
{
	if (argc > 2)
	{
		write(1, "ERROR\nToo many arguments.\nCorrect usage: ./so_long <filemap.ber>\n", 62);
		exit(EXIT_FAILURE);
	}
	if (argc < 2)
	{
		write(1, "ERROR\nArguments are missing.\nCorrect usage: ./so_long <filemap.ber>\n", 65);
		exit(EXIT_FAILURE);
	}
	if ((ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))) == NULL)
	{
		write(1, "ERROR\nIncorrect map extension. Please use a '.ber' file\nCorrect usage: ./so_long <filemap.ber>]\n", 92);
		exit(EXIT_FAILURE);
	}
}

void ft_game_init(t_game *game_ptr)
{
	game_ptr->mlx_ptr = NULL;
	game_ptr->win_ptr = NULL;
	game_ptr->win_size_x = 0;
	game_ptr->win_size_y = 0;
	game_ptr->tab = NULL;
	game_ptr->img_dog = NULL;
	game_ptr->img_empty = NULL;
	game_ptr->img_wall = NULL;
	game_ptr->img_item = NULL;
	game_ptr->img_exit = NULL;
	game_ptr->dog_texture = "./xpm/P.xpm";
	game_ptr->empty_texture = "./xpm/0.xpm";
	game_ptr->wall_texture = "./xpm/1.xpm";
	game_ptr->item_texture = "./xpm/C.xpm";
	game_ptr->exit_texture = "./xpm/E.xpm";
	game_ptr->img_res = 60;
	game_ptr->count_movs = 0;
	game_ptr->pos_dog_x = 0;
	game_ptr->pos_dog_y = 0;
	game_ptr->map_length = 0;
	game_ptr->map_width = 0;
	game_ptr->count_c = 0;
	game_ptr->count_e = 0;
	game_ptr->count_p = 0;
}

void ft_exit(t_game *game_ptr, char *error_message, int exit_status)
{
// check with julien or herve if exit() clean all mallocs,
// if yes: delete next commented code, else: see how to fix the leak that ocurs
/*	int i;
	
	i = (int)game_ptr->map_width;
	while (i >= 0)
	{
		free(game_ptr->tab[i - 1]);
		i--;
	}
	free(game_ptr); */
	ft_printf("%s\n", error_message);
	exit(exit_status);
}

void	ft_count_lines(t_game *game_ptr, char *argv1)
{
	int fd;
	char *gnl_return;

	fd = open(argv1, O_RDONLY);
	if (fd == -1)
		ft_exit(game_ptr, strerror(errno), EXIT_FAILURE);
	while (1)
	{
        gnl_return = get_next_line(fd);
		if (gnl_return != NULL)
        {   
            free(gnl_return);
            game_ptr->map_width += 1;
        }
        else
        {
            free(gnl_return);
            break;
        }
	}
	close(fd);
	if (game_ptr->map_width < 3)
	 	ft_exit(game_ptr, "Error\nThe map must have at least three rows", EXIT_FAILURE);
}

size_t	ft_strlen_without_new_line(const char *s)
{
	unsigned long long	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

int	ft_check_rectangle(t_game *game_ptr)
{
	size_t strlen;
	size_t comparation;
	int i;

	strlen = 0;
	i = (int)game_ptr->map_width;
	comparation = ft_strlen_without_new_line(game_ptr->tab[i - 1]);
	while (i > 0)
	{
		strlen = ft_strlen_without_new_line(game_ptr->tab[i - 1]);
		if (strlen != comparation)
			return (1);
		comparation = strlen;
		i--;
	}
	game_ptr->map_length = comparation;
	return(0);
}

void	ft_get_map(t_game *game_ptr, char *argv1)
{
	int fd;
	int j;

	fd = open(argv1, O_RDONLY);
	if (fd == -1)
		ft_exit(game_ptr, strerror(errno), EXIT_FAILURE);
    game_ptr->tab = malloc(sizeof(char *) * game_ptr->map_width);
    j = 0;
    while (j < game_ptr->map_width)
        game_ptr->tab[j++] = get_next_line(fd);
    close(fd);
/*	j = 0;
    while (j < game_ptr->map_width)
    {
        ft_printf("%s\n", game_ptr->tab[j]);
        j++;
    }
    game_ptr->map_length = ft_strlen_without_new_line(game_ptr->tab[1]);
    ft_printf("Map lenght = %d\n", game_ptr->map_length);
    ft_printf("Map widht = %d\n", game_ptr->map_width);
*/	if (ft_check_rectangle(game_ptr) == 1)
		ft_exit(game_ptr, "ERROR\nThe selected map does not meet the requirements. Please use a rectangular map", EXIT_FAILURE);
}

int	ft_check_walls(t_game *game_ptr)
{
	int x;
	int y;

	y = 0;
	while (y < game_ptr->map_width)
	{	
		x = 0;
		while (x < game_ptr->map_length)
		{
			if ((y == 0) && game_ptr->tab[y][x] != '1')
				return (1);	
			else if ((y == game_ptr->map_width - 1) && game_ptr->tab[y][x] != '1')
				return (1);
			else if ((x == game_ptr->map_length - 1) && game_ptr->tab[y][x] != '1')
				return (1);
			else if ((x == 0) && game_ptr->tab[y][x] != '1')
				return (1);							
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_check_characters(t_game *game_ptr)
{
	int x;
	int y;

	y = 0;
	while (y < game_ptr->map_width)
	{	
		x = 0;
		while (x < game_ptr->map_length)
		{
			if ((game_ptr->tab[y][x] != '0') && (game_ptr->tab[y][x] != '1') && (game_ptr->tab[y][x] != 'C') && (game_ptr->tab[y][x] != 'P') && (game_ptr->tab[y][x] != 'E')) 
				ft_exit(game_ptr, "Error\nThe selected map does not meet the requirements. The map can only contain the characters '0' '1' 'C' 'E' 'P'", EXIT_FAILURE);
			else if (game_ptr->tab[y][x] == 'C')
				game_ptr->count_c++;
			else if (game_ptr->tab[y][x] == 'P')
			{
				game_ptr->count_p++;		
				game_ptr->pos_dog_x = x;
				game_ptr->pos_dog_y = y;
			}
			else if (game_ptr->tab[y][x] == 'E')
				game_ptr->count_e++;				
			x++;
		}
		y++;
	}
}

void ft_process_map(t_game *game_ptr, char *argv1)
{
	ft_count_lines(game_ptr, argv1);
	ft_get_map(game_ptr, argv1);
	if (ft_check_walls(game_ptr))
	 	ft_exit(game_ptr, "Error\nThe map must be surrounded by walls (character 1).", EXIT_FAILURE);
	ft_check_characters(game_ptr);
	if ((game_ptr->count_p != 1) || (game_ptr->count_e < 1) || (game_ptr->count_c < 1))
	 	ft_exit(game_ptr, "Error\nThe map must contain at least one C character, one E character and one P character.", EXIT_FAILURE);
}

void	ft_update_win_size(t_game *game_ptr)
{
	game_ptr->win_size_x = game_ptr->map_length * game_ptr->img_res;
	game_ptr->win_size_y = game_ptr->map_width * game_ptr->img_res;
}

void ft_init_images(t_game *game_ptr)
{
	game_ptr->img_dog = mlx_xpm_file_to_image(game_ptr->mlx_ptr, game_ptr->dog_texture, &game_ptr->img_res, &game_ptr->img_res);
	game_ptr->img_empty = mlx_xpm_file_to_image(game_ptr->mlx_ptr, game_ptr->empty_texture, &game_ptr->img_res, &game_ptr->img_res);
	game_ptr->img_wall = mlx_xpm_file_to_image(game_ptr->mlx_ptr, game_ptr->wall_texture, &game_ptr->img_res, &game_ptr->img_res);
	game_ptr->img_item = mlx_xpm_file_to_image(game_ptr->mlx_ptr, game_ptr->item_texture, &game_ptr->img_res, &game_ptr->img_res);
	game_ptr->img_exit = mlx_xpm_file_to_image(game_ptr->mlx_ptr, game_ptr->exit_texture, &game_ptr->img_res, &game_ptr->img_res);
}

void	fn_put_tab_to_window(t_game *game_ptr)
{
	int x;
	int y;

	mlx_clear_window(game_ptr->mlx_ptr, game_ptr->win_ptr);
	y = 0;
	while (y < game_ptr->map_width)
	{	
		x = 0;
		while (x < game_ptr->map_length)
		{
			if (game_ptr->tab[y][x] == '0') 
				mlx_put_image_to_window(game_ptr->mlx_ptr, game_ptr->win_ptr, game_ptr->img_empty, x * game_ptr->img_res, y * game_ptr->img_res);
			if (game_ptr->tab[y][x] == '1') 
				mlx_put_image_to_window(game_ptr->mlx_ptr, game_ptr->win_ptr, game_ptr->img_wall, x * game_ptr->img_res, y * game_ptr->img_res);
			else if (game_ptr->tab[y][x] == 'C')
				mlx_put_image_to_window(game_ptr->mlx_ptr, game_ptr->win_ptr, game_ptr->img_item, x * game_ptr->img_res, y * game_ptr->img_res);
			else if (game_ptr->tab[y][x] == 'P')
				mlx_put_image_to_window(game_ptr->mlx_ptr, game_ptr->win_ptr, game_ptr->img_dog, x * game_ptr->img_res, y * game_ptr->img_res);
			else if (game_ptr->tab[y][x] == 'E')
				mlx_put_image_to_window(game_ptr->mlx_ptr, game_ptr->win_ptr, game_ptr->img_exit, x * game_ptr->img_res, y * game_ptr->img_res);
			x++;
		}
		y++;
	}
}

void ft_process_mov(t_game *game_ptr, int x, int y)
{
	int flag;

	flag = 0;
	if (game_ptr->tab[y][x] == 'C')
	{
		if (game_ptr->count_movs == 0)
			game_ptr->tab[game_ptr->pos_dog_y][game_ptr->pos_dog_x] = '0';
		game_ptr->tab[y][x] = '0';
		game_ptr->pos_dog_x = x;
		game_ptr->pos_dog_y = y;	
		game_ptr->count_c--;
		game_ptr->count_movs++;
		flag = 1;
	}
	if (game_ptr->tab[y][x] == '0')
	{
		if (game_ptr->count_movs == 0)
			game_ptr->tab[game_ptr->pos_dog_y][game_ptr->pos_dog_x] = '0';
		game_ptr->pos_dog_x = x;
		game_ptr->pos_dog_y = y;
		game_ptr->count_movs++;
		flag = 1;
	}
	if (game_ptr->tab[y][x] == 'E' && game_ptr->count_c == 0)
	{
		mlx_clear_window(game_ptr->mlx_ptr, game_ptr->win_ptr);
		mlx_string_put(game_ptr->mlx_ptr, game_ptr->win_ptr, game_ptr->win_size_x / 3, game_ptr->win_size_y / 2, 0x00ffffff, "YOU WIN! ESC key to exit");
	}
	else if (flag == 1)
	{
		ft_printf("Total number of movements: %d\n", game_ptr->count_movs);
		fn_put_tab_to_window(game_ptr);
		mlx_put_image_to_window(game_ptr->mlx_ptr, game_ptr->win_ptr, game_ptr->img_dog, x * game_ptr->img_res, y * game_ptr->img_res);
	}
}

int	key_ctrl(int key, t_game *game_ptr)
{
	if (key == LEFT)
		ft_process_mov(game_ptr, game_ptr->pos_dog_x - 1, game_ptr->pos_dog_y);
	else if (key == RIGHT)
		ft_process_mov(game_ptr, game_ptr->pos_dog_x + 1, game_ptr->pos_dog_y);
	else if (key == DOWN)
		ft_process_mov(game_ptr, game_ptr->pos_dog_x, game_ptr->pos_dog_y + 1);
	else if (key == UP)
		ft_process_mov(game_ptr, game_ptr->pos_dog_x, game_ptr->pos_dog_y - 1);
	else if (key == ESC)
		ft_exit(game_ptr, "Game over", EXIT_SUCCESS);
	return (0);
}

int main(int argc, char **argv)
{
	t_game *game_ptr;
	ft_check_args(argc, argv);
	game_ptr = malloc(sizeof(t_game));
	if (game_ptr == NULL)
		ft_exit(game_ptr, "ERROR\nMalloc error", EXIT_FAILURE);
	ft_game_init(game_ptr);
	ft_process_map(game_ptr, argv[1]);
	ft_update_win_size(game_ptr);
	game_ptr->mlx_ptr = mlx_init();
	if (game_ptr->mlx_ptr == NULL)
		ft_exit(game_ptr, "ERROR\nmlx_init has failed", EXIT_FAILURE);
	game_ptr->win_ptr = mlx_new_window(game_ptr->mlx_ptr, game_ptr->win_size_x, game_ptr->win_size_y, "So Long");
	ft_init_images(game_ptr);
	fn_put_tab_to_window(game_ptr);
	mlx_key_hook(game_ptr->win_ptr, key_ctrl, game_ptr);
	mlx_loop(game_ptr->mlx_ptr);
	return (0);
}
