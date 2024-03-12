#include "so_long.h"
#include "unistd.h"


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

	h = 0;
	game->pos = ft_calloc(1, sizeof(t_locate));
	while (h < game->map->map_Y)
	{
		w = 0;
		while (w < game->map->map_X)
		{
			if (game->map->game_map[h][w] == _PLAYER)
			{
				game->pos->player_X = w * 64;
				game->pos->player_Y = h * 64;
			}
			w++;
		}
		h++;
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