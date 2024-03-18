/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:18:13 by muguveli          #+#    #+#             */
/*   Updated: 2024/03/18 14:29:08 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_window_size(t_game *game)
{
	ft_printf("map_x: %d\n", game->map->map_x);
	ft_printf("map_y: %d\n", game->map->map_y);
	if (game->map->map_x > 20 || game->map->map_y > 10)
		ft_exit(WINDOW_SIZE_ERROR, "Window size is too big", game);
}

static int	ft_xpm_control(t_game *game)
{
	int	fd;

	fd = open("texture/collect.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_exit(COLL_XPM_NOT_FOUND, "collect.xpm not found", game);
	fd = open("texture/exit.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_exit(EXIT_XPM_NOT_FOUND, "exit.xpm not found", game);
	fd = open("texture/grass.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_exit(GRASS_XPM_NOT_FOUND, "grass.xpm not found", game);
	fd = open("texture/character.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_exit(PLAYER_XPM_NOT_FOUND, "player.xpm not found", game);
	fd = open("texture/player_left.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_exit(PLAYERLEFT_XPM_NOT_FOUND, "player_left.xpm not found", game);
	fd = open("texture/wall.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_exit(WALL_XPM_NOT_FOUND, "wall.xpm not found", game);
	fd = open("texture/exitfull.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_exit(EXITFULL_XPM_NOT_FOUND, "exitfull.xpm not found", game);
	return (1);
}

void ft_player_left_xpm(t_game *game)
{
	int	x;
	int	y;
	game->image->player_right_walk1 = mlx_xpm_file_to_image(game->mlx,"bonus/texture/player_walk/run0.xpm", &x, &y);
	game->image->player_right_walk2 = mlx_xpm_file_to_image(game->mlx,"bonus/texture/player_walk/run1.xpm", &x, &y);
	game->image->player_right_walk3 = mlx_xpm_file_to_image(game->mlx,"bonus/texture/player_walk/run2.xpm", &x, &y);
	game->image->player_right_walk4 = mlx_xpm_file_to_image(game->mlx,"bonus/texture/player_walk/run3.xpm", &x, &y);
	game->image->player_right_walk5 = mlx_xpm_file_to_image(game->mlx,"bonus/texture/player_walk/run4.xpm", &x, &y);
	game->image->player_right_walk6 = mlx_xpm_file_to_image(game->mlx,"bonus/texture/player_walk/run5.xpm", &x, &y);
	game->image->player_right_walk7 = mlx_xpm_file_to_image(game->mlx,"bonus/texture/player_walk/run6.xpm", &x, &y);
}

void	ft_get_path_xpm(t_game *game)
{
	int	x;
	int	y;

	game->image = ft_calloc(1, sizeof(t_textures));
	if (ft_xpm_control(game))
	{
		ft_player_left_xpm(game);
		game->image->coll_img = mlx_xpm_file_to_image(game->mlx,
				"bonus/texture/collect.xpm", &x, &y);
		game->image->exit_img = mlx_xpm_file_to_image(game->mlx,
				"bonus/texture/exit.xpm", &x, &y);
		game->image->ground_img = mlx_xpm_file_to_image(game->mlx,
				"bonus/texture/grass.xpm", &x, &y);
		game->image->wall_img = mlx_xpm_file_to_image(game->mlx,
				"bonus/texture/wall.xpm", &x, &y);
		game->image->exit_full_img = mlx_xpm_file_to_image(game->mlx,
				"bonus/texture/exitfull.xpm", &x, &y);
	}
}
