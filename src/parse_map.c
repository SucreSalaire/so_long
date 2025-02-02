#include "game.h"

static int	check_car(char *buf)
{
	size_t	i;
	char	p_cnt;
	char	c_cnt;
	char	e_cnt;

	i = 0;
	p_cnt = 0;
	c_cnt = 0;
	e_cnt = 0;
	while (buf[i])
	{
		if (buf[i] == CAR_PLAYER)
			p_cnt++;
		else if (buf[i] == CAR_POINT)
			c_cnt++;
		else if (buf[i] == CAR_EXIT)
			e_cnt++;
		else if (buf[i] != CAR_GND && buf[i] != CAR_WALL && buf[i] != '\n')
			return (-1);
		i++;
	}
	if (p_cnt == 1 && c_cnt >= 1 && e_cnt == 1)
		return (0);
	return (-1);
}

int	map_parser(char *file_name, t_game **game)
{
	int		fd;
	char	*buf;
	ssize_t	end;
	t_map	map;

	fd = open(file_name, O_RDONLY);
	if (read(fd, 0, 0) < 0 || fd < 0)
		end_game("Error\nInvalid fd", *game);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		end_game("Error\nmemory error", *game);
	end = read(fd, buf, BUFFER_SIZE);
	if (end <= 0)
		end_game("Error\nno map data", *game);
	buf[end] = 0;
	if (check_car(buf) < 0)
		end_game("Error\nrong map format", *game);
	map = *(t_map *)malloc(sizeof(t_map));
	//if (map == NULL)
	//	end_game("memory error", *game);
	map.conf = ft_split(buf, '\n');
	if (!(map.conf))
		end_game("Error\nmemory error", *game);
	map.width = ft_strlen(map.conf[0]);
	map.height = ft_car_count(buf, '\n');
	(*game)->point_tot = ft_car_count(buf, 'C');
	(*game)->map = map;
	return (1);
}

void	put_player(t_game *game, int line, int column)
{
	mlx_put_image_to_window(game->mlx, game->win, game->player.img, line * OBJ_WIDTH, column * OBJ_HEIGHT);
	game->player.x = line * OBJ_WIDTH;
	game->player.y = column * OBJ_HEIGHT;
}

void	put_exit(t_game **game, int line, int column)
{
	t_game *g;

	g = *game;
	mlx_put_image_to_window(g->mlx, g->win, g->obj_exit.img, line * OBJ_WIDTH, column * OBJ_HEIGHT);
	g->map.x_exit = line;
	g->map.y_exit = column;
}

void	print_map(t_game **game)
{
	int	line;
	int	column;
	t_game *g;

	line = 0;
	column = 0;
	g = *game;
	while (column < g->map.height)
	{
		while (line < g->map.width)
		{
			if (g->map.conf[column][line] == CAR_WALL)
				mlx_put_image_to_window(g->mlx, g->win, g->obj_wall.img, line * OBJ_WIDTH, column * OBJ_HEIGHT);
			else if (g->map.conf[column][line] == CAR_GND)
				mlx_put_image_to_window(g->mlx, g->win, g->obj_gnd.img, line * OBJ_WIDTH, column * OBJ_HEIGHT);
			else if (g->map.conf[column][line] == CAR_EXIT)
				put_exit(game, line, column);
			else if (g->map.conf[column][line] == CAR_POINT)
				mlx_put_image_to_window(g->mlx, g->win, g->obj_point.img, line * OBJ_WIDTH, column * OBJ_HEIGHT);
			else if (g->map.conf[column][line] == CAR_PLAYER)
				put_player(g, line, column);
			line++;
		}
		column++;
		line = 0;
	}
}
