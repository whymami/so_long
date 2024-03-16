#include "stdlib.h"
#include "so_long.h"
#include "stdlib.h"
#include "unistd.h"
#include "fcntl.h"
#include "stdio.h"

static int ft_xpm_control (t_game *game)
{
	int fd;

	fd = open("texture/collect.xpm",O_RDONLY);
	if (fd < 0 && close(fd))
		ft_exit(COLL_XPM_NOT_FOUND,"collect.xpm not found",game);
	fd = open("texture/exit.xpm",O_RDONLY);
	if (fd < 0 && close(fd))
		ft_exit(EXIT_XPM_NOT_FOUND,"exit.xpm not found",game);
	fd = open("texture/grass.xpm",O_RDONLY);
	if (fd < 0 && close(fd))
		ft_exit(GRASS_XPM_NOT_FOUND,"grass.xpm not found",game);
	fd = open("texture/character.xpm",O_RDONLY);
	if (fd < 0 && close(fd))
		ft_exit(PLAYER_XPM_NOT_FOUND,"player.xpm not found",game);
	fd = open("texture/player_left.xpm",O_RDONLY);
	if (fd < 0 && close(fd))
		ft_exit(PLAYERLEFT_XPM_NOT_FOUND,"player_left.xpm not found",game);
	fd = open("texture/wall.xpm",O_RDONLY);
	if (fd < 0 && close(fd))
		ft_exit(WALL_XPM_NOT_FOUND,"wall.xpm not found",game);
	fd = open("texture/exitfull.xpm",O_RDONLY);
	if (fd < 0 && close(fd))
		ft_exit(EXITFULL_XPM_NOT_FOUND,"exitfull.xpm not found",game);
	return (1);
}

static void ft_get_path_xpm(t_game *game)
{
    int x;
    int y;
	game->image = ft_calloc(1,sizeof(t_textures));
	if (ft_xpm_control(game))
	{
		game->image->coll_img = mlx_xpm_file_to_image(game->mlx,"texture/collect.xpm",&x,&y);
		game->image->exit_img = mlx_xpm_file_to_image(game->mlx,"texture/exit.xpm", &x,&y);
		game->image->ground_img = mlx_xpm_file_to_image(game->mlx,"texture/grass.xpm",&x,&y);
		game->image->player_img = mlx_xpm_file_to_image(game->mlx,"texture/character.xpm",&x,&y);
		game->image->player_left_img = mlx_xpm_file_to_image(game->mlx,"texture/player_left.xpm",&x,&y);
		game->image->wall_img = mlx_xpm_file_to_image(game->mlx,"texture/wall.xpm",&x,&y);
		game->image->exit_full_img = mlx_xpm_file_to_image(game->mlx,"texture/exitfull.xpm",&x,&y);
	}
}

int ft_put_image(t_game *game)
{
	int x;
	int y;

	y = -1;
	while (++y < game->map->map_Y)
	{
		x = -1;
		while(++x < game->map->map_X)
		{
			mlx_put_image_to_window(game->mlx,game->window,game->image->ground_img,x*64,y*64);
			if(game->map->game_map[y][x] == _WALL)
				mlx_put_image_to_window(game->mlx,game->window,game->image->wall_img,x *64,y*64);
			if (game->map->game_map[y][x] == _COLLECTIBLE)
				mlx_put_image_to_window(game->mlx,game->window,game->image->coll_img,x*64,y*64);
		}
		if (game->pos->direction == 1)
			mlx_put_image_to_window(game->mlx, game->window, game->image->player_left_img, game->pos->player_X, game->pos->player_Y);
		else
			mlx_put_image_to_window(game->mlx, game->window, game->image->player_img, game->pos->player_X, game->pos->player_Y);
		if (game->counters->c_counter > 0)
			mlx_put_image_to_window(game->mlx, game->window, game->image->exit_img, game->pos->exit_X, game->pos->exit_Y);
		else
			mlx_put_image_to_window(game->mlx, game->window, game->image->exit_full_img, game->pos->exit_X, game->pos->exit_Y);
	}
	return 0;
}

static int is_move(t_game *game, int keycode)
{
	if (keycode == _KEY_A)
		if (game->map->game_map[game->pos->player_Y / 64][game->pos->player_X / 64 - 1] == _WALL)
			return 0;
	if (keycode == _KEY_D)
		if (game->map->game_map[game->pos->player_Y / 64][game->pos->player_X / 64 + 1] == _WALL)
			return 0;
	if (keycode == _KEY_W)
		if (game->map->game_map[game->pos->player_Y / 64 - 1][game->pos->player_X / 64] == _WALL)
			return 0;
	if (keycode == _KEY_S)
		if (game->map->game_map[game->pos->player_Y / 64 + 1][game->pos->player_X / 64] == _WALL)
			return 0;
	return 1;
}

static void ft_pos_control (t_game *game)
{
	if (game->map->game_map[game->pos->player_Y / 64][game->pos->player_X / 64] == _COLLECTIBLE && game->counters->c_counter--)
		game->map->game_map[game->pos->player_Y / 64][game->pos->player_X / 64] = _GROUND;
	if (game->map->game_map[game->pos->player_Y / 64][game->pos->player_X / 64] == _EXIT && game->counters->c_counter == 0)
		ft_exit(_FINISH_GAME,"Caillou collected all strawberry 🥳",game);
}
static int ft_get_keycode (int keycode, t_game *game)
{
	if(keycode == _KEY_ESC || keycode == _KEY_EXİT)
		ft_exit(_SUCC_EXIT,"Exit successful",game);
	if (keycode == _KEY_A)
		if(is_move(game,keycode) && printf("Move Step %d\n",game->pos->move++))
		{
			game->pos->direction = 1;
			game->pos->player_X -= 64;
		}
	if (keycode == _KEY_D)
		if(is_move(game,keycode) && printf("Move Step %d\n",game->pos->move++))
		{
			game->pos->direction = 0;
			game->pos->player_X += 64;
		}
	if (keycode == _KEY_W)
		if(is_move(game,keycode) && printf("Move Step %d\n",game->pos->move++))
			game->pos->player_Y -= 64;
	if (keycode == _KEY_S)
		if(is_move(game,keycode) && printf("Move Step %d\n",game->pos->move++))
			game->pos->player_Y += 64;
	ft_pos_control(game);
	return 0;
}


static int is_reachable(t_map *tmp_game)
{
	int i;
	int j;

	i = -1;
	while (++i < tmp_game->map_Y)
	{
		j = -1;
		while (++j < tmp_game->map_X)
			if(tmp_game->game_map[i][j] == _EXIT)
				return (1);
			else if(tmp_game->game_map[i][j] == _COLLECTIBLE)
				return (2);
	}
	ft_dispose_map(tmp_game);
	return (0);
}

static void copy_map (t_game *game)
{
	t_map tmp_map;
	int i;
	int result;

	tmp_map.game_map = ft_calloc(game->map->map_Y, sizeof(char *));
	i = -1;
	while (++i < game->map->map_Y)
		tmp_map.game_map[i] = ft_strdup(game->map->game_map[i]);
	tmp_map.map_X = game->map->map_X;
	tmp_map.map_Y = game->map->map_Y;
	flood_fill(&tmp_map,game->pos->player_Y/64,game->pos->player_X/64);
	result = is_reachable(&tmp_map);
	if (result == 2)
		ft_exit(_COLL_REACHABLE, "Collectible not reachable", game);
	else if (result == 1)
		ft_exit(_EXIT_REACHABLE, "Exit not reachable", game);
}

static int ft_mouse_exit(t_game *game)
{
	ft_exit(_SUCC_EXIT,"Exit successful",game);
	return (1);
}
static void ft_create_window(t_game *game)
{
	game->mlx = mlx_init();
	ft_get_cords(game);
	copy_map(game);
	game->window = mlx_new_window(game->mlx,game->map->map_X * 64,game->map->map_Y * 64 , "SO_LONG");
	ft_get_path_xpm(game);
	mlx_clear_window(game->mlx,game->window);
	mlx_loop_hook(game->mlx, ft_put_image, game);
	mlx_key_hook(game->window,ft_get_keycode,game);
	mlx_hook(game->window,17,0,ft_mouse_exit,game);
	mlx_loop(game->mlx);
}

void ft_get_count (char c, int x, int y, t_game *game)
{
	if(c == _PLAYER && game->counters->p_counter++)
		if(game->counters->p_counter > 1 || game->counters->p_counter == 0)
			ft_exit(_PLAYER_COUNT,"There must be one player in the game", game);
	if (c == _EXIT && game->counters->e_counter++)
		if(game->counters->e_counter > 1 || game->counters->e_counter == 0)
			ft_exit(_EXIT_COUNT,"There should be one exit in the game", game);
	if (c == _COLLECTIBLE)
		game->counters->c_counter++;
}

static void ft_frame_control(t_game *game)
{
	int x;
	int y;

	y = -1;
	x = -1;
	while (++y < game->map->map_Y)
		if ((game->map->game_map[y][0] != _WALL || game->map->game_map[y][ft_len_not_nl(game->map->game_map[y]) - 1] != _WALL))
			ft_exit(_FRAME_ERR,"The borders of the map have to be a wall",game);
	while (++x < game->map->map_X)
		if ((game->map->game_map[0][x] != '1' || game->map->game_map[game->map->map_Y - 1][x] != '1'))
			ft_exit(_FRAME_ERR,"The borders of the map have to be a wall",game);
	ft_create_window(game);
}

static void ref_control(t_game *game)
{
	int x;
	int y;

	y = -1;
	game->counters = ft_calloc(1, sizeof(t_counter));
	if(!game->counters)
		ft_exit(_ALLOCATE_ERR, "failed to allocate memory space", game);
	while(++y < game->map->map_Y)
	{
		x = -1;
		while (++x < game->map->map_X)
		{
			if (ft_strchr(_ELEMENTS, game->map->game_map[y][x]) == 0)
				ft_exit(_UNRECOGNİZE_CHAR,"Unrecognized character in map file",game); 
			else if (game->map->game_map[y][x] == _PLAYER)
				ft_get_count(_PLAYER,x,y,game);
			else if (game->map->game_map[y][x] == _COLLECTIBLE)
				ft_get_count(_COLLECTIBLE,x,y,game);
			else if (game->map->game_map[y][x] == _EXIT)
				ft_get_count(_EXIT, x,y,game);
		}
	}
	if(game->counters->c_counter < 1)
		ft_exit(_COLLECTIBLE_COUNT , "At least one must be collectible" , game);
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
			ft_exit(_MAP_LENGTH, "The map length is inconsistent", game);
	}
	ref_control(game);
}

static void ft_read_map(char *str, t_game *game)
{
	int y;
	int fd;

	y = 0;
	game->map->game_map = malloc(game->map->map_Y * sizeof(char *));
	if(!game->map->game_map)
		ft_exit(_ALLOCATE_ERR, "failed to allocate memory space", game);
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

	game = ft_calloc(1,sizeof(t_game));
	if (!game)
		ft_exit(_ALLOCATE_ERR,"failed to allocate memory space",game);
	game->map = ft_calloc(1,sizeof(t_map));
	if (!game->map)
		ft_exit(_ALLOCATE_ERR,"Failed to allocate memory space",game);
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
	free(line);
	close(fd);
	ft_read_map(str,game);
}

static void	ft_map_check(char *str)
{
	int fd;

	fd = open(str,O_RDONLY);
	if (!str[0] && close(fd))
		ft_exit(_MAP_NAME, "Map name cannot be left blank", NULL);
	if (ft_strrchr(str, '.') && ft_strrchr(str, 'b') && ft_strrchr(str, 'e')
		&& ft_strrchr(str, 'r'))
		if (3 > fd)
		{
			close(fd);
			ft_exit(_MAP_NOT_OPEN, "Map not found", NULL);
		}
		else
		{
			close(fd);
			ft_get_map_size(str);
		}
	else
		ft_exit(_INV_EXTENTION, "Invalid file extension. Map file must have the .ber extension", NULL);
		
}

void func(int argc, char **argv)
{
	if (argc == 2)
		ft_map_check(argv[1]);
	else
		ft_exit(_INV_ARG, "INVALID ARGUMENT\nUSAGE: ./so_long <map/map.ber>", NULL);
	
}

int	main(int argc, char **argv)
{
	func(argc, argv);
}


