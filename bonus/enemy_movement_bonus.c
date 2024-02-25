#include "sl_header_bonus.h"

void rendering_enemy(v_player *player, int x, int y)
{
    t_data  img;
    char    *path;
    int     img_width;
    int     img_height;

    path = "../assets/enemy/enemy 1.xpm";
    img.img = mlx_xpm_file_to_image(player->mlx_ptr, path, &img_width, &img_height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, img.img, x, y);
}

void enemy_get_animation_images(v_player *enemy)
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
}

void enemy_animation(v_player *enemy, int x, int y)
{
    static int  j;

    rendering_background(enemy->mlx_ptr, enemy->mlx_win, enemy->enemy_x * 50, enemy->enemy_y * 50);
    if (enemy->keycode == 2)
        rendering_background(enemy->mlx_ptr, enemy->mlx_win, (enemy->enemy_x - 1) * 50, enemy->enemy_y * 50);
    else if (enemy->keycode == 0)
        rendering_background(enemy->mlx_ptr, enemy->mlx_win, (enemy->enemy_x + 1) * 50, enemy->enemy_y * 50);
    else if (enemy->keycode == 1)
        rendering_background(enemy->mlx_ptr, enemy->mlx_win, enemy->enemy_x * 50, (enemy->enemy_y + 1) * 50);
    else if (enemy->keycode == 13)
        rendering_background(enemy->mlx_ptr, enemy->mlx_win, enemy->enemy_x * 50, (enemy->enemy_y - 1) * 50);
    mlx_put_image_to_window(enemy->mlx_ptr, enemy->mlx_win, enemy->animations[j], x, y);
    j++;
    if (j == 8)
        j = 0;
}

void enemy_following_player(v_player *enemy)
{
    static int i = 25;
    static int is_right;
    static int is_left;
    static int is_up;
    static int is_down;

    enemy_get_animation_images(enemy);
    if (i == 25 && enemy->x < enemy->enemy_x && (enemy->map[enemy->enemy_y][enemy->enemy_x - 1]) != '1' && (enemy->map[enemy->enemy_y][enemy->enemy_x - 1]) != 'E')
    {
        enemy->enemy_x--;
        enemy->keycode = 0;
        is_left = 1;
    }
    else if (i == 25 && enemy->y < enemy->enemy_y && (enemy->map[enemy->enemy_y - 1][enemy->enemy_x]) != '1' && (enemy->map[enemy->enemy_y - 1][enemy->enemy_x]) != 'E')
    {
        enemy->enemy_y--;
        enemy->keycode = 1;
        is_up = 1;
    }
    else if (i == 25 && enemy->x > enemy->enemy_x && (enemy->map[enemy->enemy_y][enemy->enemy_x + 1]) != '1' && (enemy->map[enemy->enemy_y][enemy->enemy_x + 1]) != 'E')
    {
        enemy->enemy_x++;
        enemy->keycode = 2;
        is_right = 1;
    }
    else if (i == 25 && enemy->y > enemy->enemy_y && (enemy->map[enemy->enemy_y + 1][enemy->enemy_x]) != '1' && (enemy->map[enemy->enemy_y + 1][enemy->enemy_x]) != 'E')
    {
        enemy->enemy_y++;
        enemy->keycode = 13;
        is_down = 1;
    }
    if (is_left && (enemy->map[enemy->enemy_y][enemy->enemy_x - 1]) != '1' && (enemy->map[enemy->enemy_y][enemy->enemy_x - 1]) != 'E')
        enemy_animation(enemy, ((enemy->enemy_x * 50) + (i * 2)), enemy->enemy_y * 50);
    else if (is_right && (enemy->map[enemy->enemy_y][enemy->enemy_x + 1]) != '1' && (enemy->map[enemy->enemy_y][enemy->enemy_x + 1]) != 'E')
        enemy_animation(enemy, ((enemy->enemy_x * 50) - (i * 2)), enemy->enemy_y * 50);
    else if (is_up && (enemy->map[enemy->enemy_y - 1][enemy->enemy_x]) != '1' && (enemy->map[enemy->enemy_y - 1][enemy->enemy_x]) != 'E')
        enemy_animation(enemy, enemy->enemy_x * 50, ((enemy->enemy_y * 50) + (i * 2)));
    else if (is_down && (enemy->map[enemy->enemy_y + 1][enemy->enemy_x]) != '1' && (enemy->map[enemy->enemy_y + 1][enemy->enemy_x]) != 'E')
        enemy_animation(enemy, enemy->enemy_x * 50, ((enemy->enemy_y * 50) - (i * 2)));
    else
        enemy_animation(enemy, (enemy->enemy_x * 50), enemy->enemy_y * 50);
    i--;
    ft_printf("i -> %d\n", i);
    ft_printf("is_left -> %d\n", is_left);
    ft_printf("is_right -> %d\n", is_right);
    ft_printf("is_up -> %d\n", is_up);
    ft_printf("is_down -> %d\n", is_down);
    if (i < 0 || (!is_left && !is_right && !is_up && !is_down))
    {
        i = 25;
        is_down = 0;
        is_up = 0;
        is_right = 0;
        is_left = 0;
    }
    mlx_do_sync(enemy->mlx_ptr);
    if (enemy->enemy_x == enemy->x && enemy->enemy_y == enemy->y)
    {
        enemy_animation(enemy, enemy->enemy_x * 50, enemy->enemy_y * 50);
        ft_printf("You Lost !!\n");
        exit(0);
    }
}
