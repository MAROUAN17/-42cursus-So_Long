#include "sl_header.h"

void move_player_right(v_player *player)
{
    player->keycode = 2;
    if (player->map[player->y][player->x + 1] != '1' && player->x < player->map_width 
        && player->y < player->map_height)
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
            ft_printf("moves -> %d\n", player->moves);
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
    if (player->map[player->y][player->x - 1] != '1' && player->x < player->map_width 
            && player->y < player->map_height)
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
            ft_printf("moves -> %d\n", player->moves);
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
    if (player->map[player->y + 1][player->x] != '1' && player->x < player->map_width 
        && player->y < player->map_height)
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
            ft_printf("moves -> %d\n", player->moves);
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
    if (player->map[player->y - 1][player->x] != '1' && player->x < player->map_width 
        && player->y < player->map_height)
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
            ft_printf("moves -> %d\n", player->moves);
            if (player->map[player->y - 1][player->x] == 'C')
            {
                player->map[player->y - 1][player->x] = '0';
                player->collected_collectibles++;
            }
            player->y -= 1;
        }
    }
}

void walking_player(v_player *player, void *mlx_ptr, void *mlx_win, int x, int y)
{
    t_data      img;
    void        *images[8];
    int         img_width;
    int         img_height;
    static int  j;

    images[0] = mlx_xpm_file_to_image(mlx_ptr, "./assets/walk/Walk 1.xpm", &img_width, &img_height);
    images[1] = mlx_xpm_file_to_image(mlx_ptr, "./assets/walk/Walk 2.xpm", &img_width, &img_height);
    images[2] = mlx_xpm_file_to_image(mlx_ptr, "./assets/walk/Walk 3.xpm", &img_width, &img_height);
    images[3] = mlx_xpm_file_to_image(mlx_ptr, "./assets/walk/Walk 4.xpm", &img_width, &img_height);
    images[4] = mlx_xpm_file_to_image(mlx_ptr, "./assets/walk/Walk 5.xpm", &img_width, &img_height);
    images[5] = mlx_xpm_file_to_image(mlx_ptr, "./assets/walk/Walk 6.xpm", &img_width, &img_height);
    images[6] = mlx_xpm_file_to_image(mlx_ptr, "./assets/walk/Walk 7.xpm", &img_width, &img_height);
    images[7] = mlx_xpm_file_to_image(mlx_ptr, "./assets/walk/Walk 8.xpm", &img_width, &img_height);
    while (j < 8)
    {
        ft_printf("j -> %d\n", j);
        img.img = images[j];
        j++;
        if (player->keycode == 2)
        {
            rendering_background(player->mlx_ptr, player->mlx_win, player->x - 1, player->y);
            mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, (x - 1) * 50, y * 50);
        }
        else if (player->keycode == 0)
        {
            rendering_background(player->mlx_ptr, player->mlx_win, player->x + 1, player->y);
            mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, (x + 1) * 50, y * 50);
        }
        else if (player->keycode == 1)
        {
            rendering_background(player->mlx_ptr, player->mlx_win, player->x, player->y - 1);
            mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, x * 50, (y - 1) * 50);
        }
        else if (player->keycode == 13)
        {
            rendering_background(player->mlx_ptr, player->mlx_win, player->x , player->y + 1);    
            mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, x * 50, (y + 1) * 50);
        }
    }
    mlx_clear_window(mlx_ptr, mlx_win);
    if (player->keycode == 2)
        player->map[player->y][player->x - 1] = '0';
    else if (player->keycode == 0)
        player->map[player->y][player->x + 1] = '0';
    else if (player->keycode == 1)
        player->map[player->y - 1][player->x] = '0';
    else if (player->keycode == 13)
        player->map[player->y + 1][player->x] = '0';
    player->map[player->y][player->x] = 'P';
    j = 0;
}
