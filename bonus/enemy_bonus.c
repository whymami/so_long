/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:23:27 by muguveli          #+#    #+#             */
/*   Updated: 2024/03/23 17:37:37 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_cords(t_game *game)
{
	int	h;
	int	w;

	h = -1;
	while (++h < game->map->map_y)
	{
		w = -1;
		while (++w < game->map->map_x)
		{
			if (game->map->game_map[h][w] == _ENEMY)
			{
				game->pos->enemy_x = w * 64;
				game->pos->enemy_y = h * 64;
			}
		}
	}
}

static void	change_dir(t_game *game, int y, int x)
{
	if (game->map->game_map[y][x] == _EXIT
		|| game->map->game_map[y][x] == _COLLECTIBLE
		|| game->map->game_map[y][x] == _WALL
		|| game->map->game_map[y][x] == _ENEMY)
	{
		if (game->pos->e_direction == _DIR_UP)
			game->pos->e_direction = _DIR_DOWN;
		else if (game->pos->e_direction == _DIR_DOWN)
			game->pos->e_direction = _DIR_RIGHT;
		else if (game->pos->e_direction == _DIR_RIGHT)
			game->pos->e_direction = _DIR_LEFT;
		else if (game->pos->e_direction == _DIR_LEFT)
			game->pos->e_direction = _DIR_UP;
	}
}

int	flood_fill_enemy(t_game *game, int y, int x)
{
	if (game->pos->enemy_x / 64 == game->pos->player_x / 64
		&& game->pos->enemy_y / 64 == game->pos->player_y / 64)
		ft_bns_exit(_FINISH_GAME, RED "YOU LOSE" COLOR_RESET, game);
	if (x < 0 || x > game->map->map_x || y < 0 || y > game->map->map_y)
		return (0);
	change_dir(game, y, x);
	if (game->map->game_map[y][x] != _WALL && game->map->game_map[y][x] != _EXIT
		&& game->map->game_map[y][x] != _COLLECTIBLE
		&& game->map->game_map[y][x] != _ENEMY)
	{
		game->map->game_map[y][x] = 'X';
		return (1);
	}
	return (0);
}

static void	whereisenemy2(t_game *game, int i)
{
	if (game->pos->e_direction == _DIR_RIGHT)
	{
		if (!(i % 30) && flood_fill_enemy(game, game->pos->enemy_y / 64,
				game->pos->enemy_x / 64 + 1))
			game->map->game_map[game->pos->enemy_y / 64][game->pos->enemy_x
				/ 64] = '0';
	}
	else if (game->pos->e_direction == _DIR_DOWN)
	{
		if (!(i % 30) && flood_fill_enemy(game, game->pos->enemy_y / 64 + 1,
				game->pos->enemy_x / 64))
			game->map->game_map[game->pos->enemy_y / 64][game->pos->enemy_x
				/ 64] = '0';
	}
}

void	whereisenemy(t_game *game)
{
	static int	i = 0;

	enemy_cords(game);
	i++;
	if (game->pos->e_direction == _DIR_LEFT)
	{
		if (!(i % 30) && flood_fill_enemy(game, game->pos->enemy_y / 64,
				game->pos->enemy_x / 64 - 1))
			game->map->game_map[game->pos->enemy_y / 64][game->pos->enemy_x
				/ 64] = '0';
	}
	else if (game->pos->e_direction == _DIR_UP)
	{
		if (!(i % 30) && flood_fill_enemy(game, game->pos->enemy_y / 64 - 1,
				game->pos->enemy_x / 64))
			game->map->game_map[game->pos->enemy_y / 64][game->pos->enemy_x
				/ 64] = '0';
	}
	whereisenemy2(game, i);
}
