#include "sl_header_bonus.h"

int rendering_new_frames(v_enemy *enemy)
{
    enemy_get_animation_images(enemy);
    // enemy_following_player(enemy);
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
        move_player_up(player);
    else if (keycode == 13)
        move_player_down(player);
    update_player_position_and_render(player);
    get_animation_images(player);
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
            rendering_background(mlx, mlx_win, x * 50, y * 50);
            if (map[y][x] == '1')
                rendering_ground(mlx, mlx_win, x * 50, y * 50);
            else if (map[y][x] == 'C')
                rendering_collectible(mlx, mlx_win, x * 50, y * 50);
            else if (map[y][x] == 'E')
                rendering_exit(mlx, mlx_win, x * 50, y * 50);
            else if (map[y][x] == 'P')
                rendering_player(mlx, mlx_win, x * 50, y * 50);
            else if (map[y][x] == 'M')
                rendering_enemy(mlx, mlx_win, x * 50, y * 50);
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
    v_enemy     enemy;

    player.collected_collectibles = 0;
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
        // ft_printf("width -> %d\n", width);
	    // ft_printf("height -> %d\n", height);
        player.map = map;
        enemy.map = map;
        player.mlx_ptr = mlx;
        enemy.mlx_ptr = mlx;
        player.map_height = height;
        player.map_width = width;
        enemy.map_height = height;
        enemy.map_width = width;
        find_player_position(player.map, player.map_width, player.map_height, &player.x, &player.y);
        find_enemy_position(enemy.map, enemy.map_width, enemy.map_height, &enemy.x, &enemy.y);
        enemy.player_x = player.x;
        enemy.player_y = player.y;
        player.enemy_x = enemy.x;
        player.enemy_y = enemy.y;
        mlx_win = mlx_new_window(mlx, width * 50, height * 50, "So_Long");
        player.mlx_win = mlx_win;
        enemy.mlx_win = mlx_win;
        if (!mlx_win)
        {
            free(mlx);
            return (1);
        }
        win_vars.win = mlx_win;
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
        mlx_hook(win_vars.win, 2, 1L<<0, events_handler, &player);
        mlx_loop_hook(mlx, rendering_new_frames, &enemy);
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