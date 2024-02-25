#include "sl_header_bonus.h"

void count_lines_rows(char *path, int *p_lines, int *p_rows)
{
    int     fd;
    char    *line;
    int     index;

    fd = open(path, O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        index = 0;
        *p_rows = 0;
        while (*(line + index))
        {
            index++;
            (*p_rows)++;
        }
        line = get_next_line(fd);
        (*p_lines)++;
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

int parsing_map(char *path, char **map, int height, int width)
{
    int     check;
    int     counter;
    int     x;
    int     y;

    counter = 0;
    check = 0;
    x = 0;
    y = 0;
    if(height > width || height == width || !map[0][0] || check_rectangular_map(map, height, width)
        || check_walls(map, height, width) || check_collectible(map, width, height) 
        || check_exits(map, width, height) || check_start(map, width, height) 
        || check_reachable_collectibles(path, map, width, height) || check_reachable_exits(path, map, width, height))
    {
        ft_printf("check collectible -> %d\n", check_collectible(map, width, height));
        ft_printf("check rectangular -> %d\n", check_rectangular_map(map, height, width));
        ft_printf("check_reachable_collectible -> %d\n", check_reachable_collectibles(path, map, width, height));
        ft_printf("check_reachable_exits -> %d\n", check_reachable_exits(path, map, width, height));
        check = 1;
    }
    return (check);
}
