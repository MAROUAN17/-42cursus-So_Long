#include "sl_header_bonus.h"

int rendering_new_frames(v_player *player)
{
    enemy_following_player(player);
    usleep(20000);
    rendering_collectibles(player, player->map, player->map_width, player->map_height);
    making_enemies(player);
    return (0);
}

int events_handler(int keycode, v_player *player)
{
    if (keycode == 53)
    {
        mlx_destroy_window(player->mlx_ptr, player->mlx_win);
        exit(0);
    }
    else if (keycode == 2)
        move_player_right(player);
    else if (keycode == 0)
        move_player_left(player);
    else if (keycode == 1)
        move_player_down(player);
    else if (keycode == 13)
        move_player_up(player);
    update_player_position_and_render(player);
    get_animation_images(player);
    display_moves(player);
    return (0);
}

void rend_assets(v_player *player, char **map, int width, int height)
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
            rendering_background(player->mlx_ptr, player->mlx_win, x * 50, y * 50);
            if (map[y][x] == '1')
                rendering_ground(player, x * 50, y * 50);
            else if (map[y][x] == 'C')
                rendering_collectible(player->mlx_ptr, player->mlx_win, x * 50, y * 50);
            else if (map[y][x] == 'E')
                rendering_exit(player, x * 50, y * 50);
            else if (map[y][x] == 'P')
                rendering_player(player, x * 50, y * 50);
            else if (map[y][x] == 'M')
                rendering_enemy(player, x * 50, y * 50);
            x++;
        }
        y++;
    }
}

int main(int ac, char **av)
{
    void        *mlx;
    void        *mlx_win;
    char        **map = NULL;
    int         width;
    int         height;
    t_vars      win_vars;
    v_player    player;
    v_player    enemy;

    player.c_collectibles = 0;
    player.moves = 0;
    height = 0;
    width = 0;
    player.x = 0;
    player.y = 0;
    enemy.x = 0;
    enemy.y = 0;
    player.keycode = -1;
    if (ac >= 2)
    {
        mlx = mlx_init();
        if(!mlx)
            return (1);
        win_vars.mlx = mlx;
        map = reading_map(av[1], &width, &height);
        player.map = map;
        player.mlx_ptr = mlx;
        player.map_height = height;
        player.map_width = width;
        enemy.map = map;
        enemy.mlx_ptr = mlx;
        enemy.map_height = height;
        enemy.map_width = width;
        find_player_position(&player, &player.x, &player.y);
        find_enemy_position(&player, &player.enemy_x, &player.enemy_y, 1);
        mlx_win = mlx_new_window(mlx, width * 50, height * 50, "So_Long");
        player.mlx_win = mlx_win;
        enemy.mlx_win = mlx_win;
        if (!mlx_win)
        {
            free(mlx);
            return (1);
        }
        win_vars.win = mlx_win;
        initialize_enemies(&player);
        if (!parsing_map(av[1], map, height, width))
        {
            player.total_collectibles = count_a_tile(player.map, player.map_width, player.map_height, 'C');
            rend_assets(&player, map, width, height);
        }
        else
        {
            ft_printf("Error\n");
            ft_printf("Non Valid Map!!\n");
            exit(1);
        }
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
