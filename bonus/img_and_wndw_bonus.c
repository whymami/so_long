/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_and_wndw_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:49:38 by beyarsla          #+#    #+#             */
/*   Updated: 2024/03/21 17:25:37 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// int put_enemy(t_game *game, int y, int x)
// {
// 	if (game->pos->e_direction == 1)
// 		mlx_put_image_to_window(game->mlx, game->window, game->image->enemy_left_img, x, y);
// 	else
// 		mlx_put_image_to_window(game->mlx, game->window, game->image->enemy_img, x, y);
// 	return (0);
// }

static void enemy_cords(t_game *game)
{
	int x;
	int y;

	y = -1;
	while (++y < game->map->map_y)
	{
		x = -1;
		while (++x < game->map->map_x)
		{
			if (game->map->game_map[y][x] == _ENEMY)
			{
				game->pos->enemy_x = x * 64;
				game->pos->enemy_y = y * 64;
			}
		}
	}
}
#include <stdio.h>
int	flood_fill_enemy(t_game *game, int y, int x)
{
	printf("heyx: %d, y: %d\n", x, y);
	if (x < 0 || x > game->map->map_x || y < 0 || y > game->map->map_y)
		return 0;
	if (game->map->game_map[y][x] != _WALL && game->map->game_map[y][x] != _EXIT && game->map->game_map[y][x] != _COLLECTIBLE)
	{	
		printf("hey2: %d, y: %d\n", x, y);

		game->map->game_map[y][x] = 'X';	
		return 1;
	}
	return 0;
}

int whereisenemy(t_game *game)
{
	enemy_cords(game);
	static int i = 0;
	i++;
	
	if (!(i % 20) && flood_fill_enemy(game, game->pos->enemy_y / 64, game->pos->enemy_x / 64 - 1))
		game->map->game_map[game->pos->enemy_y / 64][game->pos->enemy_x / 64] = '0';
	else if (!(i % 80) &&flood_fill_enemy(game, game->pos->enemy_y / 64 - 1, game->pos->enemy_x / 64))
		game->map->game_map[game->pos->enemy_y / 64][game->pos->enemy_x / 64] = '0';
	else if (!(i % 60) && flood_fill_enemy(game, game->pos->enemy_y / 64, game->pos->enemy_x / 64 + 1))
		game->map->game_map[game->pos->enemy_y / 64][game->pos->enemy_x / 64] = '0';
	else if (!(i % 40) && flood_fill_enemy(game, game->pos->enemy_y / 64 + 1, game->pos->enemy_x / 64))
		game->map->game_map[game->pos->enemy_y / 64][game->pos->enemy_x / 64] = '0';
	return 0;
}

static void	ft_direction(t_game *game)
{
	if (game->pos->direction == 1)
		mlx_put_image_to_window(game->mlx, game->window,
			game->image->player_left_img, game->pos->player_x,
			game->pos->player_y);
	else
		mlx_put_image_to_window(game->mlx, game->window,
			game->image->player_img, game->pos->player_x, game->pos->player_y);
	if (game->counters->c_counter > 0)
		mlx_put_image_to_window(game->mlx, game->window, game->image->exit_img,
			game->pos->exit_x, game->pos->exit_y);
	else
		mlx_put_image_to_window(game->mlx, game->window,
			game->image->exit_full_img, game->pos->exit_x, game->pos->exit_y);
}

static int	ft_put_image(t_game *game)
{
	int	x;
	int	y;
	whereisenemy(game);
	y = -1;
	while (++y < game->map->map_y)
	{
		x = -1;
		while (++x < game->map->map_x)
		{
			mlx_put_image_to_window(game->mlx, game->window,
				game->image->ground_img, x * 64, y * 64);
			if (game->map->game_map[y][x] == _WALL)
				mlx_put_image_to_window(game->mlx, game->window,
					game->image->wall1_img, x * 64, y * 64);
			if (game->map->game_map[y][x] == _COLLECTIBLE)
				mlx_put_image_to_window(game->mlx, game->window,
					game->image->coll1_img, x * 64, y * 64);
			if (game->map->game_map[y][x] == _ENEMY)
				mlx_put_image_to_window(game->mlx, game->window,
					game->image->enemy_img, x * 64, y * 64);
		}
		ft_direction(game);
		// move_enemy(game);
	}
	return (0);
}




void	ft_create_window(t_game *game)
{
	game->mlx = mlx_init();
	ft_get_cords(game);
	copy_map(game);
	game->window = mlx_new_window(game->mlx, game->map->map_x * 64,
			game->map->map_y * 64, "SO_LONG");
	ft_get_path_xpm(game);
	mlx_clear_window(game->mlx, game->window);
	mlx_loop_hook(game->mlx, ft_put_image, game);
	mlx_key_hook(game->window, ft_get_keycode, game);
	mlx_hook(game->window, 17, 0, ft_mouse_exit, game);
	mlx_loop(game->mlx);
}