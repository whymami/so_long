/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_and_wndw_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:01:16 by muguveli          #+#    #+#             */
/*   Updated: 2024/03/26 14:34:37 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	if (game->pos->e_direction != _DIR_LEFT && game->counters->x_counter == 1)
		mlx_put_image_to_window(game->mlx, game->window, game->image->enemy_img,
			game->pos->enemy_x, game->pos->enemy_y);
	else if (game->pos->e_direction != _DIR_RIGHT
		&& game->counters->x_counter == 1)
		mlx_put_image_to_window(game->mlx, game->window,
			game->image->enemy_left_img, game->pos->enemy_x,
			game->pos->enemy_y);
}

static int	ft_put_image(t_game *game)
{
	int	x;
	int	y;

	mlx_clear_window(game->mlx, game->window);
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
					game->image->wall_img, x * 64, y * 64);
			if (game->map->game_map[y][x] == _COLLECTIBLE)
				mlx_put_image_to_window(game->mlx, game->window,
					game->image->coll_img, x * 64, y * 64);
		}
		ft_direction(game);
	}
	ft_score(game);
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
	mlx_loop_hook(game->mlx, ft_put_image, game);
	mlx_key_hook(game->window, ft_get_keycode, game);
	mlx_hook(game->window, 17, 0, ft_mouse_exit, game);
	mlx_loop(game->mlx);
}
