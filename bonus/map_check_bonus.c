/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:43:50 by beyarsla          #+#    #+#             */
/*   Updated: 2024/03/23 15:13:19 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_bns_game_map_check(t_game *game)
{
	int	first_line;
	int	contro_line;
	int	y;

	y = 1;
	first_line = ft_len_not_nl(game->map->game_map[0]);
	while (y < game->map->map_y)
	{
		contro_line = ft_len_not_nl(game->map->game_map[y++]);
		if (first_line != contro_line)
			ft_bns_exit(_MAP_LENGTH,
				YELLOW "The map length is inconsistent" COLOR_RESET, game);
	}
	ft_window_size(game);
	ref_control(game);
}

static void	ft_bns_read_map(char *str, t_game *game)
{
	int	y;
	int	fd;

	y = 0;
	game->map->game_map = malloc(game->map->map_y * sizeof(char *));
	if (!game->map->game_map)
		ft_bns_exit(_ALLOCATE_ERR,
			YELLOW "failed to allocate memory space" COLOR_RESET, game);
	fd = open(str, O_RDONLY);
	while (y < game->map->map_y)
		game->map->game_map[y++] = get_next_line(fd);
	close(fd);
	ft_bns_game_map_check(game);
}

static void	ft_bns_get_map_size(char *str)
{
	int		fd;
	char	*line;
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		ft_bns_exit(_ALLOCATE_ERR,
			YELLOW "failed to allocate memory space" COLOR_RESET, game);
	game->map = ft_calloc(1, sizeof(t_map));
	if (!game->map)
		ft_bns_exit(_ALLOCATE_ERR,
			YELLOW "Failed to allocate memory space" COLOR_RESET, game);
	fd = open(str, O_RDONLY);
	game->map->map_y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		game->map->map_x = ft_strlen(line);
		game->map->map_y++;
		free(line);
	}
	close(fd);
	ft_bns_read_map(str, game);
}

void	ft_bns_map_check(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (!str[0] && close(fd))
		ft_bns_exit(_MAP_NAME,
			YELLOW "Map name cannot be left blank" COLOR_RESET, NULL);
	if (ft_strrchr(str, '.') && ft_strrchr(str, 'b') && ft_strrchr(str, 'e')
		&& ft_strrchr(str, 'r'))
	{
		if (3 > fd)
		{
			close(fd);
			ft_bns_exit(_MAP_NOT_OPEN, YELLOW "Map not found" COLOR_RESET,
				NULL);
		}
		else
		{
			close(fd);
			ft_bns_get_map_size(str);
		}
	}
	else
		ft_bns_exit(_INV_EXTENTION, YELLOW
			"Invalid file extension. Map file must have the .ber extension"
			COLOR_RESET, NULL);
}
