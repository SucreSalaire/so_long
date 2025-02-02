#include "game.h"

void	move_player(t_game *game, int keycode)
{
	mlx_put_image_to_window(game->mlx, game->win, game->obj_gnd.img, game->player.x, game->player.y);	
	if (keycode == KEY_W)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player.img, game->player.x, game->player.y - OBJ_HEIGHT);
		game->player.y -= OBJ_HEIGHT;
	}
	else if (keycode == KEY_A)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player.img, game->player.x - OBJ_WIDTH, game->player.y);
		game->player.x -= OBJ_WIDTH;
	}
	else if (keycode == KEY_S)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player.img, game->player.x, game->player.y + OBJ_HEIGHT);
		game->player.y += OBJ_HEIGHT;
	}
	else if (keycode == KEY_D)
	{	
		mlx_put_image_to_window(game->mlx, game->win, game->player.img, game->player.x + OBJ_WIDTH, game->player.y);
		game->player.x += OBJ_WIDTH;
	}
	game->step += 1;
	print_step(game);
}

char	check_collision(t_game *game, int pox, int poy)
{
	int	x_index;
	int y_index;

	x_index = pox / OBJ_WIDTH;
	y_index = poy / OBJ_HEIGHT;
	return (game->map.conf[y_index][x_index]);	
}

int	key_action(t_game *game, int keycode)
{
	char	col;
	
	col = 0;
	if (keycode == KEY_W)
		col = check_collision(game, game->player.x, game->player.y - OBJ_HEIGHT);
	else if (keycode == KEY_A)
		col = check_collision(game, game->player.x - OBJ_WIDTH, game->player.y);
	else if (keycode == KEY_S)
		col = check_collision(game, game->player.x, game->player.y + OBJ_HEIGHT);
	else if (keycode == KEY_D)
		col = check_collision(game, game->player.x + OBJ_WIDTH, game->player.y);
	if (col != CAR_WALL && col != 0)
	{
		if (col == CAR_EXIT && game->score == game->point_tot)
			end_game("Good job !!!", game);
		if (col != CAR_EXIT)
			move_player(game, keycode);
		if (CAR_POINT == check_collision(game, game->player.x, game->player.y))
		{
			game->map.conf[game->player.y / OBJ_HEIGHT][game->player.x / OBJ_WIDTH] = CAR_GND;
			game->score++;
			print_score(game);
		}
	}
	return (0);
}
