/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:15:55 by muguveli          #+#    #+#             */
/*   Updated: 2024/03/23 17:01:56 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_window_size(t_game *game)
{
	if (game->map->map_x > 20 || game->map->map_y > 10)
		ft_bns_exit(WINDOW_SIZE_ERROR,
			YELLOW "Window size is too big" COLOR_RESET, game);
}

static void	xpm_control2(t_game *game)
{
	int	fd;

	fd = open("texture/bonus_img/wall1.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_bns_exit(WALL_XPM_NOT_FOUND,
			YELLOW "wall1.xpm not found" COLOR_RESET, game);
	fd = open("texture/bonus_img/collect1.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_bns_exit(COLL_XPM_NOT_FOUND,
			YELLOW "collect1.xpm not found" COLOR_RESET, game);
	fd = open("texture/exitfull.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_bns_exit(EXITFULL_XPM_NOT_FOUND,
			YELLOW "exitfull.xpm not found" COLOR_RESET, game);
	fd = open("texture/bonus_img/enemy.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_bns_exit(EXITFULL_XPM_NOT_FOUND,
			YELLOW "enemy.xpm not found" COLOR_RESET, game);
}

static int	ft_xpm_control(t_game *game)
{
	int	fd;

	fd = open("texture/exit.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_bns_exit(EXIT_XPM_NOT_FOUND, YELLOW "exit.xpm not found" COLOR_RESET,
			game);
	fd = open("texture/grass.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_bns_exit(GRASS_XPM_NOT_FOUND,
			YELLOW "grass.xpm not found" COLOR_RESET, game);
	fd = open("texture/character.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_bns_exit(PLAYER_XPM_NOT_FOUND,
			YELLOW "player.xpm not found" COLOR_RESET, game);
	fd = open("texture/player_left.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_bns_exit(PLAYERLEFT_XPM_NOT_FOUND,
			YELLOW "player_left.xpm not found" COLOR_RESET, game);
	fd = open("texture/bonus_img/enemy_left.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_bns_exit(EXITFULL_XPM_NOT_FOUND,
			YELLOW "enemy_left.xpm not found" COLOR_RESET, game);
	xpm_control2(game);
	return (1);
}

void	ft_get_path_xpm2(t_game *game, int x, int y)
{
	game->image->exit_full_img = mlx_xpm_file_to_image(game->mlx,
			"texture/exitfull.xpm", &x, &y);
	game->image->enemy_img = mlx_xpm_file_to_image(game->mlx,
			"texture/bonus_img/enemy.xpm", &x, &y);
	game->image->enemy_left_img = mlx_xpm_file_to_image(game->mlx,
			"texture/bonus_img/enemy_left.xpm", &x, &y);
}

void	ft_get_path_xpm(t_game *game)
{
	int	x;
	int	y;

	game->image = ft_calloc(1, sizeof(t_textures));
	if (!game->image)
		ft_bns_exit(_ALLOCATE_ERR,
			YELLOW "Failed to allocate memory space" COLOR_RESET, game);
	if (ft_xpm_control(game))
	{
		game->image->coll_img = mlx_xpm_file_to_image(game->mlx,
				"texture/bonus_img/collect1.xpm", &x, &y);
		game->image->exit_img = mlx_xpm_file_to_image(game->mlx,
				"texture/exit.xpm", &x, &y);
		game->image->ground_img = mlx_xpm_file_to_image(game->mlx,
				"texture/grass.xpm", &x, &y);
		game->image->player_img = mlx_xpm_file_to_image(game->mlx,
				"texture/character.xpm", &x, &y);
		game->image->player_left_img = mlx_xpm_file_to_image(game->mlx,
				"texture/player_left.xpm", &x, &y);
		game->image->wall_img = mlx_xpm_file_to_image(game->mlx,
				"texture/bonus_img/wall1.xpm", &x, &y);
		ft_get_path_xpm2(game, x, y);
	}
}
