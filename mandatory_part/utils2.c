/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:23:58 by muguveli          #+#    #+#             */
/*   Updated: 2024/03/26 12:32:45 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	ber_control(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[--len] == 'r' && str[--len] == 'e'
		&& str[--len] == 'b' && str[--len] == '.')
		return (1);
	return (0);
}
