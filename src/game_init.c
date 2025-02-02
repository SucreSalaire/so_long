#include "game.h"

t_game	*init_game(char *map_name)
{
	t_game *game;
	
	game = malloc(sizeof(t_game));
	if (!game)
		end_game("Error\nmemory error", NULL);
	game->mlx = mlx_init();
	game->obj_wall.img = mlx_png_file_to_image(game->mlx, PATH_WALL, &(game->obj_wall.width), &(game->obj_wall.height));
	game->obj_gnd.img = mlx_png_file_to_image(game->mlx, PATH_GND, &(game->obj_gnd.width), &(game->obj_gnd.height));
	game->obj_exit.img = mlx_png_file_to_image(game->mlx, PATH_EXIT, &(game->obj_exit.width), &(game->obj_exit.height));
	game->obj_point.img = mlx_png_file_to_image(game->mlx, PATH_POINT, &(game->obj_point.width), &(game->obj_point.height));
	game->player.img = mlx_png_file_to_image(game->mlx, PATH_PLAYER, &(game->player.width), &(game->player.height));
	map_parser(map_name, &game);
	//if (find_path(game->map) == -1)
	//	end_game("Error\nno way to escape", game);
	//find_path(&game->map);
	game->width = game->map.width * OBJ_WIDTH;
	game->height = game->map.height * OBJ_HEIGHT;
	game->score = 0;
	game->step = 0;
	game->win = mlx_new_window(game->mlx, game->width, game->height, "game");
	if (!game->win)
		end_game("Error\ncan't create windows's game", game);
	print_map(&game);
	print_score(game);
	print_step(game);
	mlx_hook(game->win, KEY_HOOK, 0, key_handler, (void *)game);
	mlx_hook(game->win, WIN_CLOSE, 0, close_handler, (void *)game);
	return (game);
}

void	end_game(char *er_buf, t_game *game)
{
	if (game->mlx != NULL && game->win != NULL)
		mlx_destroy_window(game->mlx, game->win);
	printf("%s\n", er_buf);
	exit(0);
}
