#ifndef SO_LONG_H
#define SO_LONG_H

# include "lib/mlx/mlx.h"
# include "lib/libft/libft.h"
# include "lib/get_next_line/get_next_line.h"

# define _ELEMENTS "10PEC"
# define _WALL '1'
# define _GROUND '0'
# define _COLLECTIBLE 'C'
# define _PLAYER 'P'
# define _EXIT 'E'

# define _KEY_A 0
# define _KEY_S 1
# define _KEY_D 2
# define _KEY_W 13
# define _KEY_ESC 53
# define _KEY_EXİT 17

#define _INV_ARG 1
#define _INV_ARG_MSG "ERROR: INVALID ARGUMENT\nUSAGE: ./so_long <map/map.ber>"
#define _MAP_NAME 2
#define _MAP_NAME_MSG "ERROR: Map name cannot be left blank"
#define _INV_EXTENTION 3
#define _INV_EXTENTION_MSG "ERROR: Invalid file extension. Map file must have the .ber extension"
#define _MAP_NOT_OPEN 4
#define _MAP_NOT_OPEN_MSG "ERROR: Map not found"
#define _MAP_LENGTH 5
#define _MAP_LENGTH_MSG "ERROR: The map length is inconsistent"

typedef struct s_map
{
	char **game_map;
	int map_X;
	int map_Y;
}	t_map;

typedef struct s_counter
{
	int	p_counter;
	int	e_counter;
	int	c_counter;
}	t_counter;

typedef	 struct s_locate
{
	int player_X;
	int player_Y;
	int exit_X;
	int exit_Y;
	int move;
	int direction;
}	t_locate;

typedef struct s_texture
{
	void	*player_img;
	void	*player_left_img;
	void	*ground_img;
	void	*exit_img;
	void	*exit_full_img;
	void	*coll_img;
	void	*wall_img;
}	t_textures;


typedef struct s_state
{
	void *mlx;
	void *window;
	t_map *map;
	t_counter *counters;
	t_locate *pos;
	t_textures image;
}	t_game;

void ft_exit(int excode);
int ft_len_not_nl(char *str);
void ft_allocater(t_game *game);
void	ft_get_cords(t_game *game);
void flood_fill (t_map *tmp_map, int y, int x);

#endif
