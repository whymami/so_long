#include "so_long.h"
#include "unistd.h"
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

int ft_len_not_nl(char *str)
{
	int i;

	i  = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

void ft_equal_null(t_game *game)
{
	game->map->map_X = 0;
	game->map->map_Y = 0;
	game->counters->c_counter = 0;
	game->counters->e_counter = 0;
	game->counters->p_counter = 0;
}