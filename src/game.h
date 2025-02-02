#ifndef GAME_H
# define GAME_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 2048

# define PATH_WALL "./img/wall.png"
# define PATH_GND "./img/gnd.png"
# define PATH_EXIT "./img/exit.png"
# define PATH_POINT "./img/point.png"
# define PATH_PLAYER "./img/player.png"

# define OBJ_WIDTH 64
# define OBJ_HEIGHT 64

# define KEY_HOOK 2
# define WIN_CLOSE 17

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

# define CAR_PLAYER 'P'
# define CAR_EXIT	'E'
# define CAR_POINT	'C'
# define CAR_WALL	'1'
# define CAR_GND	'0'

typedef struct	t_player
{
	void	*img;
	int		x;
	int		y;
	int		width;
	int		height;
}	t_player;

typedef struct	t_obj
{
	void	*img;
	int		width;
	int		height;
}	t_obj;

typedef struct	t_map
{
	char	**conf;
	int		x_exit;
	int		y_exit;
	int		width;
	int		height;
}	t_map;

typedef struct t_game
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			score;
	int			step;
	int			point_tot;
	t_map		map;
	t_player	player;
	t_obj	obj_wall;
	t_obj	obj_gnd;
	t_obj	obj_exit;
	t_obj	obj_point;
}	t_game;

void	print_score(t_game *game);
void	print_step(t_game *game);
void	print_map(t_game **game);
int		map_parser(char *file_name, t_game **game);
char	find_path(t_map *map);
int		key_action(t_game *game, int keycode);
void	move_player(t_game *game, int keycode);
int		key_handler(int keycode, void *param);
t_game	*init_game(char *map_name);
int		close_handler(t_game *param);
void	end_game(char *er_buf, t_game *game);
#endif
