/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:47:01 by beyarsla          #+#    #+#             */
/*   Updated: 2024/03/22 16:13:14 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	copy_map(t_game *game)
{
	t_map	tmp_map;
	int		i;
	int		result;

	tmp_map.game_map = ft_calloc(game->map->map_y, sizeof(char *));
	i = -1;
	while (++i < game->map->map_y)
		tmp_map.game_map[i] = ft_strdup(game->map->game_map[i]);
	tmp_map.map_x = game->map->map_x;
	tmp_map.map_y = game->map->map_y;
	flood_fill(&tmp_map, game->pos->player_y / 64, game->pos->player_x / 64);
	result = is_reachable(&tmp_map);
	if (result == 2)
		ft_bns_exit(_COLL_REACHABLE, "Collectible not reachable", game);
	else if (result == 1)
		ft_bns_exit(_EXIT_REACHABLE, "Exit not reachable", game);
}

static void	ft_frame_control(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	x = -1;
	while (++y < game->map->map_y)
		if ((game->map->game_map[y][0] != _WALL
			|| game->map->game_map[y][ft_len_not_nl(game->map->game_map[y])
			- 1] != _WALL))
			ft_bns_exit(_FRAME_ERR, "The borders of the map have to be a wall",
				game);
	while (++x < game->map->map_x)
		if ((game->map->game_map[0][x] != '1'
			|| game->map->game_map[game->map->map_y - 1][x] != '1'))
			ft_bns_exit(_FRAME_ERR, "The borders of the map have to be a wall",
				game);
	ft_create_window(game);
}

static void	ft_get_count(char c, t_game *game)
{
	if (c == _PLAYER && game->counters->p_counter++)
		if (game->counters->p_counter > 1 || game->counters->p_counter == 0)
			ft_bns_exit(_PLAYER_COUNT, "There must be one player in the game",
				game);
	if (c == _EXIT && game->counters->e_counter++)
		if (game->counters->e_counter > 1 || game->counters->e_counter == 0)
			ft_bns_exit(_EXIT_COUNT, "There should be one exit in the game", game);
	if (c == _ENEMY && game->counters->x_counter++)
		if (game->counters->x_counter > 1)
			ft_bns_exit(_ENEMY_COUNT, "There should be one enemy in the game", game);
	if (c == _COLLECTIBLE)
		game->counters->c_counter++;
}

void	ref_control(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	game->counters = ft_calloc(1, sizeof(t_counter));
	if (!game->counters)
		ft_bns_exit(_ALLOCATE_ERR, "failed to allocate memory space", game);
	while (++y < game->map->map_y)
	{
		x = -1;
		while (++x < game->map->map_x)
		{
			if (ft_strchr(_ELEMENTS, game->map->game_map[y][x]) == 0)
				ft_bns_exit(_CHAR_ERR, "Unrecognized character in map file", game);
			else if (game->map->game_map[y][x] == _PLAYER)
				ft_get_count(_PLAYER, game);
			else if (game->map->game_map[y][x] == _COLLECTIBLE)
				ft_get_count(_COLLECTIBLE, game);
			else if (game->map->game_map[y][x] == _EXIT)
				ft_get_count(_EXIT, game);
			else if (game->map->game_map[y][x] == _ENEMY)
				ft_get_count(_ENEMY, game);
		}
	}
	if (game->counters->c_counter < 1)
		ft_bns_exit(_COLLECTIBLE_COUNT, "At least one must be collectible", game);
	ft_frame_control(game);
}
