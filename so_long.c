#include "so_long.h"
#include <stdio.h>

// escribir fn_game_init que inicialice todos los elementos de la estructura game_ptr
// escribir fn_exit que free todo y cierre el programa
// escribir fn_verif_map_ext que verifique nombre del archivo del mapa.
// 			si termina por ".ber" return(0), sino imprime mensaje de error y exit(EXIT_FAILURE).
// escribir fn_verif_map_config para verificar que A) esta rodeada de muros,
//			B) que es rectangular, C) solo caracteres permitidos (01CEP),
//			D) numero minimo de items (1E, 1C, 1P).
//			si todo ok, return (1) sino "Error\n(mensaje custom)" y return (0) 
// escribir ft_exit. imprime mensaje de error correspondiente, free malloc si es necesario, y exit(1).

int key_ctrl(int key, t_game *game_ptr)
{
	if (key == LEFT)
	{
		game_ptr->pos_char_x -= 60;
		mlx_destroy_image(game_ptr->mlx_ptr, game_ptr->img_char_ptr);
		game_ptr->dog_texture = "./xpm/dog_left.xpm";
		game_ptr->img_char_ptr = mlx_xpm_file_to_image(game_ptr->mlx_ptr, game_ptr->dog_texture, &game_ptr->img_res, &game_ptr->img_res);
	}
	else if (key == RIGHT)
	{
		game_ptr->pos_char_x += 60;
		mlx_destroy_image(game_ptr->mlx_ptr, game_ptr->img_char_ptr);
		game_ptr->dog_texture = "./xpm/dog_right.xpm";
		game_ptr->img_char_ptr = mlx_xpm_file_to_image(game_ptr->mlx_ptr, game_ptr->dog_texture, &game_ptr->img_res, &game_ptr->img_res);
	}
	else if (key == DOWN)
		game_ptr->pos_char_y += 60;
	else if (key == UP)
		game_ptr->pos_char_y -= 60;
	else if (key == ESC)
		exit(EXIT_FAILURE); // ft_exit()
	mlx_put_image_to_window(game_ptr->mlx_ptr, game_ptr->win_ptr, game_ptr->img_char_ptr, game_ptr->pos_char_x, game_ptr->pos_char_y);
	return (0);
}

int main(int argc, char **argv)
{
	t_game *game_ptr;
	int i = 60;

    if (argc != 2)
	{
		write(1, "Usage: ./so_long 'map.ber'\n", 28);
		exit(EXIT_FAILURE);
	}
//	fn_verif_map_ext(argv[2]);
	game_ptr = malloc(sizeof(t_game));
	if (game_ptr == NULL)
	{
		write(1, "Malloc error\n", 14);
		exit(EXIT_FAILURE);
	}
//	fn_game_init(&game_ptr);
//	abrir map.ber y leerlo utilizando: open(), get_next_line(), close();
//	if (fn_verif_map_config(&game_ptr->tableau) == 1)
//		ft_exit();
	game_ptr->mlx_ptr = mlx_init();
//	if (mlx_ptr == NULL)
//		free(game_ptr); write(1, "Usage: ./so_long 'map.ber'\n", 28); exit(EXIT_FAILURE);
	game_ptr->img_res = 60; // inicializar valor en fn_game_init;
	game_ptr->pos_char_x = 30; // inicializar valor en fn_game_init;
	game_ptr->pos_char_y = 30; // inicializar valor en fn_game_init;
	game_ptr->dog_texture = "./xpm/dog_left.xpm";
	game_ptr->win_ptr = mlx_new_window(game_ptr->mlx_ptr, 500, 500, "Ayas proyect");
	mlx_string_put(game_ptr->mlx_ptr, game_ptr->win_ptr, 150, 400, 0xFFFFFF,"Videogame in process...");
	game_ptr->img_char_ptr = mlx_xpm_file_to_image(game_ptr->mlx_ptr, game_ptr->dog_texture, &game_ptr->img_res, &game_ptr->img_res);
	mlx_put_image_to_window(game_ptr->mlx_ptr, game_ptr->win_ptr, game_ptr->img_char_ptr, game_ptr->pos_char_x, game_ptr->pos_char_y);
	mlx_key_hook(game_ptr->win_ptr, key_ctrl, game_ptr);
	mlx_loop(game_ptr->mlx_ptr);
	return (0);
}
