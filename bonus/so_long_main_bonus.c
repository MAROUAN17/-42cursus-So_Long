#include "sl_header_bonus.h"

int infinite_function(v_player *player)
{
    check_player_die(player);
    enemy_following_player(player);
    rendering_collectibles(player);
    making_enemies(player);
    return (0);
}

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
        move_player_down(player);
    else if (keycode == 13)
        move_player_up(player);
    update_player_position_and_render(player);
    walking_animation(player);
    display_moves(player);
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
            mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->background_img, x * player->img_height, y * player->img_width);
            if (player->map[y][x] == '1')
                mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->ground_img, x * player->img_height, y * player->img_width);
            else if (player->map[y][x] == 'C')
                mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->collectible_img, x * player->img_height, y * player->img_width);
            else if (player->map[y][x] == 'E')
                mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->exit_img, x * player->img_height, y * player->img_width);
            else if (player->map[y][x] == 'P')
                mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->player_img, x * player->img_height, y * player->img_width);
            else if (player->map[y][x] == 'M')
                mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->enemy_img, x * player->img_height, y * player->img_width);
            x++;
        }
        y++;
    }
}

void    initialize_player_struct(v_player *player)
{
    initialize_player_struct_variables(player);
    count_lines_rows(player, &player->map_height, &player->map_width);
    player->mlx_win = mlx_new_window(player->mlx_ptr, player->map_width * player->img_width, player->map_height * player->img_height, "So_Long");
    if (!player->mlx_win)
        exit(1);
    player->map = reading_map(player);
    player->total_collectibles = count_a_tile(player, 'C');
    find_player_position(player, &player->x, &player->y);
    find_enemy_position(player, &player->enemy_x, &player->enemy_y);
    if (!parsing_map(player))
    {
        initialize_images(player);
        initialize_enemies(player);
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

int main(int ac, char **av)
{
    v_player    player;

    if (ac >= 2)
    {
        player.mlx_ptr = mlx_init();
        if (!player.mlx_ptr)
            exit(1);
        player.map_path = av[1];
        initialize_player_struct(&player);
        mlx_hook(player.mlx_win, 2, 1L<<0, events_handler, &player);
        mlx_loop_hook(player.mlx_ptr, infinite_function, &player);
        mlx_loop(player.mlx_ptr);
    }
    else
    {
        ft_printf("Error\n");
        ft_printf("Invalid map !!\n");
        exit(1);
    }
    return (0);
}
