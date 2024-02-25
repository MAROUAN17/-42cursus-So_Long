#include "sl_header_bonus.h"

void display_moves(v_player *player)
{
    char    *moves;

    moves = ft_itoa(player->moves);
    rendering_ground(player, 0, 0);
    mlx_string_put(player->mlx_ptr, player->mlx_win, 0, 0, 0xFFFFFF, moves);
}