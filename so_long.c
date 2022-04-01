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

int main(int argc, char **argv)
{
	t_game *game_ptr;
	int i = 60;
	char *relative_path = "./dog.xpm";
	void *aya;

    if (argc != 2)
	{
		write(1, "Usage: ./so_long 'map.ber'\n", 28);
		exit(EXIT_FAILURE);
	}
//	fn_verif_map_ext(argv[2]);
	game_ptr = malloc(sizeof(game_ptr));
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
	game_ptr->win_ptr = mlx_new_window(game_ptr->mlx_ptr, 500, 500, "Ayas proyect");
	mlx_string_put(game_ptr->mlx_ptr, game_ptr->win_ptr, 180, 250, 0xFFFFFF,"Videogame in process...");
//	mlx_pixel_put(game_ptr->mlx_ptr, game_ptr->win_ptr, 300, 300, 0xFF0000);
	aya = mlx_xpm_file_to_image(game_ptr->mlx_ptr, relative_path, &i, &i);
	mlx_put_image_to_window(game_ptr->mlx_ptr, game_ptr->win_ptr, aya, 150, 150);
	mlx_loop(game_ptr->mlx_ptr);
	return (0);
}
