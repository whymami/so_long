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

#define _SUCC_EXIT 0
#define _INV_ARG 1
#define _MAP_NAME 2
#define _INV_EXTENTION 3
#define _MAP_NOT_OPEN 4
#define _MAP_LENGTH 5
#define _ALLOCATE_ERR 6
#define _COLLECTIBLE_COUNT 7
#define _UNRECOGNİZE_CHAR 8
#define _FRAME_ERR 9
#define _EXIT_COUNT 10
#define _PLAYER_COUNT 11
#define _COLL_REACHABLE 12
#define _EXIT_REACHABLE 13
#define _FINISH_GAME 14
#define PLAYER_XPM_NOT_FOUND 15
#define EXIT_XPM_NOT_FOUND 16
#define EXITFULL_XPM_NOT_FOUND 17
#define PLAYERLEFT_XPM_NOT_FOUND 18
#define WALL_XPM_NOT_FOUND 19
#define GRASS_XPM_NOT_FOUND 20
#define COLL_XPM_NOT_FOUND 21

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
	t_textures *image;
}	t_game;

void	ft_exit(int err_no, char *err, t_game *game);
int ft_len_not_nl(char *str);
void ft_allocater(t_game *game);
void	ft_get_cords(t_game *game);
void flood_fill (t_map *tmp_map, int y, int x);
void ft_dispose_map(t_map *map);
void ft_dispose (t_game *game);

#endif
