#include "sl_header.h"

void move_player_right(v_player *player)
{
    player->keycode = 2;
    if (player->map[player->y][player->x + 1] != '1')
    {
        if (player->map[player->y][player->x + 1] == 'E')
        {
            if (player->c_collectibles == player->total_collectibles)
            {
                ft_close(player);
                exit(0);
            }
        }
        else
        {
            player->moves++;
            ft_printf("moves -> %d\n", player->moves);
            if (player->map[player->y][player->x + 1] == 'C')
            {
                player->map[player->y][player->x + 1] = '0';   
                player->c_collectibles++;
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
            if (player->c_collectibles == player->total_collectibles)
            {
                ft_close(player);
                exit(0);
            }
        }
        else
        {
            player->moves++;
            ft_printf("moves -> %d\n", player->moves);
            if (player->map[player->y][player->x - 1] == 'C')
            {
                player->map[player->y][player->x - 1] = '0'; 
                player->c_collectibles++;
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
            if (player->c_collectibles == player->total_collectibles)
            {
                ft_close(player);
                exit(0);
            }
        }
        else
        {
            player->moves++;
            ft_printf("moves -> %d\n", player->moves);
            if (player->map[player->y + 1][player->x] == 'C')
            {
                player->map[player->y + 1][player->x] = '0';    
                player->c_collectibles++;
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
            if (player->c_collectibles == player->total_collectibles)
            {
                ft_close(player);
                exit(0);
            }
        }
        else
        {
            player->moves++;
            ft_printf("moves -> %d\n", player->moves);
            if (player->map[player->y - 1][player->x] == 'C')
            {
                player->map[player->y - 1][player->x] = '0';
                player->c_collectibles++;
            }
            player->y -= 1;
        }
    }
}

void get_animation_images(v_player *player)
{
    player->animations[0] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/walk/Walk 1.xpm", &player->img_width, &player->img_height);
    player->animations[1] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/walk/Walk 2.xpm", &player->img_width, &player->img_height);
    player->animations[2] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/walk/Walk 3.xpm", &player->img_width, &player->img_height);
    player->animations[3] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/walk/Walk 4.xpm", &player->img_width, &player->img_height);
    player->animations[4] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/walk/Walk 5.xpm", &player->img_width, &player->img_height);
    player->animations[5] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/walk/Walk 6.xpm", &player->img_width, &player->img_height);
    player->animations[6] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/walk/Walk 7.xpm", &player->img_width, &player->img_height);
    player->animations[7] = mlx_xpm_file_to_image(player->mlx_ptr, "../assets/walk/Walk 8.xpm", &player->img_width, &player->img_height);
}

void    walking_animation(v_player *player)
{
    static int  j;
    static int  i;

    if (j < 8)
    {
        mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->background, player->x * 50 , player->y * 50);
        mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->animations[j], player->x * 50, player->y * 50);
        j++;
        while (i < 5000000)
            i++;
        i = 0;
    }
    if (j == 8)
        j = 0;
}
