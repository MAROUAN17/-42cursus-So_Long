#include "sl_header.h"

void rendering_background(void *mlx_ptr, void *mlx_win, int x, int y)
{
    t_data  img;
    char    *path;
    int     img_width;
    int     img_height;

    path = "./assets/m_Yellow.xpm";
    img.img = mlx_xpm_file_to_image(mlx_ptr, path, &img_width, &img_height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, x, y);
}

void rendering_ground(void *mlx_ptr, void *mlx_win, int x, int y)
{
    t_data  img;
    char    *path;
    int     img_width;
    int     img_height;

    path = "./assets/wall.xpm";
    img.img = mlx_xpm_file_to_image(mlx_ptr, path, &img_width, &img_height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, x, y);
}

void rendering_collectible(void *mlx_ptr, void *mlx_win, int x, int y)
{
    t_data  img;
    char    *path;
    int     img_width;
    int     img_height;

    path = "./assets/Coin_01.xpm";
    img.img = mlx_xpm_file_to_image(mlx_ptr, path, &img_width, &img_height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, x, y);
}

void rendering_exit(void *mlx_ptr, void *mlx_win, int x, int y)
{
    t_data  img;
    char    *path;
    int     img_width;
    int     img_height;

    path = "./assets/Decor_Ruins_02.xpm";
    img.img = mlx_xpm_file_to_image(mlx_ptr, path, &img_width, &img_height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, x, y);
}

void rendering_player(void *mlx_ptr, void *mlx_win, int x, int y)
{
    t_data  img;
    char    *path;
    int     img_width;
    int     img_height;

    path = "./assets/walk/Walk 1.xpm";
    img.img = mlx_xpm_file_to_image(mlx_ptr, path, &img_width, &img_height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, x, y);
}

void rendering_player_rev(void *mlx_ptr, void *mlx_win, int x, int y)
{
    t_data  img;
    char    *path;
    int     img_width;
    int     img_height;

    path = "./assets/Attack_1_rev.xpm";
    img.img = mlx_xpm_file_to_image(mlx_ptr, path, &img_width, &img_height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, x, y);
}
