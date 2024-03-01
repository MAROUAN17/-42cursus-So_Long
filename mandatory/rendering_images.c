#include "sl_header.h"

void initialize_background(v_player *player)
{
    char    *path;

    path = "../assets/m_Yellow.xpm";
    player->background = mlx_xpm_file_to_image(player->mlx_ptr, path, &player->img_width, &player->img_height);
}

void initialize_ground(v_player *player)
{
    char    *path;

    path = "../assets/wall.xpm";
    player->ground = mlx_xpm_file_to_image(player->mlx_ptr, path, &player->img_width, &player->img_height);
}

void initialize_collectible(v_player *player)
{
    char    *path;

    path = "../assets/Coin_01.xpm";
    player->collectible = mlx_xpm_file_to_image(player->mlx_ptr, path, &player->img_width, &player->img_height);
}

void initialize_exit(v_player *player)
{
    char    *path;

    path = "../assets/Decor_Ruins_02.xpm";
    player->exit = mlx_xpm_file_to_image(player->mlx_ptr, path, &player->img_width, &player->img_height);
}

void initialize_player(v_player *player)
{
    char    *path;

    path = "../assets/walk/Walk 1.xpm";
    player->player = mlx_xpm_file_to_image(player->mlx_ptr, path, &player->img_width, &player->img_height);
}
