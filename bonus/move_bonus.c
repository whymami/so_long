/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:18:09 by beyarsla          #+#    #+#             */
/*   Updated: 2024/03/23 14:54:03 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_mouse_exit(t_game *game)
{
	ft_bns_exit(_SUCC_EXIT, GREEN"Exit successful"COLOR_RESET, game);
	return (1);
}

static void	ft_pos_control(t_game *game)
{
	if (game->map->game_map[game->pos->player_y / 64][game->pos->player_x
		/ 64] == _COLLECTIBLE && game->counters->c_counter--)
	{
		game->map->game_map[game->pos->player_y / 64][game->pos->player_x
			/ 64] = _GROUND;
		game->score++;
	}
	if (game->map->game_map[game->pos->player_y / 64][game->pos->player_x
		/ 64] == _EXIT && game->counters->c_counter == 0)
		ft_bns_exit(_FINISH_GAME, YELLOW"Caillou collected all strawberry"
			COLOR_RESET " 🥳", game);
}

static int	is_move(t_game *game, int keycode)
{
	if (keycode == _KEY_A)
		if (game->map->game_map[game->pos->player_y / 64][game->pos->player_x
			/ 64 - 1] == _WALL)
			return (0);
	if (keycode == _KEY_D)
		if (game->map->game_map[game->pos->player_y / 64][game->pos->player_x
			/ 64 + 1] == _WALL)
			return (0);
	if (keycode == _KEY_W)
		if (game->map->game_map[game->pos->player_y / 64
				- 1][game->pos->player_x / 64] == _WALL)
			return (0);
	if (keycode == _KEY_S)
		if (game->map->game_map[game->pos->player_y / 64
				+ 1][game->pos->player_x / 64] == _WALL)
			return (0);
	return (1);
}

static void	key_a_d(t_game *game, int keycode)
{
	if (keycode == _KEY_A)
	{
		if (is_move(game, keycode) && game->pos->move++)
		{
			game->pos->direction = 1;
			game->pos->player_x -= 64;
		}
	}
	if (keycode == _KEY_D)
	{
		if (is_move(game, keycode) && game->pos->move++)
		{
			game->pos->direction = 0;
			game->pos->player_x += 64;
		}
	}
}

int	ft_get_keycode(int keycode, t_game *game)
{
	if (keycode == _KEY_ESC)
		ft_bns_exit(_SUCC_EXIT, GREEN "Exit successful" COLOR_RESET, game);
	if (keycode == _KEY_A || keycode == _KEY_D)
		key_a_d(game, keycode);
	if (keycode == _KEY_W)
		if (is_move(game, keycode) && game->pos->move++)
			game->pos->player_y -= 64;
	if (keycode == _KEY_S)
		if (is_move(game, keycode) && game->pos->move++)
			game->pos->player_y += 64;
	ft_pos_control(game);
	return (0);
}
