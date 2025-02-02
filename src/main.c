#include "game.h"

int	key_handler(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
    if (keycode == KEY_ESC)
        end_game("see you next time", game);
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || keycode == KEY_D)
		key_action(game, keycode);
	return (0);
}

int	close_handler(t_game *param)
{
	end_game("see you next time", param);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;
	
	game = NULL;
	if (!ac)
		end_game("Error\nno arguments", NULL);
	game = init_game(av[1]);
	mlx_loop(game->mlx);
	return (0);
}
