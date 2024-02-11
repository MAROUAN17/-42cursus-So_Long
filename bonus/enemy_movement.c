#include "sl_header_bonus.h"

void rendering_enemy(void *mlx_ptr, void *mlx_win, int x, int y)
{
    t_data  img;
    char    *path;
    int     img_width;
    int     img_height;

    path = "../assets/enemy/enemy 1.xpm";
    img.img = mlx_xpm_file_to_image(mlx_ptr, path, &img_width, &img_height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, x, y);
}

void enemy_get_animation_images(v_enemy *enemy)
{
    int         img_width;
    int         img_height;

    enemy->animations[0] = mlx_xpm_file_to_image(enemy->mlx_ptr, "../assets/enemy/enemy 1.xpm", &img_width, &img_height);
    enemy->animations[1] = mlx_xpm_file_to_image(enemy->mlx_ptr, "../assets/enemy/enemy 2.xpm", &img_width, &img_height);
    enemy->animations[2] = mlx_xpm_file_to_image(enemy->mlx_ptr, "../assets/enemy/enemy 3.xpm", &img_width, &img_height);
    enemy->animations[3] = mlx_xpm_file_to_image(enemy->mlx_ptr, "../assets/enemy/enemy 4.xpm", &img_width, &img_height);
    enemy->animations[4] = mlx_xpm_file_to_image(enemy->mlx_ptr, "../assets/enemy/enemy 5.xpm", &img_width, &img_height);
    enemy->animations[5] = mlx_xpm_file_to_image(enemy->mlx_ptr, "../assets/enemy/enemy 6.xpm", &img_width, &img_height);
    enemy->animations[6] = mlx_xpm_file_to_image(enemy->mlx_ptr, "../assets/enemy/enemy 7.xpm", &img_width, &img_height);
    enemy->animations[7] = mlx_xpm_file_to_image(enemy->mlx_ptr, "../assets/enemy/enemy 8.xpm", &img_width, &img_height);
    enemy_animation(enemy);
}

void enemy_animation(v_enemy *enemy)
{
    static int  j;
    int  i;

    i = 0;
    if (j < 8)
    {
        rendering_background(enemy->mlx_ptr, enemy->mlx_win, enemy->x * 50 , enemy->y * 50);
        mlx_put_image_to_window(enemy->mlx_ptr, enemy->mlx_win, enemy->animations[j], enemy->x * 50, enemy->y * 50);
        j++;
        while (i < 50000000)
            i++;
        i = 0;
    }
    if (j == 8)
        j = 0;
}

void enemy_following_player(v_enemy *enemy)
{
    int i;

    i = 0;
    while (i < 50000000)
        i++;
    if (enemy->x != enemy->player_x && enemy->x + 1 != '1' && enemy->x + 1 != 'E')
    {    
        enemy->x++;
        rendering_background(enemy->mlx_ptr, enemy->mlx_win, (enemy->x - 1) * 50, enemy->y * 50);
        rendering_enemy(enemy->mlx_ptr, enemy->mlx_win, enemy->x * 50, enemy->y * 50);
    }
    if (enemy->y != enemy->player_y && enemy->y + 1 != '1' && enemy->y + 1 != 'E')
    {    
        enemy->y++;
        rendering_background(enemy->mlx_ptr, enemy->mlx_win, enemy->x * 50, (enemy->y - 1) * 50);
        rendering_enemy(enemy->mlx_ptr, enemy->mlx_win, enemy->x * 50, enemy->y * 50);
    }
    if (enemy->x != enemy->player_x && (enemy->x - 1) != '1' && (enemy->x - 1) != 'E')
    {    
        enemy->x--;
        rendering_background(enemy->mlx_ptr, enemy->mlx_win, (enemy->x + 1) * 50, enemy->y * 50);
        rendering_enemy(enemy->mlx_ptr, enemy->mlx_win, enemy->x * 50, enemy->y * 50);
    }
    if (enemy->y != enemy->player_y && (enemy->y - 1) != '1' && (enemy->y - 1) != 'E')
    {    
        enemy->y--;
        rendering_background(enemy->mlx_ptr, enemy->mlx_win, enemy->x * 50, (enemy->y + 1) * 50);
        rendering_enemy(enemy->mlx_ptr, enemy->mlx_win, enemy->x * 50, enemy->y * 50);
    }
    if (enemy->x == enemy->player_x && enemy->y == enemy->player_y)
    {
        ft_printf("You Lost !!\n");
        exit(0);
    }
}
