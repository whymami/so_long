/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:23:27 by muguveli          #+#    #+#             */
/*   Updated: 2024/03/21 16:36:41 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void remove_enemies_from_map(t_game *game) {
    int h, w;
    for (h = 0; h < game->map->map_y; h++) {
        for (w = 0; w < game->map->map_x; w++) {
            if (game->map->game_map[h][w] == _ENEMY)
                game->map->game_map[h][w] = _GROUND;
        }
    }
}

static void put_enemies_to_map(t_game *game) {
    t_enemy *enemy = game->enemies;
    while (enemy) {
        game->map->game_map[enemy->y][enemy->x] = _ENEMY;
        enemy = enemy->next;
    }
}

static void move_enemy(t_game *game, t_enemy *enemy, int x, int y) {
    if (game->map->game_map[y][x] != _WALL &&
        game->map->game_map[y][x] != _COLLECTIBLE &&
        game->map->game_map[y][x] != _EXIT &&
        game->map->game_map[y][x] != _ENEMY) {
        enemy->x = x;
        enemy->y = y;
    }
}

static void move_enemies(t_game *game) {
    t_enemy *enemy = game->enemies;
    while (enemy) {
        int new_x = enemy->x;
        int new_y = enemy->y;
        // Hareket yönlerine göre yeni konumu hesaplayın
        if (enemy->e_direction == DIR_RIGHT) {
            new_x += 1;
        } else if (enemy->e_direction == DIR_LEFT) {
            new_x -= 1;
        } else if (enemy->e_direction == DIR_DOWN) {
            new_y += 1;
        } else if (enemy->e_direction == DIR_UP) {
            new_y -= 1;
        }
        move_enemy(game, enemy, new_x, new_y);
        enemy = enemy->next;
    }
}

void update_enemy_direction(t_enemy *enemy) {
    // Düşmanın hareket yönünü değiştirin (örneğin saat yönünün tersine)
    if (enemy->e_direction == DIR_RIGHT)
        enemy->e_direction = DIR_DOWN;
    else if (enemy->e_direction == DIR_DOWN)
        enemy->e_direction = DIR_LEFT;
    else if (enemy->e_direction == DIR_LEFT)
        enemy->e_direction = DIR_UP;
    else if (enemy->e_direction == DIR_UP)
        enemy->e_direction = DIR_RIGHT;
}

void move_enemies(t_game *game) {
    t_enemy *enemy = game->enemies;
    while (enemy) {
        if (change_dir == 0) {
            move_enemy(game, enemy, enemy->x + 1, enemy->y);
        } else {
            update_enemy_direction(enemy);
        }
        enemy = enemy->next;
    }
}
