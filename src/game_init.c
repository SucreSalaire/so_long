#include "game.h"

t_game	*init_game()
{
	t_game *game;

	game = malloc(sizeof(t_game));
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "game");
	if (!game->win)
		return(NULL);
	game->img = mlx_png_file_to_image(game->mlx, PATH_ROOM, &(game->width), &(game->height));
	game->player.img = mlx_png_file_to_image(game->mlx, PATH_PLAYER, &(game->player.width), &(game->player.height));
	game->player.x = 0;
	game->player.y = 0;
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->player.img, game->player.x, game->player.y);
	mlx_hook(game->win, KEY_HOOK, 0, key_handler, (void *)game);
	return (game);
}
