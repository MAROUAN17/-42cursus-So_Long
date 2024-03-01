#include "sl_header_bonus.h"

void    initialize_player_struct_variables(v_player *player)
{
    int i;

    i = 0;
    player->background_img = NULL;
    player->ground_img = NULL;
    player->collectible_img = NULL;
    player->exit_img = NULL;
    player->player_img = NULL;
    while (i < 8)
    {
        player->animations[i] = NULL;
        i++;
    }
    player->e_keycode = -1;
    player->enemy_x = 0;
    player->enemy_y = 0;
    player->map_width = 0;
    player->map_height = 0;
    player->c_collectibles = 0;
    player->moves = 0;
    player->x = 0;
    player->y = 0;
    player->keycode = -1;
    player->img_height = 50;
    player->img_width = 50;
}

void initialize_enemies(v_player *player)
{
    int         i;
    v_player    enemy;

    i = 0;
    enemy.enemy_x = 0;
    enemy.enemy_y = 0;
    player->c_enemies = count_enemies(player->map, player->map_width, player->map_height);
    player->enemies = malloc(sizeof(v_player) * player->c_enemies);
    while (i < player->c_enemies - 1)
    {
        enemy.keycode = -1;
        enemy.e_keycode = -1;
        enemy.mlx_ptr = player->mlx_ptr;
        enemy.mlx_win = player->mlx_win;
        enemy.map = player->map;
        enemy.map_height = player->map_height;
        enemy.map_width = player->map_width;
        enemy.x = player->x;
        enemy.y = player->y;
        find_enemy_position(player, &enemy.enemy_x, &enemy.enemy_y);
        player->enemies[i] = enemy;
        i++;
    }
}

void initialize_images(v_player *player)
{
    initialize_background(player);
    initialize_ground(player);
    initialize_collectible(player);
    initialize_exit(player);
    initialize_player(player);
    initialize_enemy(player);
    get_animation_images(player);
    enemy_get_animation_images(player);
}

void check_player_die(v_player *player)
{
    static int i;

    while (i < player->c_enemies - 1)
    {
        if (player->x == player->enemies[i].enemy_x 
            && player->y == player->enemies[i].enemy_y)
        {
            ft_close(player);
            exit(0);
        }
        i++;
    }
    if (i == player->c_enemies - 1)
        i = 0;
}
