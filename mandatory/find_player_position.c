#include "sl_header.h"

void find_player_position(v_player *player, int *p_x, int *p_y)
{
    while (*p_y < player->map_height)
    {
        *p_x = 0;
        while (*p_x < player->map_width)
        {
            if (player->map[*p_y][*p_x] == 'P')
                return;
            (*p_x)++;
        }
        (*p_y)++;
    }
}
