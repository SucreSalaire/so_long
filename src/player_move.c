#include "game.h"

void	move_player(t_game *game, int keycode)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	if (keycode == KEY_W)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player.img, game->player.x, game->player.y - 50);
		game->player.y -= 50;
	}
	else if (keycode == KEY_A)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player.img, game->player.x - 50, game->player.y);
		game->player.x -= 50;
	}
	else if (keycode == KEY_S)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player.img, game->player.x, game->player.y + 50);
		game->player.y += 50;
	}
	else if (keycode == KEY_D)
	{	
		mlx_put_image_to_window(game->mlx, game->win, game->player.img, game->player.x + 50, game->player.y);
		game->player.x += 50;
	}
}

void	*check_collision(t_game game, )
{
	
}
