#include "sl_header_bonus.h"

void count_lines_rows(v_player *player, int *p_lines, int *p_rows)
{
    int     fd;
    char    *line;
    int     index;

    fd = open(player->map_path, O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        index = 0;
        while (*(line + index) && (*p_lines) == 0)
        {
            index++;
            (*p_rows)++;
        }
        (*p_lines)++;
        free(line);
    }
    close(fd);
}

int first_line_and_last(char **map, int y, int width)
{
    int x;
    int check;

    x = 0;
    check = 0;
    while (x <= width && map[y][x] == '1')    
        x++;
    if (map[y][x] && map[y][x] != '\n' && x <= width && map[y][x] != '1')
        check = 1;
    return (check);
}

int other_lines(char **map, int y, int width)
{
    int check;
    int x;

    x = 0;
    check = 0;
    if(map[y][x] != '1' || map[y][width - 1] != '1')
        check = 1;
    return (check);
}

int check_walls(char **map, int height, int width)
{
    int check;
    int x;
    int y;

    check = 0;
    x = 0;
    y = 0;
    while (y < height)
    {
        x = 0;
        if (y == 0 || y == height - 1)
            first_line_and_last(map, y, width);
        else
            other_lines(map, y, width);
        y++;
    }
    return (check);
}

int check_rectangular_map(char **map, int height, int width)
{
    int check;
    int counter;
    int x;
    int y;

    check = 0;
    counter = 0;
    x = 0;
    y = 0;
    while (y < height)
    {
        x = 0;
        counter = 0;
        while(map[y][counter] && map[y][counter] != '\n')
            counter++;
        if (counter != width)
        {
            check = 1;
            break;
        }
        y++;
    }
    return (check);
}

int parsing_map(v_player *player)
{
    int     check;
    int     counter;
    int     x;
    int     y;

    counter = 0;
    check = 0;
    x = 0;
    y = 0;
    if(player->map_height > player->map_width || player->map_height == player->map_width || !player->map[0][0]
        || check_rectangular_map(player->map, player->map_height, player->map_width) || check_walls(player->map, player->map_height, player->map_width)
        || check_collectible(player->map, player->map_width, player->map_height) || check_exits(player->map, player->map_width, player->map_height) 
        || check_start(player->map, player->map_width, player->map_height) || check_reachable_collectibles(player)
        || check_reachable_exits(player))
    {
        // ft_printf("check collectible -> %d\n", check_collectible(player->map, player->map_width, player->map_height));
        // ft_printf("check rectangular -> %d\n", check_rectangular_map(player->map, player->map_height, player->map_width));
        // ft_printf("check_reachable_collectible -> %d\n", check_reachable_collectibles(player));
        // ft_printf("check_reachable_exits -> %d\n", check_reachable_exits(player));
        check = 1;
    }
    return (check);
}
