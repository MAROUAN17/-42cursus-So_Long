#include "sl_header_bonus.h"

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

void finding_main_enemy_position()
{
}

void find_enemy_position(v_player *player, int *p_x, int *p_y)
{
    static int last_x;
    static int last_y;

    *p_x = last_x;
    *p_y = last_y;
    while (*p_y < player->map_height)
    {
        if (*p_x == player->map_width)
            *p_x = 0;
        while (*p_x < player->map_width)
        {
            if (player->map[*p_y][*p_x] == 'M')
            {
                if (*p_x != last_x || *p_y != last_y)
                {
                    last_x = *p_x;
                    last_y = *p_y;
                    return;
                }
            }
            (*p_x)++;
        }
        (*p_y)++;
    }
}
