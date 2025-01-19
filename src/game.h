#ifndef GAME_H
# define GAME_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>

# define PATH_ROOM "./img/room.png"
# define PATH_PLAYER "./img/player.png"

# define WIN_WIDTH 500
# define WIN_HEIGHT 500
# define PLAYER_WIDTH 50
# define PLAYER_HEIGHT 50
# define KEY_HOOK 2

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

typedef struct	t_player
{
	void	*img;
	int		x;
	int		y;
	int		width;
	int		height;
}	t_player;

typedef struct t_game
{
	void		*mlx;
	void		*win;
	void		*img;
	int			width;
	int			height;
	t_player	player;
}	t_game;

void	move_player(t_game *game, int keycode);
int		key_handler(int keycode, void *param);
t_game	*init_game();
#endif
