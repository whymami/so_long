#include "so_long.h"
#include "unistd.h"
#include "stdio.h"

void ft_exit(int excode)
{
	if (excode == 1 && write(1, _INV_ARG_MSG, 55))
		exit(_INV_ARG);
	else if (excode == _MAP_NAME && write(1, _MAP_NAME_MSG, 37))
		exit(_MAP_NAME);
	else if (excode == _INV_EXTENTION && write(1, _INV_EXTENTION_MSG, 69))
		exit(_INV_EXTENTION);
	else if (excode == _MAP_NOT_OPEN && write(1, _MAP_NOT_OPEN_MSG, 21))
		exit(_MAP_NOT_OPEN);
	else if (excode == _MAP_LENGTH && write(1, _MAP_LENGTH_MSG, 38))
		exit(_MAP_LENGTH);
}
void	ft_get_cords(t_game *game)
{
	int	h;
	int	w;

	h = -1;
	game->pos = ft_calloc(1, sizeof(t_locate));
	while (++h < game->map->map_Y)
	{
		w = -1;
		while (++w < game->map->map_X)
		{
			if (game->map->game_map[h][w] == _PLAYER)
			{
				game->pos->player_X = w * 64;
				game->pos->player_Y = h * 64;
			}
			if (game->map->game_map[h][w] == _EXIT)
			{
				game->pos->exit_X = w * 64;
				game->pos->exit_Y = h * 64;
			}
		}
	}
}

int ft_len_not_nl(char *str)
{
	int i;

	i  = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

void flood_fill (t_map *tmp_map, int y, int x)
{
	if (x < 0 || x > tmp_map->map_X || y < 0 || y > tmp_map->map_Y)
		return ;
	if (tmp_map->game_map[y][x] != _WALL && tmp_map->game_map[y][x] != 'F')
	{
		tmp_map->game_map[y][x] = 'F';
		flood_fill(tmp_map, y - 1, x);
		flood_fill(tmp_map, y + 1, x);
		flood_fill(tmp_map, y, x - 1);
		flood_fill(tmp_map, y, x + 1);
	}
}