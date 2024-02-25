#include "sl_header_bonus.h"

void rendering_background(void *mlx_ptr, void *mlx_win, int x, int y)
{
    t_data  img;
    char    *path;
    int     img_width;
    int     img_height;

    path = "../assets/m_Yellow.xpm";
    img.img = mlx_xpm_file_to_image(mlx_ptr, path, &img_width, &img_height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, x, y);
}

void rendering_ground(v_player *player, int x, int y)
{
    t_data  img;
    char    *path;
    int     img_width;
    int     img_height;

    path = "../assets/wall.xpm";
    img.img = mlx_xpm_file_to_image(player->mlx_ptr, path, &img_width, &img_height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, img.img, x, y);
}

void rendering_collectible(void *mlx_ptr, void *mlx_win, int x, int y)
{
    t_data  img;
    char    *path;
    int     img_width;
    int     img_height;

    path = "../assets/Coin_01.xpm";
    img.img = mlx_xpm_file_to_image(mlx_ptr, path, &img_width, &img_height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, x, y);
}

void rendering_exit(v_player *player, int x, int y)
{
    t_data  img;
    char    *path;
    int     img_width;
    int     img_height;

    path = "../assets/Decor_Ruins_02.xpm";
    img.img = mlx_xpm_file_to_image(player->mlx_ptr, path, &img_width, &img_height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, img.img, x, y);
}

void rendering_player(v_player *player, int x, int y)
{
    t_data  img;
    char    *path;
    int     img_width;
    int     img_height;

    path = "../assets/walk/Walk 1.xpm";
    img.img = mlx_xpm_file_to_image(player->mlx_ptr, path, &img_width, &img_height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, img.img, x, y);
}

void rendering_player_rev(v_player *player, int x, int y)
{
    t_data  img;
    char    *path;
    int     img_width;
    int     img_height;

    path = "../assets/Attack_1_rev.xpm";
    img.img = mlx_xpm_file_to_image(player->mlx_ptr, path, &img_width, &img_height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, img.img, x, y);
}

void rendering_collectibles(v_player *enemy, char **map, int width, int height)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            if (map[y][x] == 'C')
            {
                rendering_background(enemy->mlx_ptr, enemy->mlx_win, x * 50, y * 50);
                rendering_collectible(enemy->mlx_ptr, enemy->mlx_win, x * 50, y * 50);
            }
            x++;
        }
        y++;
    }
}
