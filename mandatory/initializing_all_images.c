#include "sl_header.h"

void initialising_images(v_player *player)
{
    initialize_background(player);
    initialize_ground(player);
    initialize_collectible(player);
    initialize_exit(player);
    initialize_player(player);
    get_animation_images(player);
}