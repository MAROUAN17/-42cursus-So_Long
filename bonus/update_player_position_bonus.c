#include "sl_header_bonus.h"

void update_player_position_and_render(v_player *player)
{
    if (player->keycode == 2 
        && player->map[player->y][player->x - 1] != '1' 
        && player->map[player->y][player->x - 1] != 'C')
        mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->background_img, (player->x - 1) * 50, player->y * 50);
    else if (player->keycode == 0 
        && player->map[player->y][player->x + 1] != '1' 
        && player->map[player->y][player->x + 1] != 'C')
        mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->background_img, (player->x + 1) * 50, player->y * 50);
    else if (player->keycode == 13 
        && player->map[player->y - 1][player->x] != '1' 
        && player->map[player->y - 1][player->x] != 'C')
        mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->background_img, player->x * 50, (player->y - 1) * 50);
    else if (player->keycode == 1
        && player->map[player->y + 1][player->x] != '1'
        && player->map[player->y + 1][player->x] != 'C')
        mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->background_img, player->x * 50, (player->y + 1) * 50);
    mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->player_img, player->x * 50, player->y * 50);
}

void put_img_to_window(v_player *player, void *img, int x, int y)
{
    mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, img, x * 50, y * 50);
}
