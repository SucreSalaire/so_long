#include "game.h"

int	has_neighbours(char **conf, int x, int y, char car)
{
	if (conf[y - 1][x] == car)
		return (0);
	if (conf[y - 1][x - 1] == car)
		return (1);
	if (conf[y][x - 1] == car)
		return (2);
	if (conf[y + 1][x - 1] == car)
		return (3);
	if (conf[y + 1][x] == car)
		return (4);
	if (conf[y + 1][x + 1] == car)
		return (5);
	if (conf[y][x + 1] == car)
		return (6);
	if (conf[y - 1][x + 1] == car)
		return (7);
	return (-1);
}

void	find_exit_pos(t_map **map)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < (*map)->width)
	{
		while (j < (*map)->height)
		{
			if ((*map)->conf[j][i] == CAR_EXIT)
			{
				(*map)->x_exit = i;
				(*map)->y_exit = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

char	find_path(t_map *map)
{
	int	x;
	int	y;
	int	index;
	int	i_y[8] = {-1 , -1, 0, 1, 1, 1, 0, -1};
	int	i_x[8] = {0, -1, -1, -1, 0, 1, 1, 1};

	find_exit_pos(&map);
	x = map->x_exit;
	y = map->y_exit;
	while (has_neighbours(map->conf, x, y, 'P') == -1)
	{
		index = has_neighbours(map->conf, x, y, '0');
		if (index >= 0)
		{
			x += i_x[index];
			y += i_y[index];
			map->conf[y][x] = 'E';
		}
		else
		{
			index = has_neighbours(map->conf, x, y, 'C');
			if (index >= 0)
			{
				x += i_x[index];
				y += i_y[index];
				map->conf[y][x] = 'E';
			}
			else
			{
				return (-1);
			}
		}
	}
	return (0);
}
