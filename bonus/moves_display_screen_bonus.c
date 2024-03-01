#include "sl_header_bonus.h"

void display_moves(v_player *player)
{
    char    *moves;

    moves = ft_itoa(player->moves);
    if (!moves)
    {
        ft_close(player);
        exit(1);
    }
    mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->ground_img, 0, 0);
    mlx_string_put(player->mlx_ptr, player->mlx_win, 0, 0, 0xFFFFFF, moves);
    free(moves);
}