/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:02:00 by beyarsla          #+#    #+#             */
/*   Updated: 2024/03/21 16:47:49 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flood_fill(t_map *tmp_map, int y, int x)
{
	if (x < 0 || x > tmp_map->map_x || y < 0 || y > tmp_map->map_y)
		return ;
	if (tmp_map->game_map[y][x] != _WALL && tmp_map->game_map[y][x] != 'F')
	{
		tmp_map->game_map[y][x] = 'F';
		flood_fill(tmp_map, y - 1, x);
		flood_fill(tmp_map, y + 1, x);
		flood_fill(tmp_map, y, x - 1);
		flood_fill(tmp_map, y, x + 1);
	}
}

int	is_reachable(t_map *tmp_game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < tmp_game->map_y)
	{
		j = -1;
		while (++j < tmp_game->map_x)
		{
			if (tmp_game->game_map[i][j] == _EXIT)
				return (1);
			else if (tmp_game->game_map[i][j] == _COLLECTIBLE)
				return (2);
		}
	}
	ft_dispose_map(tmp_game);
	return (0);
}
