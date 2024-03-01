#include "sl_header_bonus.h"

void rendering_collectibles(v_player *player)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < player->map_height)
    {
        x = 0;
        while (x < player->map_width)
        {
            if (player->map[y][x] == 'C')
            {
                mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->background_img, x * 50, y * 50);
                mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->collectible_img, x * 50, y * 50);
            }
            x++;
        }
        y++;
    }
}
