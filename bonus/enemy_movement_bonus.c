#include "sl_header_bonus.h"

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
    player->e_animations[0] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/enemy/enemy 1.xpm", &player->img_width, &player->img_height);
    player->e_animations[1] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/enemy/enemy 2.xpm", &player->img_width, &player->img_height);
    player->e_animations[2] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/enemy/enemy 3.xpm", &player->img_width, &player->img_height);
    player->e_animations[3] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/enemy/enemy 4.xpm", &player->img_width, &player->img_height);
    player->e_animations[4] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/enemy/enemy 5.xpm", &player->img_width, &player->img_height);
    player->e_animations[5] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/enemy/enemy 6.xpm", &player->img_width, &player->img_height);
    player->e_animations[6] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/enemy/enemy 7.xpm", &player->img_width, &player->img_height);
    player->e_animations[7] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/enemy/enemy 8.xpm", &player->img_width, &player->img_height);
}

void enemy_animation(v_player *player, int x, int y)
{
    static int  j;

    mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->background_img, player->enemy_x * 50, player->enemy_y * 50);
    if (player->e_keycode == 2)
        mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->background_img, (player->enemy_x - 1) * 50, player->enemy_y * 50);
    else if (player->e_keycode == 0)
        mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->background_img, (player->enemy_x + 1) * 50, player->enemy_y * 50);
    else if (player->e_keycode == 1)
        mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->background_img, player->enemy_x * 50, (player->enemy_y + 1) * 50);
    else if (player->e_keycode == 13)
        mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->background_img, player->enemy_x * 50, (player->enemy_y - 1) * 50);
    mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->e_animations[j], x, y);
    j++;
    if (j == 8)
        j = 0;
}

void enemy_step_move(v_player *player)
{
    if (player->x > player->enemy_x
        && player->map[player->enemy_y][player->enemy_x + 1] != '1'
        && player->map[player->enemy_y][player->enemy_x + 1] != 'E')
        right_left_movement(player, 1);
    else if (player->x < player->enemy_x
        && player->map[player->enemy_y][player->enemy_x - 1] != '1'
        && player->map[player->enemy_y][player->enemy_x - 1] != 'E')
        right_left_movement(player, 0);
    else if (player->y < player->enemy_y
        && player->map[player->enemy_y - 1][player->enemy_x] != '1'
        && player->map[player->enemy_y - 1][player->enemy_x] != 'E')
        up_down_movement(player, 1);
    else if (player->y > player->enemy_y
        && player->map[player->enemy_y + 1][player->enemy_x] != '1' 
        && player->map[player->enemy_y + 1][player->enemy_x] != 'E')
        up_down_movement(player, 0);
}

void enemy_following_player(v_player *player)
{
    static int counter = 25;

    if (counter == 25)
        enemy_step_move(player);
    if (player->e_keycode == 0)
        enemy_animation(player, ((player->enemy_x * 50) + (counter * 2)), player->enemy_y * 50);
    else if (player->e_keycode == 2)
        enemy_animation(player, ((player->enemy_x * 50) - (counter * 2)), player->enemy_y * 50);
    else if (player->e_keycode == 1)
        enemy_animation(player, player->enemy_x * 50, ((player->enemy_y * 50) + (counter * 2)));
    else if (player->e_keycode == 13)
        enemy_animation(player, player->enemy_x * 50, ((player->enemy_y * 50) - (counter * 2)));
    counter--;
    mlx_do_sync(player->mlx_ptr);
    if (counter < 0)
    {    
        counter = 25;
        player->e_keycode = -1;
    }
    if (player->x == player->enemy_x && player->enemy_y == player->y)
    {
        enemy_animation(player, player->enemy_x * 50, player->enemy_y * 50);
        ft_printf("You Lost !!\n");
        exit(0);
    }
}




