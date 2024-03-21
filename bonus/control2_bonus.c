/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:06:43 by beyarsla          #+#    #+#             */
/*   Updated: 2024/03/21 14:49:46 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_window_size(t_game *game)
{
	if (game->map->map_x > 20 || game->map->map_y > 10)
		ft_bns_exit(WINDOW_SIZE_ERROR, "Window size is too big", game);
}

static void anim_xpm_control(t_game *game)
{
	int fd;
	fd = open("texture/bonus_img/wall1.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_bns_exit(WALL_XPM_NOT_FOUND, "wall1.xpm not found", game);
	fd = open("texture/bonus_img/wall2.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_bns_exit(WALL_XPM_NOT_FOUND, "wall2.xpm not found", game);
	fd = open("texture/bonus_img/wall3.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_bns_exit(WALL_XPM_NOT_FOUND, "wall3.xpm not found", game);
	fd = open("texture/bonus_img/collect1.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_bns_exit(COLL_XPM_NOT_FOUND, "collect1.xpm not found", game);
	fd = open("texture/bonus_img/collect2.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_bns_exit(COLL_XPM_NOT_FOUND, "collect2.xpm not found", game);
	fd = open("texture/bonus_img/collect3.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_bns_exit(COLL_XPM_NOT_FOUND, "collect3.xpm not found", game);
}

static int	ft_xpm_control(t_game *game)
{
	int	fd;

	fd = open("texture/exit.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_bns_exit(EXIT_XPM_NOT_FOUND, "exit.xpm not found", game);
	fd = open("texture/grass.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_bns_exit(GRASS_XPM_NOT_FOUND, "grass.xpm not found", game);
	fd = open("texture/character.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_bns_exit(PLAYER_XPM_NOT_FOUND, "player.xpm not found", game);
	fd = open("texture/player_left.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_bns_exit(PLAYERLEFT_XPM_NOT_FOUND, "player_left.xpm not found", game);
	fd = open("texture/exitfull.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_bns_exit(EXITFULL_XPM_NOT_FOUND, "exitfull.xpm not found", game);
	fd = open("texture/bonus_img/enemy.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_bns_exit(EXITFULL_XPM_NOT_FOUND, "enemy.xpm not found", game);
	fd = open("texture/bonus_img/enemy_left.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_bns_exit(EXITFULL_XPM_NOT_FOUND, "enemy_left.xpm not found", game);
	anim_xpm_control(game);
	return (1);
}

void	ft_get_path_xpm(t_game *game)
{
	int	x;
	int	y;

	game->image = ft_calloc(1, sizeof(t_textures));
	if (ft_xpm_control(game))
	{
		game->image->coll1_img = mlx_xpm_file_to_image(game->mlx,
				"texture/bonus_img/collect1.xpm", &x, &y);
		game->image->exit_img = mlx_xpm_file_to_image(game->mlx,
				"texture/exit.xpm", &x, &y);
		game->image->ground_img = mlx_xpm_file_to_image(game->mlx,
				"texture/grass.xpm", &x, &y);
		game->image->player_img = mlx_xpm_file_to_image(game->mlx,
				"texture/character.xpm", &x, &y);
		game->image->player_left_img = mlx_xpm_file_to_image(game->mlx,
				"texture/player_left.xpm", &x, &y);
		game->image->wall1_img = mlx_xpm_file_to_image(game->mlx,
				"texture/bonus_img/wall1.xpm", &x, &y);
		game->image->exit_full_img = mlx_xpm_file_to_image(game->mlx,
				"texture/exitfull.xpm", &x, &y);
		game->image->enemy_img = mlx_xpm_file_to_image(game->mlx,
				"texture/bonus_img/enemy.xpm", &x, &y);
		game->image->enemy_left_img = mlx_xpm_file_to_image(game->mlx,
				"texture/bonus_img/enemy_left.xpm", &x, &y);
	}
}