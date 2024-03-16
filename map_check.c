/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:00:14 by muguveli          #+#    #+#             */
/*   Updated: 2024/03/16 17:52:39 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_game_map_check(t_game *game)
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
			ft_exit(_MAP_LENGTH, "The map length is inconsistent", game);
	}
	ft_window_size(game);
	ref_control(game);
}

static void	ft_read_map(char *str, t_game *game)
{
	int	y;
	int	fd;

	y = 0;
	game->map->game_map = malloc(game->map->map_y * sizeof(char *));
	if (!game->map->game_map)
		ft_exit(_ALLOCATE_ERR, "failed to allocate memory space", game);
	fd = open(str, O_RDONLY);
	while (y < game->map->map_y)
		game->map->game_map[y++] = get_next_line(fd);
	close(fd);
	ft_game_map_check(game);
}

static void	ft_get_map_size(char *str)
{
	int		fd;
	char	*line;
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		ft_exit(_ALLOCATE_ERR, "failed to allocate memory space", game);
	game->map = ft_calloc(1, sizeof(t_map));
	if (!game->map)
		ft_exit(_ALLOCATE_ERR, "Failed to allocate memory space", game);
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
	free(line);
	close(fd);
	ft_read_map(str, game);
}

void	ft_map_check(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (!str[0] && close(fd))
		ft_exit(_MAP_NAME, "Map name cannot be left blank", NULL);
	if (ft_strrchr(str, '.') && ft_strrchr(str, 'b') && ft_strrchr(str, 'e')
		&& ft_strrchr(str, 'r'))
	{
		if (3 > fd)
		{
			close(fd);
			ft_exit(_MAP_NOT_OPEN, "Map not found", NULL);
		}
		else
		{
			close(fd);
			ft_get_map_size(str);
		}
	}
	else
		ft_exit(_INV_EXTENTION,
			"Invalid file extension. Map file must have the .ber extension",
			NULL);
}
