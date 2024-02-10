#include "sl_header.h"

void update_player_position_and_render(v_player *player)
{
    if (player->keycode == 2 
        && player->map[player->y][player->x - 1] != '1' 
        && player->map[player->y][player->x - 1] != 'C')
        rendering_background(player->mlx_ptr, player->mlx_win, (player->x - 1) * 50, player->y * 50);
    else if (player->keycode == 0 
        && player->map[player->y][player->x + 1] != '1' 
        && player->map[player->y][player->x + 1] != 'C')
        rendering_background(player->mlx_ptr, player->mlx_win, (player->x + 1) * 50, player->y * 50);
    else if (player->keycode == 1 
        && player->map[player->y - 1][player->x] != '1' 
        && player->map[player->y - 1][player->x] != 'C')
        rendering_background(player->mlx_ptr, player->mlx_win, player->x * 50, (player->y - 1) * 50);
    else if (player->keycode == 13
        && player->map[player->y + 1][player->x] != '1'
        && player->map[player->y + 1][player->x] != 'C')
        rendering_background(player->mlx_ptr, player->mlx_win, player->x * 50, (player->y + 1) * 50);
    rendering_player(player->mlx_ptr, player->mlx_win, player->x * 50, player->y * 50);
}
