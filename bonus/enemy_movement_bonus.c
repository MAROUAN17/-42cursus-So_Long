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

int count_enemies(char **map, int width, int height)
{
    int     x;
    int     y;
    int     counter;

    x = 0;
    y = 0;
    counter = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            if (map[y][x] == 'M')
                counter++;
            x++;
        }
        y++;
    }
    return (counter);
}

void enemy_get_animation_images(v_player *player)
{
    int         img_width;
    int         img_height;

    player->animations[0] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/enemy/enemy 1.xpm", &img_width, &img_height);
    player->animations[1] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/enemy/enemy 2.xpm", &img_width, &img_height);
    player->animations[2] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/enemy/enemy 3.xpm", &img_width, &img_height);
    player->animations[3] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/enemy/enemy 4.xpm", &img_width, &img_height);
    player->animations[4] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/enemy/enemy 5.xpm", &img_width, &img_height);
    player->animations[5] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/enemy/enemy 6.xpm", &img_width, &img_height);
    player->animations[6] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/enemy/enemy 7.xpm", &img_width, &img_height);
    player->animations[7] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/enemy/enemy 8.xpm", &img_width, &img_height);
}

void enemy_animation(v_player *player, int x, int y)
{
    static int  j;

    rendering_background(player->mlx_ptr, player->mlx_win, player->enemy_x * 50, player->enemy_y * 50);
    if (player->e_keycode == 2)
        rendering_background(player->mlx_ptr, player->mlx_win, (player->enemy_x - 1) * 50, player->enemy_y * 50);
    else if (player->e_keycode == 0)
        rendering_background(player->mlx_ptr, player->mlx_win, (player->enemy_x + 1) * 50, player->enemy_y * 50);
    else if (player->e_keycode == 1)
        rendering_background(player->mlx_ptr, player->mlx_win, player->enemy_x * 50, (player->enemy_y + 1) * 50);
    else if (player->e_keycode == 13)
        rendering_background(player->mlx_ptr, player->mlx_win, player->enemy_x * 50, (player->enemy_y - 1) * 50);
    mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->animations[j], x, y);
    j++;
    if (j == 8)
        j = 0;
}

void enemy_following_player(v_player *player)
{
    static int counter = 25;
    static int i;
    static int is_right;
    static int is_left;
    static int is_up;
    static int is_down;

    enemy_get_animation_images(player);
    if (counter == 25 && player->x < player->enemy_x && player->map[player->enemy_y][player->enemy_x - 1] != '1' && player->map[player->enemy_y][player->enemy_x - 1] != 'E')
    {
        player->enemy_x--;
        player->e_keycode = 0;
        is_left = 1;
    }
    else if (counter == 25 && player->x > player->enemy_x && player->map[player->enemy_y][player->enemy_x + 1] != '1' && player->map[player->enemy_y][player->enemy_x + 1] != 'E')
    {
        player->enemy_x++;
        player->e_keycode = 2;
        is_right = 1;
    }
    else if (counter == 25 && player->y < player->enemy_y && player->map[player->enemy_y - 1][player->enemy_x] != '1' && player->map[player->enemy_y - 1][player->enemy_x] != 'E')
    {
        player->enemy_y--;
        player->e_keycode = 1;
        is_up = 1;
    }
    else if (counter == 25 && player->y > player->enemy_y && player->map[player->enemy_y + 1][player->enemy_x] != '1' && player->map[player->enemy_y + 1][player->enemy_x] != 'E')
    {
        player->enemy_y++;
        player->e_keycode = 13;
        is_down = 1;
    }
    ft_printf("counter -> %d\n", counter);
    ft_printf("enemy y -> %d\n", player->enemy_y);
    ft_printf("enemy x -> %d\n", player->enemy_x);
    ft_printf("enemy y block -> %c\n", player->map[player->enemy_y + 1][player->enemy_x]);
    ft_printf("is_right -> %d\n", is_right);
    ft_printf("is_left -> %d\n", is_left);
    ft_printf("is_down -> %d\n", is_down);
    ft_printf("is_up -> %d\n", is_up);
    if (counter != 25)
    {
        if (is_left && (player->map[player->enemy_y][player->enemy_x - 1]) != '1' && (player->map[player->enemy_y][player->enemy_x - 1]) != 'E')
            enemy_animation(player, ((player->enemy_x * 50) + (counter * 2)), player->enemy_y * 50);
        else if (is_right && (player->map[player->enemy_y][player->enemy_x + 1]) != '1' && (player->map[player->enemy_y][player->enemy_x + 1]) != 'E')
            enemy_animation(player, ((player->enemy_x * 50) - (counter * 2)), player->enemy_y * 50);
        else if (is_up && (player->map[player->enemy_y - 1][player->enemy_x]) != '1' && (player->map[player->enemy_y - 1][player->enemy_x]) != 'E')
            enemy_animation(player, player->enemy_x * 50, ((player->enemy_y * 50) + (counter * 2)));
        else if (is_down && (player->map[player->enemy_y + 1][player->enemy_x]) != '1' && (player->map[player->enemy_y + 1][player->enemy_x]) != 'E')
            enemy_animation(player, player->enemy_x * 50, ((player->enemy_y * 50) - (counter * 2)));
        else
            enemy_animation(player, player->enemy_x * 50, player->enemy_y * 50);
    }
    counter--;
    if (counter < 0 || (!is_left && !is_right && !is_up && !is_down))
    {
        counter = 25;
        i++;
        is_down = 0;
        is_up = 0;
        is_right = 0;
        is_left = 0;
    }
    if (i == player->c_enemies - 1)
        i = 0;
    mlx_do_sync(player->mlx_ptr);
    if (player->x == player->enemy_x && player->enemy_y == player->y)
    {
        enemy_animation(player, player->enemy_x * 50, player->enemy_y * 50);
        ft_printf("You Lost !!\n");
        exit(0);
    }
}
