/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:41:30 by beyarsla          #+#    #+#             */
/*   Updated: 2024/03/22 17:05:41 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/ft_printf/ft_printf.h"
# include "fcntl.h"

# define _ELEMENTS "10PECX"
# define _WALL '1'
# define _GROUND '0'
# define _COLLECTIBLE 'C'
# define _PLAYER 'P'
# define _EXIT 'E'
# define _ENEMY 'X'

# define _DIR_UP 0
# define _DIR_DOWN 1
# define _DIR_LEFT 2
# define _DIR_RİGHT 3

# define _KEY_A 0
# define _KEY_S 1
# define _KEY_D 2
# define _KEY_W 13
# define _KEY_ESC 53
# define _KEY_EXIT 17

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
# define _ENEMY_COUNT 23

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
	int x_counter;
}		t_counter;

typedef struct s_locate
{
	int	player_x;
	int	player_y;
	int enemy_x;
	int enemy_y;
	int	exit_x;
	int	exit_y;
	int	move;
	int	direction;
	int e_direction;
}		t_locate;

typedef struct s_collectible_node 
{
    int x;
    int y;
    struct s_collectible_node *next;
} 			t_collectible_node;

typedef struct s_texture
{
	void	*player_img;
	void	*player_left_img;
	void	*enemy_img;
	void	*enemy_left_img;
	void	*ground_img;
	void	*exit_img;
	void	*exit_full_img;
	void	*coll1_img;
	void	*coll2_img;
	void	*coll3_img;
	void	*wall1_img;
	void	*wall2_img;
	void	*wall3_img;
}			t_textures;


typedef struct s_state
{
	void		*mlx;
	void		*window;
	t_map		*map;
	t_counter	*counters;
	t_locate	*pos;
	t_textures	*image;
	t_collectible_node *collectibles;
}				t_game;

void	copy_map(t_game *game);
void	ref_control(t_game *game);
void	ft_window_size(t_game *game);
void	ft_get_path_xpm(t_game *game);
void	ft_create_window(t_game *game);
void	ft_bns_map_check(char *str);
int	ft_mouse_exit(t_game *game);
int	ft_get_keycode(int keycode, t_game *game);
void	ft_dispose_map(t_map *map);
void	ft_dispose(t_game *game);
void	ft_bns_exit(int err_no, char *err, t_game *game);
void	ft_get_cords(t_game *game);
int	ft_len_not_nl(char *str);
void	flood_fill(t_map *tmp_map, int y, int x);
int	is_reachable(t_map *tmp_game);
int whereisenemy (t_game *game);
int	flood_fill_enemy(t_game *game, int y, int x);


#endif