/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:47:06 by muguveli          #+#    #+#             */
/*   Updated: 2024/03/26 11:59:04 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/ft_printf/ft_printf.h"
# include "fcntl.h"

# define _ELEMENTS "10PEC"
# define _WALL '1'
# define _GROUND '0'
# define _COLLECTIBLE 'C'
# define _PLAYER 'P'
# define _EXIT 'E'

# define _KEY_EXIT 17

# ifndef _KEY_W
#  define _KEY_W 13
# endif

# ifndef _KEY_A
#  define _KEY_A 0
# endif

# ifndef _KEY_S
#  define _KEY_S 1
# endif

# ifndef _KEY_D
#  define _KEY_D 2
# endif

# ifndef _KEY_ESC
#  define _KEY_ESC 53
# endif

# define _SUCC_EXIT 0
# define _INV_ARG 1
# define _MAP_NAME 2
# define _INV_EXTENTION 3
# define _MAP_NOT_OPEN 4
# define _MAP_LENGTH 5
# define _ALLOCATE_ERR 6
# define _COLLECTIBLE_COUNT 7
# define _CHAR_ERR 8
# define _FRAME_ERR 9
# define _EXIT_COUNT 10
# define _PLAYER_COUNT 11
# define _COLL_REACHABLE 12
# define _EXIT_REACHABLE 13
# define _FINISH_GAME 14
# define PLAYER_XPM_NOT_FOUND 15
# define EXIT_XPM_NOT_FOUND 16
# define EXITFULL_XPM_NOT_FOUND 17
# define PLAYERLEFT_XPM_NOT_FOUND 18
# define WALL_XPM_NOT_FOUND 19
# define GRASS_XPM_NOT_FOUND 20
# define COLL_XPM_NOT_FOUND 21
# define WINDOW_SIZE_ERROR 22
# define EMPTY_MAP 23

typedef struct s_map
{
	char	**game_map;
	int		map_x;
	int		map_y;
}			t_map;

typedef struct s_counter
{
	int	p_counter;
	int	e_counter;
	int	c_counter;
}		t_counter;

typedef struct s_locate
{
	int	player_x;
	int	player_y;
	int	exit_x;
	int	exit_y;
	int	move;
	int	direction;
}		t_locate;

typedef struct s_texture
{
	void	*player_img;
	void	*player_left_img;
	void	*ground_img;
	void	*exit_img;
	void	*exit_full_img;
	void	*coll_img;
	void	*wall_img;
}			t_textures;

typedef struct s_state
{
	void		*mlx;
	void		*window;
	t_map		*map;
	t_counter	*counters;
	t_locate	*pos;
	t_textures	*image;
}				t_game;

void	ft_exit(int err_no, char *err, t_game *game);
int		ft_len_not_nl(char *str);
void	ft_allocater(t_game *game);
void	flood_fill(t_map *tmp_map, int y, int x);
void	ft_dispose_map(t_map *map);
void	ft_dispose(t_game *game);
void	ft_map_check(char *str);
void	ref_control(t_game *game);
void	ft_create_window(t_game *game);
void	ft_get_cords(t_game *game);
void	ft_get_path_xpm(t_game *game);
int		ft_get_keycode(int keycode, t_game *game);
int		ft_mouse_exit(t_game *game);
void	copy_map(t_game *game);
int		is_reachable(t_map *tmp_game);
void	ft_window_size(t_game *game);
int		ber_control(char *str);

#endif
