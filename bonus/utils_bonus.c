/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:01:58 by muguveli          #+#    #+#             */
/*   Updated: 2024/03/26 13:02:00 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_dispose_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = -1;
	while (++i < map->map_y)
		free(map->game_map[i]);
	free(map->game_map);
}

void	ft_dispose(t_game *game)
{
	if (!game)
		return ;
	free(game->counters);
	ft_dispose_map(game->map);
	free(game->pos);
	free(game->image);
	free(game->map);
	free(game);
}

void	ft_bns_exit(int err_no, char *err, t_game *game)
{
	ft_dispose(game);
	if (err_no == _SUCC_EXIT || err_no == _FINISH_GAME)
	{
		if (err_no == _FINISH_GAME)
			ft_printf(BOLD YELLOW "Move Step: %d\n"COLOR_RESET BOLD YELLOW
				"Score: %d\n"COLOR_RESET, game->pos->move, game->score);
		ft_putstr_fd(err, 2);
		exit(0);
	}
	ft_putstr_fd(RED "ERROR: Excited With (" COLOR_RESET, 2);
	ft_putnbr_fd(err_no, 2);
	ft_putstr_fd(RED ") " COLOR_RESET, 2);
	ft_putendl_fd(err, 2);
	exit(err_no);
}

void	ft_get_cords(t_game *game)
{
	int	h;
	int	w;

	h = -1;
	game->pos = ft_calloc(1, sizeof(t_locate));
	if (!game->pos)
		ft_bns_exit(_ALLOCATE_ERR,
			YELLOW "Failed to allocate memory space" COLOR_RESET, game);
	while (++h < game->map->map_y)
	{
		w = -1;
		while (++w < game->map->map_x)
		{
			if (game->map->game_map[h][w] == _PLAYER)
			{
				game->pos->player_x = w * 64;
				game->pos->player_y = h * 64;
			}
			if (game->map->game_map[h][w] == _EXIT)
			{
				game->pos->exit_x = w * 64;
				game->pos->exit_y = h * 64;
			}
		}
	}
}

int	ft_len_not_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}
