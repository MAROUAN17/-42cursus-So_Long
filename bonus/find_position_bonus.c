#include "sl_header_bonus.h"

void find_player_position(char **map, int width, int height, int *p_x, int *p_y)
{
    while(*p_y < height)
    {
        *p_x = 0;
        while(*p_x < width)
        {
            if(map[*p_y][*p_x] == 'P')
                return;
            (*p_x)++;
        }
        (*p_y)++;
    }
}

void find_enemy_position(char **map, int width, int height, int *p_x, int *p_y)
{
    while(*p_y < height)
    {
        *p_x = 0;
        while(*p_x < width)
        {
            if(map[*p_y][*p_x] == 'M')
                return;
            (*p_x)++;
        }
        (*p_y)++;
    }
}