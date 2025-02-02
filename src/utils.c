#include "game.h"

void	print_score(t_game *game)
{
	
	mlx_put_image_to_window(game->mlx, game->win, game->obj_wall.img, game->width - OBJ_WIDTH, 0);
	mlx_string_put(game->mlx, game->win, game->width - OBJ_WIDTH + OBJ_WIDTH / 2, OBJ_HEIGHT / 2, 0, ft_itoa(game->score));
}

void	print_step(t_game *game)
{
	printf("You've made %i big step in the black hole\n", game->step);
	mlx_put_image_to_window(game->mlx, game->win, game->obj_wall.img, game->width - 2 * OBJ_WIDTH, 0);
	mlx_string_put(game->mlx, game->win, game->width - 2 * OBJ_WIDTH + OBJ_WIDTH / 2, OBJ_HEIGHT / 2, 0, ft_itoa(game->step));
}
