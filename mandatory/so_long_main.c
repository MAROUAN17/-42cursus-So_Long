#include "sl_header.h"

int events_handler(int keycode, v_player *player)
{
    if (keycode == 53)
    {
        ft_close(player);
        exit(0);
    }
    else if (keycode == 2)
        move_player_right(player);
    else if (keycode == 0)
        move_player_left(player);
    else if (keycode == 1)
        move_player_up(player);
    else if (keycode == 13)
        move_player_down(player);
    update_player_position_and_render(player);
    walking_animation(player);
    return (0);
}

void rend_assets(v_player *player)
{
    int     x;
    int     y;

    x = 0;
    y = 0;
    while (y < player->map_height)
    {
        x = 0;
        while (x < player->map_width)
        {
            mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->background, x * player->img_width, y * player->img_height);
            if (player->map[y][x] == '1')
                mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->ground, x * player->img_width, y * player->img_height);
            else if (player->map[y][x] == 'C')
                mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->collectible, x * player->img_width, y * player->img_height);
            else if (player->map[y][x] == 'E')
                mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->exit, x * player->img_width, y * player->img_height);
            else if (player->map[y][x] == 'P')
                mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->player, x * player->img_width, y * player->img_height);
            x++;
        }
        y++;
    }
}

void    intialise_player(v_player *player, char *path)
{
    int i;

    i = 0;
    player->background = NULL;
    player->ground = NULL;
    player->collectible = NULL;
    player->exit = NULL;
    player->player = NULL;
    player->map_height = 0;
    player->map_width = 0;
    player->c_collectibles = 0;
    player->moves = 0;
    player->x = 0;
    player->y = 0;
    player->img_height = 50;
    player->img_width = 50;
    while (i < 8)
    {
        player->animations[i] = NULL;
        i++;
    }
    count_lines_rows(player, &player->map_height, &player->map_width);
    player->mlx_win = mlx_new_window(player->mlx_ptr, player->map_width * player->img_width, player->map_height * player->img_height, "So_Long");
    if (!player->mlx_win)
    {
        ft_close(player);
        exit(1);
    }
    player->map = reading_map(player, path);
    player->total_collectibles = count_a_tile(player, 'C');
    find_player_position(player, &player->x, &player->y);
    if (!parsing_map(player))
    {
        initialising_images(player);
        rend_assets(player);
    }
    else
    {
        ft_printf("Error\n");
        ft_printf("Non Valid Map!!\n");
        ft_close(player);
        exit(1);
    }
}

void a()
{
    system("leaks so_long");
}

int main(int ac, char **av)
{
    v_player    player;

    atexit(a);
    if (ac == 2)
    {
        player.mlx_ptr = mlx_init();
        if (!player.mlx_ptr)
            exit(1);
        player.map_path = av[1];
        intialise_player(&player, player.map_path);
        mlx_hook(player.mlx_win, 2, 1L<<0, events_handler, &player);
        mlx_loop(player.mlx_ptr);
    }
    else
    {
        ft_printf("Parameteres Error!!\n");
        exit(1);
    }
    return (0);
}
