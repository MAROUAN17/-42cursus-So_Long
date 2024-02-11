#include "sl_header_bonus.h"

void move_player_right(v_player *player)
{
    player->keycode = 2;
    if (player->map[player->y][player->x + 1] != '1')
    {
        if (player->map[player->y][player->x + 1] == 'E')
        {
            if (player->collected_collectibles == player->total_collectibles)
            {
                mlx_destroy_window(player->mlx_ptr, player->mlx_win);
                exit(0);
            }
        }
        else
        {
            player->moves++;
            if (player->map[player->y][player->x + 1] == 'C')
            {
                player->map[player->y][player->x + 1] = '0';   
                player->collected_collectibles++;
            }
            player->x += 1;
        }
    }
}

void move_player_left(v_player *player)
{
    player->keycode = 0;
    if (player->map[player->y][player->x - 1] != '1')
    {
        if (player->map[player->y][player->x - 1] == 'E')
        {
            if (player->collected_collectibles == player->total_collectibles)
            {
                mlx_destroy_window(player->mlx_ptr, player->mlx_win);
                exit(0);
            }
        }
        else
        {
            player->moves++;
            if (player->map[player->y][player->x - 1] == 'C')
            {
                player->map[player->y][player->x - 1] = '0'; 
                player->collected_collectibles++;
            }
            player->x -= 1;
        }
    }
}

void move_player_up(v_player *player)
{
    player->keycode = 1;
    if (player->map[player->y + 1][player->x] != '1')
    {
        if (player->map[player->y + 1][player->x] == 'E')
        {
            if (player->collected_collectibles == player->total_collectibles)
            {
                mlx_destroy_window(player->mlx_ptr, player->mlx_win);
                exit(0);
            }
        }
        else
        {
            player->moves++;
            if (player->map[player->y + 1][player->x] == 'C')
            {
                player->map[player->y + 1][player->x] = '0';    
                player->collected_collectibles++;
            }
            player->y += 1;
        }
    }
}

void move_player_down(v_player *player)
{
    player->keycode = 13;
    if (player->map[player->y - 1][player->x] != '1')
    {
        if (player->map[player->y - 1][player->x] == 'E')
        {
            if (player->collected_collectibles == player->total_collectibles)
            {
                mlx_destroy_window(player->mlx_ptr, player->mlx_win);
                exit(0);
            }
        }
        else
        {
            player->moves++;
            if (player->map[player->y - 1][player->x] == 'C')
            {
                player->map[player->y - 1][player->x] = '0';
                player->collected_collectibles++;
            }
            player->y -= 1;
        }
    }
}

void get_animation_images(v_player *player)
{
    int         img_width;
    int         img_height;

    player->animations[0] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/walk/Walk 1.xpm", &img_width, &img_height);
    player->animations[1] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/walk/Walk 2.xpm", &img_width, &img_height);
    player->animations[2] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/walk/Walk 3.xpm", &img_width, &img_height);
    player->animations[3] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/walk/Walk 4.xpm", &img_width, &img_height);
    player->animations[4] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/walk/Walk 5.xpm", &img_width, &img_height);
    player->animations[5] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/walk/Walk 6.xpm", &img_width, &img_height);
    player->animations[6] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/walk/Walk 7.xpm", &img_width, &img_height);
    player->animations[7] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/walk/Walk 8.xpm", &img_width, &img_height);
    walking_animation(player);
}

void    walking_animation(v_player *player)
{
    static int  j;
    int         i;

    i = 0;
    if (j < 8)
    {
        rendering_background(player->mlx_ptr, player->mlx_win, player->x * 50 , player->y * 50);
        mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->animations[j], player->x * 50, player->y * 50);
        j++;
        while (i < 5000000)
            i++;
        i = 0;
    }
    if (j == 8)
        j = 0;
}
