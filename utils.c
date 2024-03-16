#include "so_long.h"

void ft_dispose_map(t_map *map)
{
	if (!map)
		return ;
	int i;

	i = -1;
	while (++i < map->map_Y)
		free(map->game_map[i]);
	free(map->game_map);
}
void ft_dispose (t_game *game)
{
	if (!game)
		return ;
	free(game->counters);
	ft_dispose_map(game->map);
	free(game->pos);
	free(game->image);
	free(game->map);
	free(game);
}

void	ft_exit(int err_no, char *err, t_game *game)
{
	ft_dispose(game);

	if (err_no == _SUCC_EXIT || err_no == _FINISH_GAME)
	{
		ft_putstr_fd(err, 2);
		exit (0);
	}
	ft_putstr_fd("ERROR: Excited With (", 2);
	ft_putnbr_fd(err_no, 2);
	ft_putstr_fd("): ", 2);
	ft_putendl_fd(err, 2);
	exit(err_no);
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