#include "sl_header.h"

int rendering_new_frames(void *ptr)
{
    v_player *player = (v_player *)ptr;
    if (player->keycode == 1 || player->keycode == 13 || player->keycode == 2)
    {
        walking_player(player, player->mlx_ptr, player->mlx_win, player->x, player->y);
        rend_assets(player->mlx_ptr, player->mlx_win, player->map, player->map_width, player->map_height);
        player->keycode = -1;
    }
    else if(player->keycode == 0)
    {
        walking_player(player, player->mlx_ptr, player->mlx_win, player->x, player->y);
        rend_assets(player->mlx_ptr, player->mlx_win, player->map, player->map_width, player->map_height);
        player->keycode = -1;
    }
    return (0);
}

int events_handler(int keycode, v_player *player)
{
    if (keycode == 53)
    {
        mlx_destroy_window(player->mlx_ptr, player->mlx_win);
        exit(0);
    }
    if (keycode == 2)
        move_player_right(player);
    if (keycode == 0)
        move_player_left(player);
    if (keycode == 1)
        move_player_up(player);
    if (keycode == 13)
        move_player_down(player);
    return (0);
}

void rend_assets(void *mlx, void *mlx_win, char **map, int width, int height)
{
    int     x;
    int     y;

    x = 0;
    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            rendering_background(mlx, mlx_win, x, y);
            if (map[y][x] == '1')
                rendering_ground(mlx, mlx_win, x, y);
            else if (map[y][x] == 'C')
                rendering_collectible(mlx, mlx_win, x, y);
            else if (map[y][x] == 'E')
                rendering_exit(mlx, mlx_win, x, y);
            else if (map[y][x] == 'P')
                rendering_player(mlx, mlx_win, x, y);
            x++;
        }
        y++;
    }
}

int main(int ac, char **av)
{
    void    *mlx;
    void    *mlx_win;
    char    **map = NULL;
    int     width;
    int     height;
    t_vars      win_vars;
    v_player    player;


    player.collected_collectibles = 0;
    player.moves = 0;
    height = 0;
    width = 0;
    player.x = 0;
    player.y = 0;
    player.keycode = -1;
    if (ac >= 2)
    {
        /*-----------------initialize the library-----------------*/
        mlx = mlx_init();
        if(!mlx)
            return (1);
        /*-----------------create a window-----------------*/
        win_vars.mlx = mlx;
        map = reading_map(av[1], &width, &height);
        player.map = map;
        player.mlx_ptr = mlx;
        player.map_height = height;
        player.map_width = width;
        find_player_position(player.map, player.map_width, player.map_height, &player.x, &player.y);
        mlx_win = mlx_new_window(mlx, width * 50, height * 50, "So_Long");
        player.mlx_win = mlx_win;
        if (!mlx_win)
        {
            free(mlx);
            return (1);
        }
        win_vars.win = mlx_win;
        /*-----------------create an image-----------------*/
        // img_vars.img = mlx_new_image(mlx, 1920, 1080);
        // img_vars.addr = mlx_get_data_addr(img_vars.img, &img_vars.bits_per_pixel, &img_vars.line_length, &img_vars.endian);
        /*-----------------put image to a windo && convert xpm to image-----------------*/
        // mlx_put_image_to_window(mlx, mlx_win, img_vars.img, 0, 0);
        // img_vars.img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
        // img_vars.addr = mlx_get_data_addr(img_vars.img, &img_vars.bits_per_pixel, &img_vars.line_length, &img_vars.endian);
        // mlx_put_image_to_window(mlx, mlx_win, img_vars.img, 0, 0);
        /*---------------------Reste---------------------------*/
        if (!parsing_map(av[1], map, height, width))
        {
            player.total_collectibles = count_a_tile(player.map, player.map_width, player.map_height, 'C');
            rend_assets(win_vars.mlx, win_vars.win, map, width, height);
        }
        else
        {
            ft_printf("Error\n");
            ft_printf("Non Valid Map!!\n");
            exit(1);
        }
        /*-----------------create a hook to handle an event-----------------*/
        mlx_hook(win_vars.win, 2, 1L<<0, events_handler, &player);
        mlx_loop_hook(mlx, rendering_new_frames, &player);
        mlx_loop(mlx);
        free(mlx);
    }
    else
    {
        ft_printf("Error\n");
        ft_printf("Invalid map !!\n");
        exit(1);
    }
    return (0);
}