/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:43:10 by muguveli          #+#    #+#             */
/*   Updated: 2024/03/16 18:50:11 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/ft_printf/ft_printf.h"

# define _ELEMENTS "10PECX"
# define _WALL '1'
# define _GROUND '0'
# define _COLLECTIBLE 'C'
# define _PLAYER 'P'
# define _EXIT 'E'
# define _ENEMY 'X'

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

typedef struct s_player_idle
{
	void	*player_idle1;
	void	*player_idle2;
	void	*player_idle3;
	void	*player_idle4;
}			t_player_idle;

typedef struct s_player_walk
{
	void	*player_walk1;
	void	*player_walk2;
	void	*player_walk3;
	void	*player_walk4;
}			t_player_walk;

typedef struct s_player
{
	t_player_idle	*idle;
	t_player_walk	*walk;
}			t_player;

#endif
