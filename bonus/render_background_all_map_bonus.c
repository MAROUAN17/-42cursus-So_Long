#include "sl_header_bonus.h"

void render_map_image_all_map(v_player *player, int x, int y)
{
    while(y < player->map_height)
    {
        x = 0;
        while(x < player->map_width)
        {    
            rendering_background(player->mlx_ptr, player->mlx_win, x, y);
            x++;
        }
        y++;
    }
}