#include "stdlib.h"
#include "so_long.h"
#include "stdlib.h"
#include "unistd.h"
#include "fcntl.h"
#include "stdio.h"

static void ft_create_window(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,game->map->map_X * 64,game->map->map_Y * 64 , "SO_LONG");
	mlx_loop(game->mlx);
}

void ft_get_locate (char c, int x, int y, t_game *game)
{
	game->pos = ft_calloc(1,sizeof(t_locate));
	if(c == _PLAYER)
	{
		game->counters->p_counter++;
		if(game->counters->p_counter > 1 || game->counters->p_counter == 0 && write(1, "çıktım", 10))
			exit(1); // hata kodu ekle
		game->pos->player_X = x;
		game->pos->player_Y = y;
	}
	else if (c == _EXIT)
	{
		game->counters->e_counter++;
		if(game->counters->e_counter > 1 || game->counters->e_counter == 0 && write(1, "çıktım", 10))
			exit(1); // hata kodu ekle
		game->pos->exit_X = x;
		game->pos->exit_Y = y;
	}
	else if (c == _COLLECTIBLE)
		game->counters->c_counter++;
}

static void ft_frame_control(t_game *game)
{
	int x;
	int y;

	y = -1;
	x = -1;
	while (++y < game->map->map_Y)
		if ((game->map->game_map[y][0] != '1' || game->map->game_map[y][ft_len_not_nl(game->map->game_map[y]) - 1] != '1') && write(1, "başı sonu 1 değil", 21))
			exit(1);
	while (++x < game->map->map_X)
	{
		if ((game->map->game_map[0][x] != '1' || game->map->game_map[game->map->map_Y - 1][x] != '1') && write(1, "ortası 1 değil", 21))
			exit(1);
	}
	ft_create_window(game);
}

static void ref_control(t_game *game)
{
	int x;
	int y;

	y = -1;
	game->counters = ft_calloc(1, sizeof(t_counter));
	while(++y < game->map->map_Y)
	{
		x = -1;
		while (++x < game->map->map_X)
		{
			if (ft_strchr(_ELEMENTS, game->map->game_map[y][x]) == 0 && write(1, "kürtçe mi bu ne tanıyamadım\n", 33))
				exit(1); //hata kodu ekle
			else if (game->map->game_map[y][x] == _PLAYER)
				ft_get_locate(_PLAYER,x,y,game);
			else if (game->map->game_map[y][x] == _COLLECTIBLE)
				ft_get_locate(_COLLECTIBLE,x,y,game);
			else if (game->map->game_map[y][x] == _EXIT)
				ft_get_locate(_EXIT, x,y,game);
		}
	}
	if(game->counters->c_counter < 1 && write(1, "çıktım", 10))
		exit (1);
	ft_frame_control(game);
}
static void ft_game_map_check(t_game *game)
{
	int first_line;
	int contro_line;
	int y;

	y = 1;
	first_line = ft_len_not_nl(game->map->game_map[0]);
	while (y < game->map->map_Y)
	{
		contro_line = ft_len_not_nl(game->map->game_map[y++]);
		if(first_line != contro_line)
			ft_exit(_MAP_LENGTH);
	}
	ref_control(game);
}

static void ft_read_map(char *str, t_game *game)
{
	int y;
	int fd;

	y = 0;
	game->map->game_map = malloc(game->map->map_Y * sizeof(char *));
	fd = open(str, O_RDONLY);
	while (y < game->map->map_Y)
		game->map->game_map[y++] = get_next_line(fd);
	close(fd);
	ft_game_map_check(game);
}

static void ft_get_map_size(char *str)
{
	int fd;
	char *line;
	t_game *game;

	game = malloc(sizeof(t_game));
	if (!game)
		exit(1);
	game->map = ft_calloc(1,sizeof(t_map));
	if (!game->map)
		exit(1);
	fd = open(str, O_RDONLY);
	game->map->map_Y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if(line == NULL)
			break;
		game->map->map_X = ft_strlen(line);
		game->map->map_Y++;
		free(line);
	}
	close(fd);
	ft_read_map(str,game);
}

static void	ft_map_check(char *str)
{
	int fd;

	fd = open(str,O_RDONLY);
	if (!str[0])
		ft_exit(_MAP_NAME);
	if (ft_strrchr(str, '.') && ft_strrchr(str, 'b') && ft_strrchr(str, 'e')
		&& ft_strrchr(str, 'r'))
		if (3 > fd)
		{
			close(fd);
			ft_exit(_MAP_NOT_OPEN);
		}
		else
		{
			close(fd);
			ft_get_map_size(str);
		}
	else
		ft_exit(_INV_EXTENTION);
		
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_map_check(argv[1]);
	else
		ft_exit(1);
}