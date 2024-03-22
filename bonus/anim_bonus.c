/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:14:47 by muguveli          #+#    #+#             */
/*   Updated: 2024/03/22 17:02:55 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void collect_anim(t_game *game, int y, int x, int index)
{
    static int i[7] = {0}; // collectible caunt tutulacak

    i[index]++;
	while(i[index])
	{
		if (i[index] % 100 == 0)
    		mlx_put_image_to_window(game->mlx, game->window, game->image->coll1_img, x * 64, y * 64);
    	if (i[index] % 150 == 0 && ft_printf("bunu basyım\n"))
        	mlx_put_image_to_window(game->mlx, game->window, game->image->coll2_img, x * 64, y * 64);
    	else if (i[index] % 200 == 0)
        	mlx_put_image_to_window(game->mlx, game->window, game->image->coll3_img, x * 64, y * 64);
    	else if (i[index] % 250 == 0)
        	mlx_put_image_to_window(game->mlx, game->window, game->image->coll2_img, x * 64, y * 64);
    	else if (i[index] % 300 == 0)
        	mlx_put_image_to_window(game->mlx, game->window, game->image->coll1_img, x * 64, y * 64);
		id
	}
}
