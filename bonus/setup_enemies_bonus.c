#include "sl_header_bonus.h"

void initialize_enemies(v_player *player)
{
    int         i;
    v_player    enemy;

    i = 0;
    enemy.enemy_x = 0;
    enemy.enemy_y = 0;
    player->c_enemies = count_enemies(player->map, player->map_width, player->map_height);
    player->enemies = malloc(sizeof(v_player) * player->c_enemies);
    while (i < player->c_enemies - 1)
    {
        enemy.keycode = -1;
        enemy.e_keycode = -1;
        enemy.mlx_ptr = player->mlx_ptr;
        enemy.mlx_win = player->mlx_win;
        enemy.map = player->map;
        enemy.map_height = player->map_height;
        enemy.map_width = player->map_width;
        enemy.x = player->x;
        enemy.y = player->y;
        find_enemy_position(player, &enemy.enemy_x, &enemy.enemy_y, 0);
        player->enemies[i] = enemy;
        i++;
    }
}

void n_enemy_get_animation_images(v_player *player, int i)
{
    int         img_width;
    int         img_height;

    player->enemies[i].animations[0] = mlx_xpm_file_to_image(player->enemies[i].mlx_ptr, "../assets/enemy/enemy 1.xpm", &img_width, &img_height);
    player->enemies[i].animations[1] = mlx_xpm_file_to_image(player->enemies[i].mlx_ptr, "../assets/enemy/enemy 2.xpm", &img_width, &img_height);
    player->enemies[i].animations[2] = mlx_xpm_file_to_image(player->enemies[i].mlx_ptr, "../assets/enemy/enemy 3.xpm", &img_width, &img_height);
    player->enemies[i].animations[3] = mlx_xpm_file_to_image(player->enemies[i].mlx_ptr, "../assets/enemy/enemy 4.xpm", &img_width, &img_height);
    player->enemies[i].animations[4] = mlx_xpm_file_to_image(player->enemies[i].mlx_ptr, "../assets/enemy/enemy 5.xpm", &img_width, &img_height);
    player->enemies[i].animations[5] = mlx_xpm_file_to_image(player->enemies[i].mlx_ptr, "../assets/enemy/enemy 6.xpm", &img_width, &img_height);
    player->enemies[i].animations[6] = mlx_xpm_file_to_image(player->enemies[i].mlx_ptr, "../assets/enemy/enemy 7.xpm", &img_width, &img_height);
    player->enemies[i].animations[7] = mlx_xpm_file_to_image(player->enemies[i].mlx_ptr, "../assets/enemy/enemy 8.xpm", &img_width, &img_height);
}

void enemies_animation(v_player *player, int x, int y, int i)
{
    static int  j;

    rendering_background(player->enemies[i].mlx_ptr, player->enemies[i].mlx_win, player->enemies[i].enemy_x * 50, player->enemies[i].enemy_y * 50);
    if (player->enemies[i].keycode == 2)
        rendering_background(player->enemies[i].mlx_ptr, player->enemies[i].mlx_win, (player->enemies[i].enemy_x - 1) * 50, player->enemies[i].enemy_y * 50);
    else if (player->enemies[i].keycode == 0)
        rendering_background(player->enemies[i].mlx_ptr, player->enemies[i].mlx_win, (player->enemies[i].enemy_x + 1) * 50, player->enemies[i].enemy_y * 50);
    else if (player->enemies[i].keycode == 1)
        rendering_background(player->enemies[i].mlx_ptr, player->enemies[i].mlx_win, player->enemies[i].enemy_x * 50, (player->enemies[i].enemy_y + 1) * 50);
    else if (player->enemies[i].keycode == 13)
        rendering_background(player->enemies[i].mlx_ptr, player->enemies[i].mlx_win, player->enemies[i].enemy_x * 50, (player->enemies[i].enemy_y - 1) * 50);
    mlx_put_image_to_window(player->enemies[i].mlx_ptr, player->enemies[i].mlx_win, player->enemies[i].animations[j], x, y);
    j++;
    if (j == 8)
        j = 0;
}

void making_enemies(v_player *player)
{
    static int i;
    static int is_up;
    static int is_down;
    static int is_right;
    static int is_left;
    static int direction;
    static int counter = 25;

    if (i < player->c_enemies - 1)
    {
        if (counter == 25)
            direction = rand() % 4;
        n_enemy_get_animation_images(player, i);
        if (direction == 0 && counter == 25 && (player->map[player->enemies[i].enemy_y][player->enemies[i].enemy_x - 1]) != '1' && (player->map[player->enemies[i].enemy_y][player->enemies[i].enemy_x - 1]) != 'E')
        {
            player->enemies[i].enemy_x--;
            player->enemies[i].keycode = 0;
            is_left = 1;
        }
        else if (direction == 1 && counter == 25 && (player->map[player->enemies[i].enemy_y - 1][player->enemies[i].enemy_x]) != '1' && (player->map[player->enemies[i].enemy_y - 1][player->enemies[i].enemy_x]) != 'E')
        {
            player->enemies[i].enemy_y--;
            player->enemies[i].keycode = 1;
            is_up = 1;
        }
        else if (direction == 2 && counter == 25 && (player->map[player->enemies[i].enemy_y][player->enemies[i].enemy_x + 1]) != '1' && (player->map[player->enemies[i].enemy_y][player->enemies[i].enemy_x + 1]) != 'E')
        {
            player->enemies[i].enemy_x++;
            player->enemies[i].keycode = 2;
            is_right = 1;
        }
        else if (direction == 3 && counter == 25 && (player->map[player->enemies[i].enemy_y + 1][player->enemies[i].enemy_x]) != '1' && (player->map[player->enemies[i].enemy_y + 1][player->enemies[i].enemy_x]) != 'E')
        {
            player->enemies[i].enemy_y++;
            player->enemies[i].keycode = 13;
            is_down = 1;
        }
        if (is_left && (player->map[player->enemies[i].enemy_y][player->enemies[i].enemy_x - 1] != '1') && (player->map[player->enemies[i].enemy_y][player->enemies[i].enemy_x - 1] != 'E'))
            enemies_animation(player, ((player->enemies[i].enemy_x * 50) + (counter * 2)), (player->enemies[i].enemy_y * 50), i);
        else if (is_right && (player->map[player->enemies[i].enemy_y][player->enemies[i].enemy_x + 1] != '1') && (player->map[player->enemies[i].enemy_y][player->enemies[i].enemy_x + 1] != 'E'))
            enemies_animation(player, ((player->enemies[i].enemy_x * 50) - (counter * 2)), (player->enemies[i].enemy_y * 50), i);
        else if (is_up && (player->map[player->enemies[i].enemy_y - 1][player->enemies[i].enemy_x] != '1') && (player->map[player->enemies[i].enemy_y - 1][player->enemies[i].enemy_x] != 'E'))
            enemies_animation(player, (player->enemies[i].enemy_x * 50), ((player->enemies[i].enemy_y * 50) + (counter * 2)), i);
        else if (is_down && (player->map[player->enemies[i].enemy_y + 1][player->enemies[i].enemy_x] != '1') && (player->map[player->enemies[i].enemy_y + 1][player->enemies[i].enemy_x] != 'E'))
            enemies_animation(player, (player->enemies[i].enemy_x * 50), ((player->enemies[i].enemy_y * 50) - (counter * 2)), i);
        else
            enemies_animation(player, (player->enemies[i].enemy_x * 50), (player->enemies[i].enemy_y * 50), i);
        counter--;
        if (counter < 0 || (!is_left && !is_right && !is_up && !is_down))
        {
            i++;
            counter = 25;
            is_down = 0;
            is_up = 0;
            is_right = 0;
            is_left = 0;
        }
        if (player->x == player->enemies[i].enemy_x && player->y == player->enemies[i].enemy_y)
        {
            enemy_animation(player, (player->enemies[i].enemy_x * 50), (player->enemies[i].enemy_y * 50));
            ft_printf("You Lost !!\n");
            exit(0);
        }
    }
    if (i == player->c_enemies - 1)
        i = 0;
}
