/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_and_wndw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:15:12 by muguveli          #+#    #+#             */
/*   Updated: 2024/03/18 17:41:24 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void  delay(unsigned int microseconds) {
    unsigned int now = 0;
    unsigned int then = 0;
    while (now - then < microseconds) {
        now++;
    }
}

void ft_put_player(t_game *game)
{

    // Eğer animasyon çalışıyorsa
    if (game->pos->animating)
    {
        // Frame'leri tutan dizi
        void *frames[7] = {
            game->image->player_right_walk1,
            game->image->player_right_walk2,
            game->image->player_right_walk3,
            game->image->player_right_walk4,
            game->image->player_right_walk5,
            game->image->player_right_walk6,
            game->image->player_right_walk7
        };

        // Şu anki frame'in indeksi
        int current_frame_index = (game->image->curr_p_img - 1) % 7;

        // Oyuncuyu ekleyelim
        mlx_put_image_to_window(game->mlx, game->window, frames[current_frame_index], game->pos->player_x, game->pos->player_y);
        delay(FRAME_DELAY);

        // Sonraki frame'e geçelim
        game->image->curr_p_img = (game->image->curr_p_img % 7) + 1;
		// game->pos->animating = 0;
		if(frames[current_frame_index] == game->image->player_right_walk7 )
		{
			
			game->pos->animating = 0;
		}
    }
    else
    {
		 mlx_put_image_to_window(game->mlx, game->window, game->image->player_right_walk7, game->pos->player_x, game->pos->player_y);
    }
}



void    ft_direction(t_game *game)
{
    int i;

    i = -1;
    if (game->pos->direction == 1)
    {
        ft_put_player(game); // Animasyonu çalıştır

    }
    else
    {
        mlx_put_image_to_window(game->mlx, game->window,
            game->image->player_right_walk1, game->pos->player_x, game->pos->player_y);
    }
    if (game->counters->c_counter > 0)
        mlx_put_image_to_window(game->mlx, game->window, game->image->exit_img,
            game->pos->exit_x, game->pos->exit_y);
    else
        mlx_put_image_to_window(game->mlx, game->window,
            game->image->exit_full_img, game->pos->exit_x, game->pos->exit_y);
}

static int    ft_put_image(t_game *game)
{
    int x;
    int y;
	mlx_clear_window(game->mlx, game->window);
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
    return (0);
}

void    ft_create_window(t_game *game)
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
