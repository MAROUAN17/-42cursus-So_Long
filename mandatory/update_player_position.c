#include "sl_header.h"

void update_player_position_and_render(v_player *player)
{
    if (player->keycode == 2 
        && player->map[player->y][player->x - 1] != '1' 
        && player->map[player->y][player->x - 1] != 'C')
        mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->background, (player->x - 1) * player->img_width, player->y * player->img_height);
    else if (player->keycode == 0 
        && player->map[player->y][player->x + 1] != '1' 
        && player->map[player->y][player->x + 1] != 'C')
        mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->background, (player->x + 1) * player->img_width, player->y * player->img_height);
    else if (player->keycode == 1 
        && player->map[player->y - 1][player->x] != '1' 
        && player->map[player->y - 1][player->x] != 'C')
        mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->background, player->x * player->img_width, (player->y - 1) * player->img_height);
    else if (player->keycode == 13
        && player->map[player->y + 1][player->x] != '1'
        && player->map[player->y + 1][player->x] != 'C')
        mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->background, player->x * player->img_width, (player->y + 1) * player->img_height);
    mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->player, player->x * player->img_width, player->y * player->img_height);
}
