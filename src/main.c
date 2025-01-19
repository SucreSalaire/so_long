#include "game.h"

int	key_handler(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
    if (keycode == KEY_ESC)
        exit(0);
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || keycode == KEY_D)
		move_player(game, keycode);
	return (0);
}

int	main()
{
	t_game	*game;

	game = init_game();
	mlx_loop(game->mlx);
	return (0);
}
